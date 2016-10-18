%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0"
%defines
%define parser_class_name { SmaliParser }

%define api.token.constructor
%define api.value.type variant
%define parse.assert
%define api.namespace { Analysis }
%code requires
{
//===- Parser.yy - ART-Parser ---------------------------------*- bison -*-===//
//
//                     ANDROID REVERSE TOOLKIT
//
// This file is distributed under the GNU GENERAL PUBLIC LICENSE
// V3 License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// The file defines a Parser for smali language. Please use
// bison -o SmaliParser.cpp SmaliParser.yy
// to generate parser source file
// or
// bison -v -o SmaliParser.cpp SmaliParser.yy
// to debug.
//===----------------------------------------------------------------------===//
    #include <iostream>
    #include <string>
    #include <vector>
    #include <stdint.h>
    #include "Ops/Ops.h"

    namespace Analysis {
        class SmaliLexer;
        class Interpreter;
    }
}

%code top
{
    #include <iostream>
    #include "SmaliParser.hpp"
    #include "location.hh"
    //#include "Interpreter.h"
    #include "SmaliLexer.h"
    #include "utils/Defs.h"

    static Analysis::SmaliParser::symbol_type yylex(Analysis::SmaliLexer &lexer
                                    , Analysis::Interpreter &driver ) {
        return lexer.get_next_token();
    }
    using namespace std;
    using namespace Analysis;
}

%lex-param { Analysis::SmaliLexer &lexer }
%lex-param { Analysis::Interpreter &driver }

%parse-param { Analysis::SmaliLexer &lexer }
%parse-param { Analysis::Interpreter &driver }

%locations
%define parse.trace
%define parse.error verbose

%debug

%define api.token.prefix {TOKEN_}

%token END 0 "end of file";
%token EOL "end of line";
%token <std::string> ERROR "lex error"

%token KEYWORD_BEGIN "begin of keywords"

%token CLASS_DIRECTIVE ".class"
%token SUPER_DIRECTIVE ".super"
%token IMPLEMENTS_DIRECTIVE ".implements"
%token SOURCE_DIRECTIVE ".source"
%token FIELD_DIRECTIVE ".field"
%token END_FIELD_DIRECTIVE ".end field"
%token SUBANNOTATION_DIRECTIVE ".subannotation"
%token END_SUBANNOTATION_DIRECTIVE ".end subannotation"
%token ANNOTATION_DIRECTIVE ".annotation"
%token END_ANNOTATION_DIRECTIVE ".end annotation"
%token ENUM_DIRECTIVE ".enum"
%token METHOD_DIRECTIVE ".method"
%token END_METHOD_DIRECTIVE ".end method"
%token REGISTERS_DIRECTIVE ".registers"
%token LOCALS_DIRECTIVE ".locals"
%token ARRAY_DATA_DIRECTIVE ".array-data"
%token END_ARRAY_DATA_DIRECTIVE ".end array-data"
%token PACKED_SWITCH_DIRECTIVE ".packed-switch"
%token END_PACKED_SWITCH_DIRECTIVE ".end packed-switch"
%token SPARSE_SWITCH_DIRECTIVE ".sparse-switch"
%token END_SPARSE_SWITCH_DIRECTIVE ".end sparse-switch"
%token CATCH_DIRECTIVE ".catch"
%token CATCHALL_DIRECTIVE ".catchall"
%token LINE_DIRECTIVE ".line"
%token PARAMETER_DIRECTIVE ".param"
%token END_PARAMETER_DIRECTIVE ".end param"
%token LOCAL_DIRECTIVE ".local"
%token END_LOCAL_DIRECTIVE ".end local"
%token RESTART_LOCAL_DIRECTIVE ".restart local"
%token PROLOGUE_DIRECTIVE ".prologue"
%token EPILOGUE_DIRECTIVE ".epilogue"

%token KEYWORD_END "end of keywords"

%token NUMBER_BEGIN

%token <std::string> POSITIVE_INTEGER_LITERAL "Integer"
%token <std::string> NEGATIVE_INTEGER_LITERAL "- Integer"
%token <std::string> LONG_LITERAL "- Integer L"
%token <std::string> SHORT_LITERAL "- Integer S"
%token <std::string> BYTE_LITERAL "- Integer T"

