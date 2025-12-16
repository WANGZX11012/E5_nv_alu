module adder #(parameter bits_width = 1)(   //default 1, usage: adder #(.bits_width(4)) u_adder(.a....)
    input  [bits_width-1:0] a,
    input  [bits_width-1:0] b,
    output [bits_width-1:0] out_s,
    output                  out_c,
    output                  overflow
);
    assign {out_c, out_s} = a + b;
    assign overflow = (a[bits_width-1] == b[bits_width-1]) && (out_s[bits_width-1] != a[bits_width-1]);
endmodule
