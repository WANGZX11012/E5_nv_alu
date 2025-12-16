// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VRUNLIGHT__SYMS_H_
#define VERILATED_VRUNLIGHT__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vrunlight.h"

// INCLUDE MODULE CLASSES
#include "Vrunlight___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vrunlight__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vrunlight* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vrunlight___024root            TOP;

    // CONSTRUCTORS
    Vrunlight__Syms(VerilatedContext* contextp, const char* namep, Vrunlight* modelp);
    ~Vrunlight__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
};

#endif  // guard