%token <std::string> FLOAT_LITERAL_OR_ID "FloatOrID F"
%token <std::string> DOUBLE_LITERAL_OR_ID "FloatOrID D"
%token <std::string> FLOAT_LITERAL "Float F"
%token <std::string> DOUBLE_LITERAL "Float D"

%token <int>         BOOL_LITERAL "true|false"
%token               NULL_LITERAL "null"

%token NUMBER_END

%token <int> FLAG "flag"
%token <int> REGISTER "v(p)x"
%token <std::string> PARAM_LIST_OR_ID_PRIMITIVE_TYPE "ZBSCIJFDLIT"
%token <std::string> PRIMITIVE_TYPE "ZBSCIJFD"
%token <std::string> CLASS_DESCRIPTOR "Lxxx;"
%token <std::string> ARRAY_TYPE_PREFIX "[["
%token VOID_TYPE "V"
%token <std::string> SIMPLE_NAME "simple name"
%token <std::string> MEMBER_NAME "member name"

%token <std::string> STRING_LITERAL "string"
%token <std::string> CHAR_LITERAL "char"
%token <std::string> ANNOTATION_VISIBILITY "build runtime system"
%token <std::string> VERIFICATION_ERROR_TYPE "ver type error"

%token <std::string> INLINE_INDEX "inline@0x"
%token <std::string> VTABLE_INDEX "vtable@0x"
%token <std::string> FIELD_OFFSET "field@0x"

%token <std::string> LINE_COMMENT "#xxx"

%token OP_BEGIN "begin of opcodes"

