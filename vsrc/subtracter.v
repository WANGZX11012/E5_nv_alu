module subtracter #(parameter bits_width = 4)(
    input  [bits_width-1:0] a,
    input  [bits_width-1:0] b,
    output [bits_width-1:0] out_s,
    output                  out_c,
    output                  overflow
);
    // 扩展一位避免丢掉最高位
    wire [bits_width:0] full_result;

    assign full_result = {1'b0, a} - {1'b0, b};
    assign out_s       = full_result[bits_width-1:0];
    assign out_c       = full_result[bits_width]; // 注意：这里不是严格的“借位”，只是扩展位
    assign overflow    = (a[bits_width-1] != b[bits_width-1]) && (out_s[bits_width-1] != a[bits_width-1]);//操作数符号不同，结果符号和被减数符号不同。

endmodule
