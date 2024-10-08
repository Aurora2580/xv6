#include "console.h"

int exec(const char *str) {

    putstr("Hello, World!\n");
    return 0;
}


#define INSTRUCTION_LENGTH 128

int main(void) {
    char c;
    char INS[INSTRUCTION_LENGTH];
    int index = 0;

    //启用中断
    WriteReg(IER, IER_ENABLE);



    while (1) {
        c = getchar(); // 从RHR读取字符

        //echo
        putchar(c);

        //记录指令
        INS[index++] = c;
        if(c == '\r') {
           
            INS[index] = '\0';
            index = 0;
            exec(INS);
      
        }
        
    }

    return 0; // 添加返回值
}
