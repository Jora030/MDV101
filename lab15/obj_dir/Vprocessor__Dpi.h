// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VPROCESSOR__DPI_H_
#define VERILATED_VPROCESSOR__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI IMPORTS
    // DPI import at processor.v:10:33
    extern int eval_instruction(int instr);
    // DPI import at processor.v:9:33
    extern int get_instruction();

#ifdef __cplusplus
}
#endif

#endif  // guard
