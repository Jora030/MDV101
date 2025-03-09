// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkey_lock_fsm.h for the primary calling header

#include "Vkey_lock_fsm__pch.h"
#include "Vkey_lock_fsm___024root.h"

extern const VlUnpacked<CData/*2:0*/, 128> Vkey_lock_fsm__ConstPool__TABLE_h2f217956_0;

VL_INLINE_OPT void Vkey_lock_fsm___024root___ico_sequent__TOP__0(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___ico_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    __Vtableidx1 = (((IData)(vlSelf->key_input) << 3U) 
                    | (IData)(vlSelf->key_lock_fsm__DOT__current_state));
    vlSelf->key_lock_fsm__DOT__next_state = Vkey_lock_fsm__ConstPool__TABLE_h2f217956_0
        [__Vtableidx1];
}

void Vkey_lock_fsm___024root___eval_ico(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval_ico\n"); );
    // Body
    if ((1ULL & vlSelf->__VicoTriggered.word(0U))) {
        Vkey_lock_fsm___024root___ico_sequent__TOP__0(vlSelf);
    }
}

void Vkey_lock_fsm___024root___eval_triggers__ico(Vkey_lock_fsm___024root* vlSelf);

bool Vkey_lock_fsm___024root___eval_phase__ico(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval_phase__ico\n"); );
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    Vkey_lock_fsm___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelf->__VicoTriggered.any();
    if (__VicoExecute) {
        Vkey_lock_fsm___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vkey_lock_fsm___024root___eval_act(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vkey_lock_fsm___024root___nba_sequent__TOP__0(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___nba_sequent__TOP__0\n"); );
    // Body
    VL_WRITEF("CLK: %20# | Input: %2# | Current State: %1# | Next State: %1# | Locked: %b\n",
              64,VL_TIME_UNITED_Q(1000),4,(IData)(vlSelf->key_input),
              3,vlSelf->key_lock_fsm__DOT__current_state,
              3,(IData)(vlSelf->key_lock_fsm__DOT__next_state),
              1,vlSelf->locked);
    Verilated::runFlushCallbacks();
}

VL_INLINE_OPT void Vkey_lock_fsm___024root___nba_sequent__TOP__1(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___nba_sequent__TOP__1\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->key_lock_fsm__DOT__current_state = ((IData)(vlSelf->reset)
                                                 ? 0U
                                                 : (IData)(vlSelf->key_lock_fsm__DOT__next_state));
    vlSelf->locked = (6U != (IData)(vlSelf->key_lock_fsm__DOT__current_state));
    __Vtableidx1 = (((IData)(vlSelf->key_input) << 3U) 
                    | (IData)(vlSelf->key_lock_fsm__DOT__current_state));
    vlSelf->key_lock_fsm__DOT__next_state = Vkey_lock_fsm__ConstPool__TABLE_h2f217956_0
        [__Vtableidx1];
}

void Vkey_lock_fsm___024root___eval_nba(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval_nba\n"); );
    // Body
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vkey_lock_fsm___024root___nba_sequent__TOP__0(vlSelf);
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vkey_lock_fsm___024root___nba_sequent__TOP__1(vlSelf);
    }
}

void Vkey_lock_fsm___024root___eval_triggers__act(Vkey_lock_fsm___024root* vlSelf);

bool Vkey_lock_fsm___024root___eval_phase__act(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vkey_lock_fsm___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vkey_lock_fsm___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vkey_lock_fsm___024root___eval_phase__nba(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vkey_lock_fsm___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkey_lock_fsm___024root___dump_triggers__ico(Vkey_lock_fsm___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vkey_lock_fsm___024root___dump_triggers__nba(Vkey_lock_fsm___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vkey_lock_fsm___024root___dump_triggers__act(Vkey_lock_fsm___024root* vlSelf);
#endif  // VL_DEBUG

void Vkey_lock_fsm___024root___eval(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelf->__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY((0x64U < __VicoIterCount))) {
#ifdef VL_DEBUG
            Vkey_lock_fsm___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("rtl/lock.v", 2, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (Vkey_lock_fsm___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelf->__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vkey_lock_fsm___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("rtl/lock.v", 2, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vkey_lock_fsm___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("rtl/lock.v", 2, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vkey_lock_fsm___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vkey_lock_fsm___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vkey_lock_fsm___024root___eval_debug_assertions(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((vlSelf->key_input & 0xf0U))) {
        Verilated::overWidthError("key_input");}
}
#endif  // VL_DEBUG
