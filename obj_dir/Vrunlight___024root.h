// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vrunlight.h for the primary calling header

#ifndef VERILATED_VRUNLIGHT___024ROOT_H_
#define VERILATED_VRUNLIGHT___024ROOT_H_  // guard

#include "verilated.h"


class Vrunlight__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vrunlight___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_OUT8(led,4,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    IData/*31:0*/ top__DOT__cnt;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vrunlight__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vrunlight___024root(Vrunlight__Syms* symsp, const char* v__name);
    ~Vrunlight___024root();
    VL_UNCOPYABLE(Vrunlight___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
