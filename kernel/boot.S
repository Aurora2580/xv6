

.text

.globl _start # 声明全局符号 _start

_start:
    # 设置堆栈指针
    la sp, stack_top

    # 调用内核主函数
    jal main


.bss
# 堆栈空间
stack:
    .space 4096  # 4KB 堆栈 .space 分配空白字节空间
# 堆栈顶部地址
stack_top:
