// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vkey_lock_fsm.h for the primary calling header

#include "Vkey_lock_fsm__pch.h"
#include "Vkey_lock_fsm__Syms.h"
#include "Vkey_lock_fsm___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkey_lock_fsm___024root___dump_triggers__ico(Vkey_lock_fsm___024root* vlSelf);
#endif  // VL_DEBUG

void Vkey_lock_fsm___024root___eval_triggers__ico(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval_triggers__ico\n"); );
    // Body
    vlSelf->__VicoTriggered.set(0U, (IData)(vlSelf->__VicoFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkey_lock_fsm___024root___dump_triggers__ico(vlSelf);
    }
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vkey_lock_fsm___024root___dump_triggers__act(Vkey_lock_fsm___024root* vlSelf);
#endif  // VL_DEBUG

void Vkey_lock_fsm___024root___eval_triggers__act(Vkey_lock_fsm___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vkey_lock_fsm___024root___eval_triggers__act\n"); );
    // Body
    vlSelf->__VactTriggered.set(0U, (((IData)(vlSelf->clk) 
                                      & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))) 
                                     | ((IData)(vlSelf->reset) 
                                        & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__reset__0)))));
    vlSelf->__VactTriggered.set(1U, ((IData)(vlSelf->clk) 
                                     & (~ (IData)(vlSelf->__Vtrigprevexpr___TOP__clk__0))));
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = vlSelf->clk;
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = vlSelf->reset;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vkey_lock_fsm___024root___dump_triggers__act(vlSelf);
    }
#endif
}
