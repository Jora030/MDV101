// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprocessor.h for the primary calling header

#include "Vprocessor__pch.h"
#include "Vprocessor__Syms.h"
#include "Vprocessor___024unit.h"

extern "C" void bitty_check(int instruction, int hardware_result);

VL_INLINE_OPT void Vprocessor___024unit____Vdpiimwrap_bitty_check_TOP____024unit(IData/*31:0*/ instruction, IData/*31:0*/ hardware_result) {
    VL_DEBUG_IF(VL_DBG_MSGF("+        Vprocessor___024unit____Vdpiimwrap_bitty_check_TOP____024unit\n"); );
    // Body
    int instruction__Vcvt;
    for (size_t instruction__Vidx = 0; instruction__Vidx < 1; ++instruction__Vidx) instruction__Vcvt = instruction;
    int hardware_result__Vcvt;
    for (size_t hardware_result__Vidx = 0; hardware_result__Vidx < 1; ++hardware_result__Vidx) hardware_result__Vcvt = hardware_result;
    bitty_check(instruction__Vcvt, hardware_result__Vcvt);
}