%token OP_NOP "nop"
%token OP_MOVE "move"
%token OP_MOVE_FROM16 "move/from16"
%token OP_MOVE_16 "move/16"
%token OP_MOVE_WIDE "move-wide"
%token OP_MOVE_WIDE_FROM16 "move-wide/from16"
%token OP_MOVE_WIDE_16 "move-wide/16"
%token OP_MOVE_OBJECT "move-object"
%token OP_MOVE_OBJECT_FROM16 "move-object/from16"
%token OP_MOVE_OBJECT_16 "move-object/16"
%token OP_MOVE_RESULT "move-result"
%token OP_MOVE_RESULT_WIDE "move-result-wide"
%token OP_MOVE_RESULT_OBJECT "move-result-object"
%token OP_MOVE_EXCEPTION "move-exception"
%token OP_RETURN_VOID "return-void"
%token OP_RETURN "return"
%token OP_RETURN_WIDE "return-wide"
%token OP_RETURN_OBJECT "return-object"
%token OP_CONST_4 "const/4"
%token OP_CONST_16 "const/16"
%token OP_CONST "const"
%token OP_CONST_HIGH16 "const/high16"
%token OP_CONST_WIDE_16 "const-wide/16"
%token OP_CONST_WIDE_32 "const-wide/32"
%token OP_CONST_WIDE "const-wide"
%token OP_CONST_WIDE_HIGH16 "const-wide/high16"
%token OP_CONST_STRING "const-string"
%token OP_CONST_STRING_JUMBO "const-string/jumbo"
%token OP_CONST_CLASS "const-class"
%token OP_MONITOR_ENTER "monitor-enter"
%token OP_MONITOR_EXIT "monitor-exit"
%token OP_CHECK_CAST "check-cast"
%token OP_INSTANCE_OF "instance-of"
%token OP_ARRAY_LENGTH "array-length"
%token OP_NEW_INSTANCE "new-instance"
%token OP_NEW_ARRAY "new-array"
%token OP_FILLED_NEW_ARRAY "filled-new-array"
%token OP_FILLED_NEW_ARRAY_RANGE "filled-new-array/range"
%token OP_FILL_ARRAY_DATA "fill-array-data"
%token OP_THROW "throw"
%token OP_GOTO "goto"
%token OP_GOTO_16 "goto/16"
%token OP_GOTO_32 "goto/32"
%token OP_PACKED_SWITCH "packed-switch"
%token OP_SPARSE_SWITCH "sparse-switch"
%token OP_CMPL_FLOAT "cmpl-float"
%token OP_CMPG_FLOAT "cmpg-float"
%token OP_CMPL_DOUBLE "cmpl-double"
%token OP_CMPG_DOUBLE "cmpg-double"
%token OP_CMP_LONG "cmp-long"
%token OP_IF_EQ "if-eq"
%token OP_IF_NE "if-ne"
%token OP_IF_LT "if-lt"
%token OP_IF_GE "if-ge"
%token OP_IF_GT "if-gt"
%token OP_IF_LE "if-le"
%token OP_IF_EQZ "if-eqz"
%token OP_IF_NEZ "if-nez"
%token OP_IF_LTZ "if-ltz"
%token OP_IF_GEZ "if-gez"
%token OP_IF_GTZ "if-gtz"
%token OP_IF_LEZ "if-lez"
%token OP_UNUSED_3E "unused-3e"
%token OP_UNUSED_3F "unused-3f"
%token OP_UNUSED_40 "unused-40"
%token OP_UNUSED_41 "unused-41"
%token OP_UNUSED_42 "unused-42"
%token OP_UNUSED_43 "unused-43"
%token OP_AGET "aget"
%token OP_AGET_WIDE "aget-wide"
%token OP_AGET_OBJECT "aget-object"
%token OP_AGET_BOOLEAN "aget-boolean"
%token OP_AGET_BYTE "aget-byte"
%token OP_AGET_CHAR "aget-char"
%token OP_AGET_SHORT "aget-short"
%token OP_APUT "aput"
%token OP_APUT_WIDE "aput-wide"
%token OP_APUT_OBJECT "aput-object"
%token OP_APUT_BOOLEAN "aput-boolean"
%token OP_APUT_BYTE "aput-byte"
%token OP_APUT_CHAR "aput-char"
%token OP_APUT_SHORT "aput-short"
%token OP_IGET "iget"
%token OP_IGET_WIDE "iget-wide"
%token OP_IGET_OBJECT "iget-object"
%token OP_IGET_BOOLEAN "iget-boolean"
%token OP_IGET_BYTE "iget-byte"
%token OP_IGET_CHAR "iget-char"
%token OP_IGET_SHORT "iget-short"
%token OP_IPUT "iput"
%token OP_IPUT_WIDE "iput-wide"
%token OP_IPUT_OBJECT "iput-object"
%token OP_IPUT_BOOLEAN "iput-boolean"
%token OP_IPUT_BYTE "iput-byte"
%token OP_IPUT_CHAR "iput-char"
%token OP_IPUT_SHORT "iput-short"
%token OP_SGET "sget"
%token OP_SGET_WIDE "sget-wide"
%token OP_SGET_OBJECT "sget-object"
%token OP_SGET_BOOLEAN "sget-boolean"
%token OP_SGET_BYTE "sget-byte"
%token OP_SGET_CHAR "sget-char"
%token OP_SGET_SHORT "sget-short"
%token OP_SPUT "sput"
%token OP_SPUT_WIDE "sput-wide"
%token OP_SPUT_OBJECT "sput-object"
%token OP_SPUT_BOOLEAN "sput-boolean"
%token OP_SPUT_BYTE "sput-byte"
%token OP_SPUT_CHAR "sput-char"
%token OP_SPUT_SHORT "sput-short"
%token OP_INVOKE_VIRTUAL "invoke-virtual"
%token OP_INVOKE_SUPER "invoke-super"
%token OP_INVOKE_DIRECT "invoke-direct"
%token OP_INVOKE_STATIC "invoke-static"
%token OP_INVOKE_INTERFACE "invoke-interface"
%token OP_UNUSED_73 "unused-73"
%token OP_INVOKE_VIRTUAL_RANGE "invoke-virtual/range"
%token OP_INVOKE_SUPER_RANGE "invoke-super/range"
%token OP_INVOKE_DIRECT_RANGE "invoke-direct/range"
%token OP_INVOKE_STATIC_RANGE "invoke-static/range"
%token OP_INVOKE_INTERFACE_RANGE "invoke-interface/range"
%token OP_UNUSED_79 "unused-79"
%token OP_UNUSED_7A "unused-7a"
%token OP_NEG_INT "neg-int"
%token OP_NOT_INT "not-int"
%token OP_NEG_LONG "neg-long"
%token OP_NOT_LONG "not-long"
%token OP_NEG_FLOAT "neg-float"
%token OP_NEG_DOUBLE "neg-double"
%token OP_INT_TO_LONG "int-to-long"
%token OP_INT_TO_FLOAT "int-to-float"
%token OP_INT_TO_DOUBLE "int-to-double"
%token OP_LONG_TO_INT "long-to-int"
%token OP_LONG_TO_FLOAT "long-to-float"
%token OP_LONG_TO_DOUBLE "long-to-double"
%token OP_FLOAT_TO_INT "float-to-int"
%token OP_FLOAT_TO_LONG "float-to-long"
%token OP_FLOAT_TO_DOUBLE "float-to-double"
%token OP_DOUBLE_TO_INT "double-to-int"
%token OP_DOUBLE_TO_LONG "double-to-long"
%token OP_DOUBLE_TO_FLOAT "double-to-float"
%token OP_INT_TO_BYTE "int-to-byte"
%token OP_INT_TO_CHAR "int-to-char"
%token OP_INT_TO_SHORT "int-to-short"
%token OP_ADD_INT "add-int"
%token OP_SUB_INT "sub-int"
%token OP_MUL_INT "mul-int"
%token OP_DIV_INT "div-int"
%token OP_REM_INT "rem-int"
%token OP_AND_INT "and-int"
%token OP_OR_INT "or-int"
%token OP_XOR_INT "xor-int"
%token OP_SHL_INT "shl-int"
%token OP_SHR_INT "shr-int"
%token OP_USHR_INT "ushr-int"
%token OP_ADD_LONG "add-long"
%token OP_SUB_LONG "sub-long"
%token OP_MUL_LONG "mul-long"
%token OP_DIV_LONG "div-long"
%token OP_REM_LONG "rem-long"
%token OP_AND_LONG "and-long"
%token OP_OR_LONG "or-long"
%token OP_XOR_LONG "xor-long"
%token OP_SHL_LONG "shl-long"
%token OP_SHR_LONG "shr-long"
%token OP_USHR_LONG "ushr-long"
%token OP_ADD_FLOAT "add-float"
%token OP_SUB_FLOAT "sub-float"
%token OP_MUL_FLOAT "mul-float"
%token OP_DIV_FLOAT "div-float"
%token OP_REM_FLOAT "rem-float"
%token OP_ADD_DOUBLE "add-double"
%token OP_SUB_DOUBLE "sub-double"
%token OP_MUL_DOUBLE "mul-double"
%token OP_DIV_DOUBLE "div-double"
%token OP_REM_DOUBLE "rem-double"
%token OP_ADD_INT_2ADDR "add-int/2addr"
%token OP_SUB_INT_2ADDR "sub-int/2addr"
%token OP_MUL_INT_2ADDR "mul-int/2addr"
%token OP_DIV_INT_2ADDR "div-int/2addr"
%token OP_REM_INT_2ADDR "rem-int/2addr"
%token OP_AND_INT_2ADDR "and-int/2addr"
%token OP_OR_INT_2ADDR "or-int/2addr"
%token OP_XOR_INT_2ADDR "xor-int/2addr"
%token OP_SHL_INT_2ADDR "shl-int/2addr"
%token OP_SHR_INT_2ADDR "shr-int/2addr"
%token OP_USHR_INT_2ADDR "ushr-int/2addr"
%token OP_ADD_LONG_2ADDR "add-long/2addr"
%token OP_SUB_LONG_2ADDR "sub-long/2addr"
%token OP_MUL_LONG_2ADDR "mul-long/2addr"
%token OP_DIV_LONG_2ADDR "div-long/2addr"
%token OP_REM_LONG_2ADDR "rem-long/2addr"
%token OP_AND_LONG_2ADDR "and-long/2addr"
%token OP_OR_LONG_2ADDR "or-long/2addr"
%token OP_XOR_LONG_2ADDR "xor-long/2addr"
%token OP_SHL_LONG_2ADDR "shl-long/2addr"
%token OP_SHR_LONG_2ADDR "shr-long/2addr"
%token OP_USHR_LONG_2ADDR "ushr-long/2addr"
%token OP_ADD_FLOAT_2ADDR "add-float/2addr"
%token OP_SUB_FLOAT_2ADDR "sub-float/2addr"
%token OP_MUL_FLOAT_2ADDR "mul-float/2addr"
%token OP_DIV_FLOAT_2ADDR "div-float/2addr"
%token OP_REM_FLOAT_2ADDR "rem-float/2addr"
%token OP_ADD_DOUBLE_2ADDR "add-double/2addr"
%token OP_SUB_DOUBLE_2ADDR "sub-double/2addr"
%token OP_MUL_DOUBLE_2ADDR "mul-double/2addr"
%token OP_DIV_DOUBLE_2ADDR "div-double/2addr"
%token OP_REM_DOUBLE_2ADDR "rem-double/2addr"
%token OP_ADD_INT_LIT16 "add-int/lit16"
%token OP_RSUB_INT "rsub-int"
%token OP_MUL_INT_LIT16 "mul-int/lit16"
%token OP_DIV_INT_LIT16 "div-int/lit16"
%token OP_REM_INT_LIT16 "rem-int/lit16"
%token OP_AND_INT_LIT16 "and-int/lit16"
%token OP_OR_INT_LIT16 "or-int/lit16"
%token OP_XOR_INT_LIT16 "xor-int/lit16"
%token OP_ADD_INT_LIT8 "add-int/lit8"
%token OP_RSUB_INT_LIT8 "rsub-int/lit8"
%token OP_MUL_INT_LIT8 "mul-int/lit8"
%token OP_DIV_INT_LIT8 "div-int/lit8"
%token OP_REM_INT_LIT8 "rem-int/lit8"
%token OP_AND_INT_LIT8 "and-int/lit8"
%token OP_OR_INT_LIT8 "or-int/lit8"
%token OP_XOR_INT_LIT8 "xor-int/lit8"
%token OP_SHL_INT_LIT8 "shl-int/lit8"
%token OP_SHR_INT_LIT8 "shr-int/lit8"
%token OP_USHR_INT_LIT8 "ushr-int/lit8"
%token OP_IGET_VOLATILE "+iget-volatile"
%token OP_IPUT_VOLATILE "+iput-volatile"
%token OP_SGET_VOLATILE "+sget-volatile"
%token OP_SPUT_VOLATILE "+sput-volatile"
%token OP_IGET_OBJECT_VOLATILE "+iget-object-volatile"
%token OP_IGET_WIDE_VOLATILE "+iget-wide-volatile"
%token OP_IPUT_WIDE_VOLATILE "+iput-wide-volatile"
%token OP_SGET_WIDE_VOLATILE "+sget-wide-volatile"
%token OP_SPUT_WIDE_VOLATILE "+sput-wide-volatile"
%token OP_BREAKPOINT "^breakpoint"
%token OP_THROW_VERIFICATION_ERROR "^throw-verification-error"
%token OP_EXECUTE_INLINE "+execute-inline"
%token OP_EXECUTE_INLINE_RANGE "+execute-inline/range"
%token OP_INVOKE_OBJECT_INIT_RANGE "+invoke-object-init/range"
%token OP_RETURN_VOID_BARRIER "+return-void-barrier"
%token OP_IGET_QUICK "+iget-quick"
%token OP_IGET_WIDE_QUICK "+iget-wide-quick"
%token OP_IGET_OBJECT_QUICK "+iget-object-quick"
%token OP_IPUT_QUICK "+iput-quick"
%token OP_IPUT_WIDE_QUICK "+iput-wide-quick"
%token OP_IPUT_OBJECT_QUICK "+iput-object-quick"
%token OP_INVOKE_VIRTUAL_QUICK "+invoke-virtual-quick"
%token OP_INVOKE_VIRTUAL_QUICK_RANGE "+invoke-virtual-quick/range"
%token OP_INVOKE_SUPER_QUICK "+invoke-super-quick"
%token OP_INVOKE_SUPER_QUICK_RANGE "+invoke-super-quick/range"
%token OP_IPUT_OBJECT_VOLATILE "+iput-object-volatile"
%token OP_SGET_OBJECT_VOLATILE "+sget-object-volatile"
%token OP_SPUT_OBJECT_VOLATILE "+sput-object-volatile"
%token OP_UNUSED_FF "unused-ff"

%token OP_END "end of opcodes"

%token SYMBOL_BEGIN "begin of symbol"

%token DOTDOT ".."
%token ARROW "->"
%token EQUAL "="
%token COLON ":"
%token COMMA ","
%token OPEN_BRACE "{"
%token CLOSE_BRACE "}"
%token OPEN_PAREN "("
%token CLOSE_PAREN ")"

%token SYMBOL_END "end of symbol"

%start program

%%

program :
       %empty
       ;
%%

void Analysis::SmaliParser::error(const location &loc, const std::string &message) {
	//cout << "Parse error: " << message << endl
	//    << "Error location: " << loc << endl << driver.mLexer->text() << endl;
}