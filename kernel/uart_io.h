#include <stdint.h>
#include <string.h>

#define UART_BASE 0x10000000 // UART0 mmio base address
#define Reg(reg) ((unsigned char *)(UART_BASE + (reg)))
// http://byterunner.com/16550.html
#define RHR 0                 // receive holding register (for input bytes)
#define THR 0                 // transmit holding register (for output bytes)
#define IER 1                 // interrupt enable register
#define LSR 5                 // 线路状态寄存器
#define IER_ENABLE (0b111)    //中断使能
#define LSR_RX_READY (1<<0)   // input is waiting to be read from RHR
#define LSR_TX_IDLE (1<<5)    // THR can accept another character to send

#define ReadReg(reg) (*(Reg(reg)))
#define WriteReg(reg, v) (*(Reg(reg)) = (v))


void putchar(char c);

char getchar(void);

void putstr(const char *str);

void getstr(char *str, int max_len);
