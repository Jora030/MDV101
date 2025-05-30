// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"
#include "Vtop___024root.h"

void Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf);
void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf);
void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf);

void Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__1(vlSelf);
    }
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        Vtop___024root___nba_sequent__TOP__2(vlSelf);
        Vtop___024root___nba_comb__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    SData/*15:0*/ __Vdly__top__DOT__CPU__DOT__reg_a;
    __Vdly__top__DOT__CPU__DOT__reg_a = 0;
    CData/*3:0*/ __Vdly__top__DOT__CPU__DOT__counter;
    __Vdly__top__DOT__CPU__DOT__counter = 0;
    // Body
    __Vdly__top__DOT__CPU__DOT__counter = vlSelfRef.top__DOT__CPU__DOT__counter;
    __Vdly__top__DOT__CPU__DOT__reg_a = vlSelfRef.top__DOT__CPU__DOT__reg_a;
    vlSelfRef.__Vdly__top__DOT__FETCH__DOT__pc = vlSelfRef.top__DOT__FETCH__DOT__pc;
    if (vlSelfRef.reset) {
        vlSelfRef.__Vdly__top__DOT__FETCH__DOT__pc = 0U;
        __Vdly__top__DOT__CPU__DOT__reg_a = 0U;
        vlSelfRef.result = 0U;
        __Vdly__top__DOT__CPU__DOT__counter = 0U;
        vlSelfRef.done = 0U;
        vlSelfRef.top__DOT__compare_result = 0U;
        vlSelfRef.top__DOT__CPU__DOT__reg_b = 0U;
    } else {
        if (vlSelfRef.done) {
            vlSelfRef.__Vdly__top__DOT__FETCH__DOT__pc 
                = (0xffffU & ((2U == (3U & (IData)(vlSelfRef.top__DOT__instruction)))
                               ? (((IData)(vlSelfRef.top__DOT__compare_result) 
                                   == (3U & ((IData)(vlSelfRef.top__DOT__instruction) 
                                             >> 2U)))
                                   ? (0xfff0U & (IData)(vlSelfRef.top__DOT__instruction))
                                   : ((IData)(1U) + (IData)(vlSelfRef.top__DOT__FETCH__DOT__pc)))
                               : ((IData)(1U) + (IData)(vlSelfRef.top__DOT__FETCH__DOT__pc))));
        }
        if ((3U == (IData)(vlSelfRef.top__DOT__CPU__DOT__counter))) {
            vlSelfRef.result = vlSelfRef.top__DOT__CPU__DOT__reg_out;
            vlSelfRef.done = 1U;
            vlSelfRef.top__DOT__compare_result = (((IData)(vlSelfRef.top__DOT__CPU__DOT__reg_a) 
                                                   == (IData)(vlSelfRef.top__DOT__CPU__DOT__reg_b))
                                                   ? 0U
                                                   : 
                                                  (((IData)(vlSelfRef.top__DOT__CPU__DOT__reg_a) 
                                                    > (IData)(vlSelfRef.top__DOT__CPU__DOT__reg_b))
                                                    ? 1U
                                                    : 2U));
            __Vdly__top__DOT__CPU__DOT__counter = 0U;
            __Vdly__top__DOT__CPU__DOT__reg_a = vlSelfRef.top__DOT__CPU__DOT__reg_out;
        } else {
            __Vdly__top__DOT__CPU__DOT__counter = (0xfU 
                                                   & ((IData)(1U) 
                                                      + (IData)(vlSelfRef.top__DOT__CPU__DOT__counter)));
            vlSelfRef.done = 0U;
        }
    }
    vlSelfRef.top__DOT__CPU__DOT__counter = __Vdly__top__DOT__CPU__DOT__counter;
    vlSelfRef.top__DOT__CPU__DOT__reg_a = __Vdly__top__DOT__CPU__DOT__reg_a;
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__1(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__1\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__instruction = vlSelfRef.top__DOT__FETCH__DOT__memory
        [vlSelfRef.top__DOT__FETCH__DOT__pc];
}

VL_INLINE_OPT void Vtop___024root___nba_sequent__TOP__2(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__2\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__FETCH__DOT__pc = vlSelfRef.__Vdly__top__DOT__FETCH__DOT__pc;
}

VL_INLINE_OPT void Vtop___024root___nba_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.top__DOT__CPU__DOT__reg_out = (0xffffU 
                                             & ((4U 
                                                 & (IData)(vlSelfRef.top__DOT__instruction))
                                                 ? 
                                                ((2U 
                                                  & (IData)(vlSelfRef.top__DOT__instruction))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__instruction))
                                                   ? 0U
                                                   : 
                                                  (0xffU 
                                                   | (IData)(vlSelfRef.top__DOT__CPU__DOT__reg_a)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__instruction))
                                                   ? 
                                                  VL_SHIFTR_III(16,16,32, (IData)(vlSelfRef.top__DOT__CPU__DOT__reg_a), 1U)
                                                   : 
                                                  VL_SHIFTL_III(16,16,32, (IData)(vlSelfRef.top__DOT__CPU__DOT__reg_a), 1U)))
                                                 : 
                                                ((2U 
                                                  & (IData)(vlSelfRef.top__DOT__instruction))
                                                  ? 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__instruction))
                                                   ? 
                                                  (0xfffU 
                                                   & (IData)(vlSelfRef.top__DOT__CPU__DOT__reg_a))
                                                   : 
                                                  (~ (IData)(vlSelfRef.top__DOT__CPU__DOT__reg_a)))
                                                  : 
                                                 ((1U 
                                                   & (IData)(vlSelfRef.top__DOT__instruction))
                                                   ? 
                                                  ((IData)(vlSelfRef.top__DOT__CPU__DOT__reg_a) 
                                                   - (IData)(1U))
                                                   : 
                                                  ((IData)(1U) 
                                                   + (IData)(vlSelfRef.top__DOT__CPU__DOT__reg_a))))));
}

void Vtop___024root___eval_triggers__act(Vtop___024root* vlSelf);

bool Vtop___024root___eval_phase__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtop___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        Vtop___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtop___024root___eval_phase__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtop___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__nba(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(Vtop___024root* vlSelf);
#endif  // VL_DEBUG

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
            Vtop___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("top.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vtop___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("top.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (Vtop___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (Vtop___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
}
#endif  // VL_DEBUG
