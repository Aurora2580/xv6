CC = riscv64-unknown-elf-gcc
AS = riscv64-unknown-elf-as
LD = riscv64-unknown-elf-ld

# Source files
SRC_ASM = kernel/boot.S
SRC_C = kernel/console.c kernel/uart_io.c

# Object files 
OBJ_ASM = $(SRC_ASM:.S=.o)
OBJ_C = $(SRC_C:.c=.o)

# Output files
OUTPUT = kernel/kernel.out

# Compiler flags
CFLAGS = -ffreestanding -c -g -fPIC # 不依赖系统，只编译不链接，生成调试信息、生成位置无关代码因为要自己指定内存布局
ASFLAGS = -g

# Linker script
LINKER_SCRIPT = kernel/linker.ld

# Build the output
all: $(OUTPUT)

# Linking
$(OUTPUT): $(OBJ_ASM) $(OBJ_C)
	$(LD) -o $@ $^ -T $(LINKER_SCRIPT)

# Compile assembly files
%.o: %.S
	$(AS) $(ASFLAGS) -o $@ $<

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

# Clean up generated files
clean:
	rm -f $(OBJ_ASM) $(OBJ_C) $(OUTPUT)

qemu: $(OUTPUT)
	qemu-system-riscv64 -machine virt -bios none -nographic -kernel $<

.PHONY: all clean qemu
