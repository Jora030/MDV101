// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vprocessor__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vprocessor::Vprocessor(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vprocessor__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , res{vlSymsp->TOP.res}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vprocessor::Vprocessor(const char* _vcname__)
    : Vprocessor(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vprocessor::~Vprocessor() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vprocessor___024root___eval_debug_assertions(Vprocessor___024root* vlSelf);
#endif  // VL_DEBUG
void Vprocessor___024root___eval_static(Vprocessor___024root* vlSelf);
void Vprocessor___024root___eval_initial(Vprocessor___024root* vlSelf);
void Vprocessor___024root___eval_settle(Vprocessor___024root* vlSelf);
void Vprocessor___024root___eval(Vprocessor___024root* vlSelf);

void Vprocessor::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vprocessor::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vprocessor___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vprocessor___024root___eval_static(&(vlSymsp->TOP));
        Vprocessor___024root___eval_initial(&(vlSymsp->TOP));
        Vprocessor___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vprocessor___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vprocessor::eventsPending() { return false; }

uint64_t Vprocessor::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vprocessor::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vprocessor___024root___eval_final(Vprocessor___024root* vlSelf);

VL_ATTR_COLD void Vprocessor::final() {
    Vprocessor___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vprocessor::hierName() const { return vlSymsp->name(); }
const char* Vprocessor::modelName() const { return "Vprocessor"; }
unsigned Vprocessor::threads() const { return 1; }
void Vprocessor::prepareClone() const { contextp()->prepareClone(); }
void Vprocessor::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vprocessor::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vprocessor___024root__trace_decl_types(VerilatedVcd* tracep);

void Vprocessor___024root__trace_init_top(Vprocessor___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vprocessor___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vprocessor___024root*>(voidSelf);
    Vprocessor__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    Vprocessor___024root__trace_decl_types(tracep);
    Vprocessor___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vprocessor___024root__trace_register(Vprocessor___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vprocessor::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vprocessor::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vprocessor___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
