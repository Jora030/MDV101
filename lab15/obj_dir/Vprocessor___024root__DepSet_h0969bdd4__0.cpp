// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprocessor.h for the primary calling header

#include "Vprocessor__pch.h"
#include "Vprocessor__Syms.h"
#include "Vprocessor___024root.h"

extern "C" int get_instruction();

VL_INLINE_OPT void Vprocessor___024root____Vdpiimwrap_processor__DOT__get_instruction_TOP(IData/*31:0*/ &get_instruction__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root____Vdpiimwrap_processor__DOT__get_instruction_TOP\n"); );
    // Body
    int get_instruction__Vfuncrtn__Vcvt;
    get_instruction__Vfuncrtn__Vcvt = get_instruction();
    get_instruction__Vfuncrtn = get_instruction__Vfuncrtn__Vcvt;
}

extern "C" int eval_instruction(int instr);

VL_INLINE_OPT void Vprocessor___024root____Vdpiimwrap_processor__DOT__eval_instruction_TOP(IData/*31:0*/ instr, IData/*31:0*/ &eval_instruction__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root____Vdpiimwrap_processor__DOT__eval_instruction_TOP\n"); );
    // Body
    int instr__Vcvt;
    for (size_t instr__Vidx = 0; instr__Vidx < 1; ++instr__Vidx) instr__Vcvt = instr;
    int eval_instruction__Vfuncrtn__Vcvt;
    eval_instruction__Vfuncrtn__Vcvt = eval_instruction(instr__Vcvt);
    eval_instruction__Vfuncrtn = eval_instruction__Vfuncrtn__Vcvt;
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprocessor___024root___dump_triggers__act(Vprocessor___024root* vlSelf);
#endif  // VL_DEBUG

void Vprocessor___024root___eval_triggers__act(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_triggers__act\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered.set(0U, ((IData)(vlSelfRef.clk) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
    vlSelfRef.__VactTriggered.set(1U, ((IData)(vlSelfRef.rst) 
                                       & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.rst;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vprocessor___024root___dump_triggers__act(vlSelf);
    }
#endif
}
