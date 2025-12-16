module top(a, b, opcode, out, out_c, out_s, overflow);

    input [3:0]a;
    input [3:0]b;
    input [2:0]opcode;

    output out;
    output [3:0] out_s;
    output out_c;
    output overflow;

    wire [3:0] add_s, sub_s;
    wire       add_c, sub_c;
    wire       add_overflow, sub_overflow;

    reg mid_out;
    reg [3:0] mid_s;
    reg mid_c;
    reg mid_over;


  // 实例化加法器
    adder #(.bits_width(4)) u_adder (
        .a(a),
        .b(b),
        .out_s(add_s),
        .out_c(add_c),
        .overflow(add_overflow)
    );

    // 实例化减法器
    subtracter #(.bits_width(4)) u_sub (
        .a(a),
        .b(b),
        .out_s(sub_s),
        .out_c(sub_c),
        .overflow(sub_overflow)
    );


always@(*)
begin
    mid_c    = 0;
    mid_out  = 0;
    mid_over = 0;
    mid_s    = 0;



    case (opcode)
        3'b000:
        begin
            mid_s = add_s;
            mid_c = add_c;
            mid_over = add_overflow;
        end 

        3'b001:
        begin
            mid_s = sub_s;
            mid_c = sub_c;
            mid_over = sub_overflow;
        end

        3'b010:
            mid_s = ~a;
        
        3'b011:
            mid_s = a & b;
        3'b100:
            mid_s = a | b;
        3'b101:
            mid_s = a ^ b;
        3'b110:
            mid_out = (a < b) ? 1 : 0;
        3'b111:
            mid_out = (a == b) ? 1 : 0;

        default:
        begin
            mid_c    = 0;
            mid_out  = 0;
            mid_over = 0;
            mid_s    = 0;
        end
    endcase

end


assign    out_c    = mid_c ;
assign    out      = mid_out;
assign    overflow = mid_over;
assign    out_s    = mid_s;


endmodule