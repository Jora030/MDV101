// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vkey_lock_fsm__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vkey_lock_fsm::Vkey_lock_fsm(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vkey_lock_fsm__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , key_input{vlSymsp->TOP.key_input}
    , locked{vlSymsp->TOP.locked}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vkey_lock_fsm::Vkey_lock_fsm(const char* _vcname__)
    : Vkey_lock_fsm(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vkey_lock_fsm::~Vkey_lock_fsm() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vkey_lock_fsm___024root___eval_debug_assertions(Vkey_lock_fsm___024root* vlSelf);
#endif  // VL_DEBUG
void Vkey_lock_fsm___024root___eval_static(Vkey_lock_fsm___024root* vlSelf);
void Vkey_lock_fsm___024root___eval_initial(Vkey_lock_fsm___024root* vlSelf);
void Vkey_lock_fsm___024root___eval_settle(Vkey_lock_fsm___024root* vlSelf);
void Vkey_lock_fsm___024root___eval(Vkey_lock_fsm___024root* vlSelf);

void Vkey_lock_fsm::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vkey_lock_fsm::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vkey_lock_fsm___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vkey_lock_fsm___024root___eval_static(&(vlSymsp->TOP));
        Vkey_lock_fsm___024root___eval_initial(&(vlSymsp->TOP));
        Vkey_lock_fsm___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vkey_lock_fsm___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vkey_lock_fsm::eventsPending() { return false; }

uint64_t Vkey_lock_fsm::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vkey_lock_fsm::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vkey_lock_fsm___024root___eval_final(Vkey_lock_fsm___024root* vlSelf);

VL_ATTR_COLD void Vkey_lock_fsm::final() {
    Vkey_lock_fsm___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vkey_lock_fsm::hierName() const { return vlSymsp->name(); }
const char* Vkey_lock_fsm::modelName() const { return "Vkey_lock_fsm"; }
unsigned Vkey_lock_fsm::threads() const { return 1; }
void Vkey_lock_fsm::prepareClone() const { contextp()->prepareClone(); }
void Vkey_lock_fsm::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vkey_lock_fsm::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vkey_lock_fsm___024root__trace_decl_types(VerilatedVcd* tracep);

void Vkey_lock_fsm___024root__trace_init_top(Vkey_lock_fsm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vkey_lock_fsm___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vkey_lock_fsm___024root*>(voidSelf);
    Vkey_lock_fsm__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vkey_lock_fsm___024root__trace_decl_types(tracep);
    Vkey_lock_fsm___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vkey_lock_fsm___024root__trace_register(Vkey_lock_fsm___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vkey_lock_fsm::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vkey_lock_fsm::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vkey_lock_fsm___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
