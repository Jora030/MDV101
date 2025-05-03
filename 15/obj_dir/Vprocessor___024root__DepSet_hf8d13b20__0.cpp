// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vprocessor.h for the primary calling header

#include "Vprocessor__pch.h"
#include "Vprocessor___024root.h"

void Vprocessor___024root___eval_act(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vprocessor___024root___nba_sequent__TOP__0(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___nba_sequent__TOP__0\n"); );
    // Body
    vlSelf->__Vdly__processor__DOT__counter = vlSelf->processor__DOT__counter;
}

VL_INLINE_OPT void Vprocessor___024root___nba_sequent__TOP__2(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___nba_sequent__TOP__2\n"); );
    // Body
    vlSelf->processor__DOT__valid = (1U & (~ (IData)(vlSelf->reset)));
    if (vlSelf->reset) {
        vlSelf->__Vdly__processor__DOT__counter = 0U;
    } else {
        vlSelf->__Vdly__processor__DOT__counter = (0xffffU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelf->processor__DOT__counter)));
        vlSelf->processor__DOT__instruction = vlSelf->processor__DOT__counter;
        vlSelf->processor__DOT__alu_result = (0xffU 
                                              ^ (IData)(vlSelf->processor__DOT__counter));
    }
    vlSelf->processor__DOT__counter = vlSelf->__Vdly__processor__DOT__counter;
}

void Vprocessor___024root___nba_sequent__TOP__1(Vprocessor___024root* vlSelf);

void Vprocessor___024root___eval_nba(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vprocessor___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vprocessor___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vprocessor___024root___nba_sequent__TOP__2(vlSelf);
    }
}

void Vprocessor___024root___eval_triggers__act(Vprocessor___024root* vlSelf);

bool Vprocessor___024root___eval_phase__act(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vprocessor___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vprocessor___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vprocessor___024root___eval_phase__nba(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vprocessor___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
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
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vprocessor___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("processor.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vprocessor___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("processor.v", 1, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vprocessor___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vprocessor___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vprocessor___024root___eval_debug_assertions(Vprocessor___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vprocessor___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
