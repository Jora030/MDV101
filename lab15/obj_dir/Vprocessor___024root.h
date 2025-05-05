// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vprocessor.h for the primary calling header

#ifndef VERILATED_VPROCESSOR___024ROOT_H_
#define VERILATED_VPROCESSOR___024ROOT_H_  // guard

#include "verilated.h"


class Vprocessor__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vprocessor___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    CData/*0:0*/ __VactContinue;
    VL_OUT16(res,15,0);
    SData/*15:0*/ processor__DOT__instr;
    IData/*31:0*/ __VactIterCount;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vprocessor__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vprocessor___024root(Vprocessor__Syms* symsp, const char* v__name);
    ~Vprocessor___024root();
    VL_UNCOPYABLE(Vprocessor___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
