#include <nvboard.h>
#include <Vtop.h>
#include <stdio.h>

static TOP_NAME dut;

void nvboard_bind_all_pins(TOP_NAME* top);


int main() {
  int opcode_last = 0;
  int a_last = 0;
  int b_last = 0;


  nvboard_bind_all_pins(&dut);  // 绑定 Verilog 端口和 NVBoard
  nvboard_init();               // 初始化 NVBoard
  while (1) 
  {
    nvboard_update();  // 仍需调用以更新界面
    dut.eval();
    if(opcode_last != dut.opcode || dut.a != a_last || dut.b != b_last)
    {
        // 4-bit 带符号扩展（bit3 为符号位）
      int a_signed = ((int8_t)(dut.a << 4)) >> 4; // { changed code }
      int b_signed = ((int8_t)(dut.b << 4)) >> 4; // { changed code }
      int sum_signed = ((int8_t)(dut.out_s << 4)) >> 4;

      switch (dut.opcode)
      {
      case 0:
        printf("add\n");
        printf("a = %d,b = %d, sum is %d count is %d overflow is %d\n",a_signed, b_signed, sum_signed, dut.out_c, dut.overflow);
        break;
      
      case 1:
        printf("sub\n");
        printf("a = %d,b = %d, sub is %d count is %d overflow is %d\n",a_signed, b_signed, sum_signed, dut.out_c, dut.overflow);
        break;

      case 2:
        printf("oposite a\n");
        printf("a = %d ~a = signed %d or unsigned %d\n",a_signed, sum_signed -1, dut.out_s);
        break;

      case 3:
        printf("a & b\n");
        printf("a = %d, b = %d, a & b = %d\n", a_signed, b_signed, sum_signed );
        break;
      
      case 4:
        printf("a or b\n");
        printf("a = %d, b = %d, a | b = %d\n", a_signed, b_signed, sum_signed );
        break;
      
      case 5:
        printf("a xor b\n");
        printf("a = %d, b = %d, a | b = %d\n", a_signed, b_signed, sum_signed );
        break;
      
      case 6:
        printf("a < b ?\n");
        printf("a = %d, b = %d, out = %d\n", a_signed, b_signed, dut.out);
        break;

      case 7:
        printf("a = b ?\n");
        printf("a = %d, b = %d, out = %d\n", a_signed, b_signed, dut.out);
        break;
      default:
        break;
      }
  
      opcode_last = dut.opcode;
      a_last = dut.a;
      b_last = dut.b;
    }
    
  }
}
