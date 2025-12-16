// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

void Vtop___024root___eval_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VicoFirstIteration)));
    vlSelfRef.__VicoFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
}

bool Vtop___024root___trigger_anySet__ico(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

void Vtop___024root___ico_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ico_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*3:0*/ top__DOT__add_s;
    top__DOT__add_s = 0;
    CData/*0:0*/ top__DOT__mid_out;
    top__DOT__mid_out = 0;
    CData/*3:0*/ top__DOT__mid_s;
    top__DOT__mid_s = 0;
    CData/*0:0*/ top__DOT__mid_c;
    top__DOT__mid_c = 0;
    CData/*0:0*/ top__DOT__mid_over;
    top__DOT__mid_over = 0;
    CData/*4:0*/ top__DOT__u_sub__DOT__full_result;
    top__DOT__u_sub__DOT__full_result = 0;
    // Body
    top__DOT__mid_out = 0U;
    top__DOT__add_s = (0x0000000fU & ((IData)(vlSelfRef.a) 
                                      + (IData)(vlSelfRef.b)));
    top__DOT__u_sub__DOT__full_result = (0x0000001fU 
                                         & ((IData)(vlSelfRef.a) 
                                            - (IData)(vlSelfRef.b)));
    if ((4U & (IData)(vlSelfRef.opcode))) {
        if ((2U & (IData)(vlSelfRef.opcode))) {
            top__DOT__mid_out = (1U & ((1U & (IData)(vlSelfRef.opcode))
                                        ? (((IData)(vlSelfRef.a) 
                                            == (IData)(vlSelfRef.b))
                                            ? 1U : 0U)
                                        : (((IData)(vlSelfRef.a) 
                                            < (IData)(vlSelfRef.b))
                                            ? 1U : 0U)));
        }
    }
    vlSelfRef.out = top__DOT__mid_out;
    top__DOT__mid_c = 0U;
    top__DOT__mid_over = 0U;
    if ((1U & (~ ((IData)(vlSelfRef.opcode) >> 2U)))) {
        if ((1U & (~ ((IData)(vlSelfRef.opcode) >> 1U)))) {
            if ((1U & (IData)(vlSelfRef.opcode))) {
                top__DOT__mid_c = (1U & ((IData)(top__DOT__u_sub__DOT__full_result) 
                                         >> 4U));
                top__DOT__mid_over = (((1U & ((IData)(vlSelfRef.a) 
                                              >> 3U)) 
                                       != (1U & ((IData)(vlSelfRef.b) 
                                                 >> 3U))) 
                                      & ((1U & ((IData)(top__DOT__u_sub__DOT__full_result) 
                                                >> 3U)) 
                                         != (1U & ((IData)(vlSelfRef.a) 
                                                   >> 3U))));
            } else {
                top__DOT__mid_c = (1U & (1U & (((IData)(vlSelfRef.a) 
                                                + (IData)(vlSelfRef.b)) 
                                               >> 4U)));
                top__DOT__mid_over = (((1U & ((IData)(vlSelfRef.a) 
                                              >> 3U)) 
                                       == (1U & ((IData)(vlSelfRef.b) 
                                                 >> 3U))) 
                                      & ((1U & ((IData)(top__DOT__add_s) 
                                                >> 3U)) 
                                         != (1U & ((IData)(vlSelfRef.a) 
                                                   >> 3U))));
            }
        }
    }
    top__DOT__mid_s = 0U;
    if ((4U & (IData)(vlSelfRef.opcode))) {
        if ((1U & (~ ((IData)(vlSelfRef.opcode) >> 1U)))) {
            top__DOT__mid_s = ((1U & (IData)(vlSelfRef.opcode))
                                ? ((IData)(vlSelfRef.a) 
                                   ^ (IData)(vlSelfRef.b))
                                : ((IData)(vlSelfRef.a) 
                                   | (IData)(vlSelfRef.b)));
        }
    } else {
        top__DOT__mid_s = (0x0000000fU & ((2U & (IData)(vlSelfRef.opcode))
                                           ? ((1U & (IData)(vlSelfRef.opcode))
                                               ? ((IData)(vlSelfRef.a) 
                                                  & (IData)(vlSelfRef.b))
                                               : (~ (IData)(vlSelfRef.a)))
                                           : ((1U & (IData)(vlSelfRef.opcode))
                                               ? (IData)(top__DOT__u_sub__DOT__full_result)
                                               : (IData)(top__DOT__add_s))));
    }
    vlSelfRef.out_c = top__DOT__mid_c;
    vlSelfRef.overflow = top__DOT__mid_over;
    vlSelfRef.out_s = top__DOT__mid_s;
}

void Vtop___024root___eval_ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered[0U])) {
        Vtop___024root___ico_sequent__TOP__0(vlSelf);
    }
}

bool Vtop___024root___eval_phase__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_phase__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VicoExecute;
    // Body
    Vtop___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = Vtop___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        Vtop___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VicoIterCount;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
            VL_FATAL_MT("/home/wang/E5/ysyx-workbench/nvboard/alu/vsrc/top.v", 1, "", "Input combinational region did not converge after 100 tries");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
    } while (Vtop___024root___eval_phase__ico(vlSelf));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.a & 0xf0U)))) {
        Verilated::overWidthError("a");
    }
    if (VL_UNLIKELY(((vlSelfRef.b & 0xf0U)))) {
        Verilated::overWidthError("b");
    }
    if (VL_UNLIKELY(((vlSelfRef.opcode & 0xf8U)))) {
        Verilated::overWidthError("opcode");
    }
}
#endif  // VL_DEBUG
