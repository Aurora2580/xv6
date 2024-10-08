#include "uart_io.h"

void putchar_(char c) {
    while (!(ReadReg(LSR) & LSR_TX_IDLE)); // 等待THR可写
    WriteReg(THR, c);
}

void putchar(char c) {
    switch(c)
    {
        case '\r':
        {
            putchar_('\n');
            putchar_('\r');
            break;
        }
        default:
        {
            putchar_(c);   
        }

    }
}

char getchar(void) {
    while (!(ReadReg(LSR) & LSR_RX_READY)); // 等待RHR有数据
    return ReadReg(RHR);
}



void putstr(const char *str) {
    while (*str) {
        putchar(*str++);
    }
}

void getstr(char *str, int max_len) {
    int i = 0;
    while (i < max_len - 1) {
        char c = getchar();
        if (c == '\r') {
            *str++ = '\r';
            *str = '\0';               // 添加终止符
            return;
        }
        if (c == '\b' && i > 0) {      // 处理退格
            str--;
            i--;
        } else {
            *str++ = c;
            i++;
        }
    }
    *str = '\0';  // 如果超出长度，强制终止字符串
}
