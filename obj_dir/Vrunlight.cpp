// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vrunlight__pch.h"

//============================================================
// Constructors

Vrunlight::Vrunlight(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vrunlight__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , led{vlSymsp->TOP.led}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vrunlight::Vrunlight(const char* _vcname__)
    : Vrunlight(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vrunlight::~Vrunlight() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vrunlight___024root___eval_debug_assertions(Vrunlight___024root* vlSelf);
#endif  // VL_DEBUG
void Vrunlight___024root___eval_static(Vrunlight___024root* vlSelf);
void Vrunlight___024root___eval_initial(Vrunlight___024root* vlSelf);
void Vrunlight___024root___eval_settle(Vrunlight___024root* vlSelf);
void Vrunlight___024root___eval(Vrunlight___024root* vlSelf);

void Vrunlight::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vrunlight::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vrunlight___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vrunlight___024root___eval_static(&(vlSymsp->TOP));
        Vrunlight___024root___eval_initial(&(vlSymsp->TOP));
        Vrunlight___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vrunlight___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vrunlight::eventsPending() { return false; }

uint64_t Vrunlight::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vrunlight::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vrunlight___024root___eval_final(Vrunlight___024root* vlSelf);

VL_ATTR_COLD void Vrunlight::final() {
    Vrunlight___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vrunlight::hierName() const { return vlSymsp->name(); }
const char* Vrunlight::modelName() const { return "Vrunlight"; }
unsigned Vrunlight::threads() const { return 1; }
void Vrunlight::prepareClone() const { contextp()->prepareClone(); }
void Vrunlight::atClone() const {
    contextp()->threadPoolpOnClone();
}
