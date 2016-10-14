//===- Ops.h - ART-LEX ------------------------------------------*- c++ -*-===//
//
//                     ANDROID REVERSE TOOLKIT
//
// This file is distributed under the GNU GENERAL PUBLIC LICENSE
// V3 License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// Ops.h include header that contains all ops
//
//===----------------------------------------------------------------------===//

#ifndef SMALIPARSER_OPS_H
#define SMALIPARSER_OPS_H

#include "OpCode.h"

#include "Op_NOP.h"
#include "Op_MOVE.h"

#include "Op_MOVE_RESULT.h"
#include "Op_MOVE_EXCEPTION.h"
#include "Op_RETURN_VOID.h"
#include "Op_RETURN.h"
#include "Op_CONST_D.h"
//#include "OP_CONST.h"
//#include "OP_CONST_HIGH16.h"
//#include "OP_CONST_WIDE_16.h"
//#include "OP_CONST_WIDE_32.h"
//#include "OP_CONST_WIDE.h"
//#include "OP_CONST_WIDE_HIGH16.h"
#include "Op_CONST_STRING.h"
//#include "OP_CONST_CLASS.h"
//#include "OP_MONITOR_ENTER.h"
//#include "OP_MONITOR_EXIT.h"
#include "Op_CHECK_CAST.h"
//#include "OP_INSTANCE_OF.h"
#include "Op_ARRAY_LENGTH.h"
#include "Op_NEW_INSTANCE.h"
#include "Op_NEW_ARRAY.h"
//#include "OP_FILLED_NEW_ARRAY.h"
//#include "OP_FILLED_NEW_ARRAY_RANGE.h"
//#include "OP_FILL_ARRAY_DATA.h"
#include "Op_THROW.h"
#include "Op_GOTO.h"
#include "Op_X_SWITCH.h"
//#include "OP_CMPL_FLOAT.h"
//#include "OP_CMPG_FLOAT.h"
//#include "OP_CMPL_DOUBLE.h"
//#include "OP_CMPG_DOUBLE.h"
//#include "OP_CMP_LONG.h"
#include "Op_IF_XX.h"
#include "Op_IF_XXZ.h"
//#include "OP_UNUSED_3E.h"
//#include "OP_UNUSED_3F.h"
//#include "OP_UNUSED_40.h"
//#include "OP_UNUSED_41.h"
//#include "OP_UNUSED_42.h"
//#include "OP_UNUSED_43.h"
#include "Op_AGET.h"
//#include "OP_APUT.h"
//#include "OP_APUT_WIDE.h"
//#include "OP_APUT_OBJECT.h"
//#include "OP_APUT_BOOLEAN.h"
//#include "OP_APUT_BYTE.h"
//#include "OP_APUT_CHAR.h"
//#include "OP_APUT_SHORT.h"
#include "Op_IGET.h"
#include "Op_IPUT.h"
#include "Op_SGET.h"
#include "Op_SPUT.h"
#include "Op_INVOKE.h"
//#include "OP_UNUSED_73.h"
#include "Op_INVOKE_X_RANGE.h"
//#include "OP_UNUSED_79.h"
//#include "OP_UNUSED_7A.h"
//#include "OP_NEG_INT.h"
//#include "OP_NOT_INT.h"
//#include "OP_NEG_LONG.h"
//#include "OP_NOT_LONG.h"
//#include "OP_NEG_FLOAT.h"
//#include "OP_NEG_DOUBLE.h"
//#include "OP_INT_TO_LONG.h"
//#include "OP_INT_TO_FLOAT.h"
//#include "OP_INT_TO_DOUBLE.h"
//#include "OP_LONG_TO_INT.h"
//#include "OP_LONG_TO_FLOAT.h"
//#include "OP_LONG_TO_DOUBLE.h"
//#include "OP_FLOAT_TO_INT.h"
//#include "OP_FLOAT_TO_LONG.h"
//#include "OP_FLOAT_TO_DOUBLE.h"
//#include "OP_DOUBLE_TO_INT.h"
//#include "OP_DOUBLE_TO_LONG.h"
//#include "OP_DOUBLE_TO_FLOAT.h"
//#include "OP_INT_TO_BYTE.h"
//#include "OP_INT_TO_CHAR.h"
//#include "OP_INT_TO_SHORT.h"
//#include "OP_ADD_INT.h"
//#include "OP_SUB_INT.h"
//#include "OP_MUL_INT.h"
//#include "OP_DIV_INT.h"
//#include "OP_REM_INT.h"
//#include "OP_AND_INT.h"
//#include "OP_OR_INT.h"
//#include "OP_XOR_INT.h"
//#include "OP_SHL_INT.h"
//#include "OP_SHR_INT.h"
//#include "OP_USHR_INT.h"
//#include "OP_ADD_LONG.h"
//#include "OP_SUB_LONG.h"
//#include "OP_MUL_LONG.h"
//#include "OP_DIV_LONG.h"
//#include "OP_REM_LONG.h"
//#include "OP_AND_LONG.h"
//#include "OP_OR_LONG.h"
//#include "OP_XOR_LONG.h"
//#include "OP_SHL_LONG.h"
//#include "OP_SHR_LONG.h"
//#include "OP_USHR_LONG.h"
//#include "OP_ADD_FLOAT.h"
//#include "OP_SUB_FLOAT.h"
//#include "OP_MUL_FLOAT.h"
//#include "OP_DIV_FLOAT.h"
//#include "OP_REM_FLOAT.h"
//#include "OP_ADD_DOUBLE.h"
//#include "OP_SUB_DOUBLE.h"
//#include "OP_MUL_DOUBLE.h"
//#include "OP_DIV_DOUBLE.h"
//#include "OP_REM_DOUBLE.h"
#include "Op_X_INT_2ADDR.h"
//#include "OP_ADD_LONG_2ADDR.h"
//#include "OP_SUB_LONG_2ADDR.h"
//#include "OP_MUL_LONG_2ADDR.h"
//#include "OP_DIV_LONG_2ADDR.h"
//#include "OP_REM_LONG_2ADDR.h"
//#include "OP_AND_LONG_2ADDR.h"
//#include "OP_OR_LONG_2ADDR.h"
//#include "OP_XOR_LONG_2ADDR.h"
//#include "OP_SHL_LONG_2ADDR.h"
//#include "OP_SHR_LONG_2ADDR.h"
//#include "OP_USHR_LONG_2ADDR.h"
//#include "OP_ADD_FLOAT_2ADDR.h"
//#include "OP_SUB_FLOAT_2ADDR.h"
//#include "OP_MUL_FLOAT_2ADDR.h"
//#include "OP_DIV_FLOAT_2ADDR.h"
//#include "OP_REM_FLOAT_2ADDR.h"
//#include "OP_ADD_DOUBLE_2ADDR.h"
//#include "OP_SUB_DOUBLE_2ADDR.h"
//#include "OP_MUL_DOUBLE_2ADDR.h"
//#include "OP_DIV_DOUBLE_2ADDR.h"
//#include "OP_REM_DOUBLE_2ADDR.h"
#include "Op_X_INT_LIT.h"
//#include "OP_IGET_VOLATILE.h"
//#include "OP_IPUT_VOLATILE.h"
//#include "OP_SGET_VOLATILE.h"
//#include "OP_SPUT_VOLATILE.h"
//#include "OP_IGET_OBJECT_VOLATILE.h"
//#include "OP_IGET_WIDE_VOLATILE.h"
//#include "OP_IPUT_WIDE_VOLATILE.h"
//#include "OP_SGET_WIDE_VOLATILE.h"
//#include "OP_SPUT_WIDE_VOLATILE.h"
//#include "OP_BREAKPOINT.h"
//#include "OP_THROW_VERIFICATION_ERROR.h"
//#include "OP_EXECUTE_INLINE.h"
//#include "OP_EXECUTE_INLINE_RANGE.h"
//#include "OP_INVOKE_OBJECT_INIT_RANGE.h"
//#include "OP_RETURN_VOID_BARRIER.h"
//#include "OP_IGET_QUICK.h"
//#include "OP_IGET_WIDE_QUICK.h"
//#include "OP_IGET_OBJECT_QUICK.h"
//#include "OP_IPUT_QUICK.h"
//#include "OP_IPUT_WIDE_QUICK.h"
//#include "OP_IPUT_OBJECT_QUICK.h"
//#include "OP_INVOKE_VIRTUAL_QUICK.h"
//#include "OP_INVOKE_VIRTUAL_QUICK_RANGE.h"
//#include "OP_INVOKE_SUPER_QUICK.h"
//#include "OP_INVOKE_SUPER_QUICK_RANGE.h"
//#include "OP_IPUT_OBJECT_VOLATILE.h"
//#include "OP_SGET_OBJECT_VOLATILE.h"
//#include "OP_SPUT_OBJECT_VOLATILE.h"
//#include "OP_UNUSED_FF.h"
#include "Op_JmpLabel.h"
#include "Op_CATCH.h"
#include "Op_PACKED_SWITCHDATA.h"
#include "Op_PACKED_SWITCHDATA_BEG.h"
#include "Op_PACKED_SWITCHDATA_END.h"
#endif //SMALIPARSER_OPS_H
