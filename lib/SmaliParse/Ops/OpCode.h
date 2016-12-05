//===- OpCode.h - ART-LEX ---------------------------------------*- c++ -*-===//
//
//                     ANDROID REVERSE TOOLKIT
//
// This file is distributed under the GNU GENERAL PUBLIC LICENSE
// V3 License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// The file defines opcode
//
//===----------------------------------------------------------------------===//


#ifndef SMALIPARSER_OPCODE_H
#define SMALIPARSER_OPCODE_H

#include "utils/Defs.h"
#include "RegisterX.h"
#include "utils/StringPool.hpp"
#include "RegisterX.h"

namespace Analysis {
    namespace Android
    {

        static u1 gInstructionWidthTable[kNumPackedOpcodes + kExtraOpcodes] = {
                // BEGIN(libdex-widths); GENERATED AUTOMATICALLY BY opcode-gen
                1,1,2,3,1,2,3,1,2,3,1,1,1,1,1,1,
                1,1,1,2,3,2,2,3,5,2,2,3,2,1,1,2,
                2,1,2,2,3,3,3,1,1,2,3,3,3,2,2,2,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,0,0,
                0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,3,3,
                3,3,3,0,3,3,3,3,3,0,0,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
                2,2,2,2,2,2,2,2,2,2,2,2,0,2,3,3,
                3,1,2,2,2,2,2,2,3,3,3,3,2,2,2,0,
                // END(libdex-widths)
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        };

