OUTPUT_ARCH("riscv")
ENTRY(_start)

MEMORY {
    ROM (rx) : ORIGIN = 0x80000000, LENGTH = 512K 
    RAM (rwx) : ORIGIN = 0x80080000, LENGTH = 128K
}

SECTIONS {
    . = ORIGIN(ROM);

    .text : {
        *(.text)    /* 引导代码和内核代码 */
    } > ROM

    .rodata : {
        *(.rodata)  /* 只读数据 */
    } > ROM  

    .data : {
        *(.data)    /* 已初始化的全局变量 */
    } > RAM

    .bss : {
        *(.bss)     /* 未初始化的全局变量 */
    } > RAM
}
