// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vrunlight.h for the primary calling header

#include "Vrunlight__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vrunlight___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vrunlight___024root___eval_triggers__act(Vrunlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___eval_triggers__act\n"); );
    Vrunlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(
                                                    ((IData)(vlSelfRef.clk) 
                                                     & (~ (IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vrunlight___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
}

bool Vrunlight___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___trigger_anySet__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vrunlight___024root___nba_sequent__TOP__0(Vrunlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___nba_sequent__TOP__0\n"); );
    Vrunlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __Vdly__top__DOT__cnt;
    __Vdly__top__DOT__cnt = 0;
    // Body
    __Vdly__top__DOT__cnt = vlSelfRef.top__DOT__cnt;
    if (vlSelfRef.rst) {
        if ((0U == vlSelfRef.top__DOT__cnt)) {
            vlSelfRef.led = ((0x0000001eU & ((IData)(vlSelfRef.led) 
                                             << 1U)) 
                             | (1U & ((IData)(vlSelfRef.led) 
                                      >> 4U)));
            __Vdly__top__DOT__cnt = ((IData)(1U) + vlSelfRef.top__DOT__cnt);
        }
        __Vdly__top__DOT__cnt = ((0x02625a00U <= vlSelfRef.top__DOT__cnt)
                                  ? 0U : ((IData)(1U) 
                                          + vlSelfRef.top__DOT__cnt));
    } else {
        __Vdly__top__DOT__cnt = 0U;
        vlSelfRef.led = 1U;
    }
    vlSelfRef.top__DOT__cnt = __Vdly__top__DOT__cnt;
}

void Vrunlight___024root___eval_nba(Vrunlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___eval_nba\n"); );
    Vrunlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vrunlight___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vrunlight___024root___trigger_orInto__act(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___trigger_orInto__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vrunlight___024root___eval_phase__act(Vrunlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___eval_phase__act\n"); );
    Vrunlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vrunlight___024root___eval_triggers__act(vlSelf);
    Vrunlight___024root___trigger_orInto__act(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

void Vrunlight___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vrunlight___024root___eval_phase__nba(Vrunlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___eval_phase__nba\n"); );
    Vrunlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vrunlight___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vrunlight___024root___eval_nba(vlSelf);
        Vrunlight___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vrunlight___024root___eval(Vrunlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___eval\n"); );
    Vrunlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vrunlight___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("vsrc/runlight.v", 1, "", "NBA region did not converge after 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                Vrunlight___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                VL_FATAL_MT("vsrc/runlight.v", 1, "", "Active region did not converge after 100 tries");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
        } while (Vrunlight___024root___eval_phase__act(vlSelf));
    } while (Vrunlight___024root___eval_phase__nba(vlSelf));
}

#ifdef VL_DEBUG
void Vrunlight___024root___eval_debug_assertions(Vrunlight___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vrunlight___024root___eval_debug_assertions\n"); );
    Vrunlight__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.rst & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