        static u1 gOpcodeFlagsTable[kNumPackedOpcodes + kExtraOpcodes] = {
                // BEGIN(libdex-flags); GENERATED AUTOMATICALLY BY opcode-gen
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanReturn,
                kInstrCanReturn,
                kInstrCanReturn,
                kInstrCanReturn,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue,
                kInstrCanThrow,
                kInstrCanBranch,
                kInstrCanBranch,
                kInstrCanBranch,
                kInstrCanContinue | kInstrCanSwitch,
                kInstrCanContinue | kInstrCanSwitch,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                kInstrCanContinue | kInstrCanBranch,
                0,
                0,
                0,
                0,
                0,
                0,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                0,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                0,
                0,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                0,
                kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanReturn,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow | kInstrInvoke,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                kInstrCanContinue | kInstrCanThrow,
                0,
                // END(libdex-flags)
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        };

/*
 * Table that maps each opcode to the instruction format associated
 * that opcode.
 */
        static u1 gInstructionFormatTable[kNumPackedOpcodes + kExtraOpcodes] = {
                // BEGIN(libdex-formats); GENERATED AUTOMATICALLY BY opcode-gen
                kFmt10x,kFmt12x,kFmt22x,kFmt32x,kFmt12x,kFmt22x,kFmt32x,
                kFmt12x,kFmt22x,kFmt32x,kFmt11x,kFmt11x,kFmt11x,kFmt11x,
                kFmt10x,kFmt11x,kFmt11x,kFmt11x,kFmt11n,kFmt21s,kFmt31i,
                kFmt21h,kFmt21s,kFmt31i,kFmt51l,kFmt21h,kFmt21c,kFmt31c,
                kFmt21c,kFmt11x,kFmt11x,kFmt21c,kFmt22c,kFmt12x,kFmt21c,
                kFmt22c,kFmt35c,kFmt3rc,kFmt31t,kFmt11x,kFmt10t,kFmt20t,
                kFmt30t,kFmt31t,kFmt31t,kFmt23x,kFmt23x,kFmt23x,kFmt23x,
                kFmt23x,kFmt22t,kFmt22t,kFmt22t,kFmt22t,kFmt22t,kFmt22t,
                kFmt21t,kFmt21t,kFmt21t,kFmt21t,kFmt21t,kFmt21t,kFmt00x,
                kFmt00x,kFmt00x,kFmt00x,kFmt00x,kFmt00x,kFmt23x,kFmt23x,
                kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,
                kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt22c,kFmt22c,
                kFmt22c,kFmt22c,kFmt22c,kFmt22c,kFmt22c,kFmt22c,kFmt22c,
                kFmt22c,kFmt22c,kFmt22c,kFmt22c,kFmt22c,kFmt21c,kFmt21c,
                kFmt21c,kFmt21c,kFmt21c,kFmt21c,kFmt21c,kFmt21c,kFmt21c,
                kFmt21c,kFmt21c,kFmt21c,kFmt21c,kFmt21c,kFmt35c,kFmt35c,
                kFmt35c,kFmt35c,kFmt35c,kFmt00x,kFmt3rc,kFmt3rc,kFmt3rc,
                kFmt3rc,kFmt3rc,kFmt00x,kFmt00x,kFmt12x,kFmt12x,kFmt12x,
                kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,
                kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,
                kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt23x,kFmt23x,kFmt23x,
                kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,
                kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,
                kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,
                kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,kFmt23x,
                kFmt23x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,
                kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,
                kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,
                kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,
                kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt12x,kFmt22s,kFmt22s,
                kFmt22s,kFmt22s,kFmt22s,kFmt22s,kFmt22s,kFmt22s,kFmt22b,
                kFmt22b,kFmt22b,kFmt22b,kFmt22b,kFmt22b,kFmt22b,kFmt22b,
                kFmt22b,kFmt22b,kFmt22b,kFmt22c,kFmt22c,kFmt21c,kFmt21c,
                kFmt22c,kFmt22c,kFmt22c,kFmt21c,kFmt21c,kFmt00x,kFmt20bc,
                kFmt35mi,kFmt3rmi,kFmt35c,kFmt10x,kFmt22cs,kFmt22cs,kFmt22cs,
                kFmt22cs,kFmt22cs,kFmt22cs,kFmt35ms,kFmt3rms,kFmt35ms,kFmt3rms,
                kFmt22c,kFmt21c,kFmt21c,kFmt00x,
                // END(libdex-formats)
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        };

/*
 * Table that maps each opcode to the index type implied by that
 * opcode.
 */
        static u1 gInstructionIndexTypeTable[kNumPackedOpcodes + kExtraOpcodes] = {
                // BEGIN(libdex-index-types); GENERATED AUTOMATICALLY BY opcode-gen
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexStringRef,
                kIndexStringRef,kIndexTypeRef,kIndexNone,
                kIndexNone,kIndexTypeRef,kIndexTypeRef,
                kIndexNone,kIndexTypeRef,kIndexTypeRef,
                kIndexTypeRef,kIndexTypeRef,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexUnknown,
                kIndexUnknown,kIndexUnknown,kIndexUnknown,
                kIndexUnknown,kIndexUnknown,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexMethodRef,
                kIndexMethodRef,kIndexMethodRef,kIndexMethodRef,
                kIndexMethodRef,kIndexUnknown,kIndexMethodRef,
                kIndexMethodRef,kIndexMethodRef,kIndexMethodRef,
                kIndexMethodRef,kIndexUnknown,kIndexUnknown,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexNone,
                kIndexNone,kIndexNone,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexFieldRef,kIndexFieldRef,kIndexUnknown,
                kIndexVaries,kIndexInlineMethod,kIndexInlineMethod,
                kIndexMethodRef,kIndexNone,kIndexFieldOffset,
                kIndexFieldOffset,kIndexFieldOffset,kIndexFieldOffset,
                kIndexFieldOffset,kIndexFieldOffset,kIndexVtableOffset,
                kIndexVtableOffset,kIndexVtableOffset,kIndexVtableOffset,
                kIndexFieldRef,kIndexFieldRef,kIndexFieldRef,
                kIndexUnknown,
                // END(libdex-index-types)
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
        };

    }
    class OpCode {

    public:
        OpCode(Opcode o, StringPool* sp):op(o), mStringPool(sp) {
            insFormat = Android::gInstructionFormatTable[(u1)op];
            indexType = Android::gInstructionIndexTypeTable[(u1)op];
            opFlag = Android::gOpcodeFlagsTable[(u1)op];
            opLen = Android::gInstructionWidthTable[(u1)op];
        }
        virtual ~OpCode() { };
        virtual std::string toString() = 0;
        virtual void deleteThis() = 0;
        const std::string getPoolStr(int i) {
            return (*mStringPool)[i];
        }
        u1 insFormat;
        u1 indexType;
        u1 opFlag;
        u1 opLen;
        Opcode op;

        StringPool* mStringPool;
    };
}

#endif //SMALIPARSER_OPCODE_H
