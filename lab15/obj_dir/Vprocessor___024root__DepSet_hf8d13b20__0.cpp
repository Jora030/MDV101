// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprocessor.h for the primary calling header

#include "Vprocessor__pch.h"
#include "Vprocessor___024root.h"

void Vprocessor___024root___eval_act(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_act\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vprocessor___024root___nba_sequent__TOP__0(Vprocessor___024root* vlSelf);

void Vprocessor___024root___eval_nba(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_nba\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vprocessor___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vprocessor___024root____Vdpiimwrap_processor__DOT__get_instruction_TOP(IData/*31:0*/ &get_instruction__Vfuncrtn);
void Vprocessor___024root____Vdpiimwrap_processor__DOT__eval_instruction_TOP(IData/*31:0*/ instr, IData/*31:0*/ &eval_instruction__Vfuncrtn);

VL_INLINE_OPT void Vprocessor___024root___nba_sequent__TOP__0(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___nba_sequent__TOP__0\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __Vfunc_processor__DOT__get_instruction__0__Vfuncout;
    __Vfunc_processor__DOT__get_instruction__0__Vfuncout = 0;
    IData/*31:0*/ __Vfunc_processor__DOT__eval_instruction__1__Vfuncout;
    __Vfunc_processor__DOT__eval_instruction__1__Vfuncout = 0;
    SData/*15:0*/ __Vdly__processor__DOT__instr;
    __Vdly__processor__DOT__instr = 0;
    // Body
    __Vdly__processor__DOT__instr = vlSelfRef.processor__DOT__instr;
    if (vlSelfRef.rst) {
        vlSelfRef.res = 0U;
    } else {
        __Vdly__processor__DOT__instr = (0xffffU & 
                                         ([&]() {
                    Vprocessor___024root____Vdpiimwrap_processor__DOT__get_instruction_TOP(__Vfunc_processor__DOT__get_instruction__0__Vfuncout);
                }(), __Vfunc_processor__DOT__get_instruction__0__Vfuncout));
        vlSelfRef.res = (0xffffU & ([&]() {
                    Vprocessor___024root____Vdpiimwrap_processor__DOT__eval_instruction_TOP(vlSelfRef.processor__DOT__instr, __Vfunc_processor__DOT__eval_instruction__1__Vfuncout);
                }(), __Vfunc_processor__DOT__eval_instruction__1__Vfuncout));
    }
    vlSelfRef.processor__DOT__instr = __Vdly__processor__DOT__instr;
}

void Vprocessor___024root___eval_triggers__act(Vprocessor___024root* vlSelf);

bool Vprocessor___024root___eval_phase__act(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_phase__act\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vprocessor___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vprocessor___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vprocessor___024root___eval_phase__nba(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_phase__nba\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vprocessor___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vprocessor___024root___dump_triggers__nba(Vprocessor___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vprocessor___024root___dump_triggers__act(Vprocessor___024root* vlSelf);
#endif  // VL_DEBUG

void Vprocessor___024root___eval(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vprocessor___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("processor.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vprocessor___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("processor.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vprocessor___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vprocessor___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vprocessor___024root___eval_debug_assertions(Vprocessor___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_debug_assertions\n"); );
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
