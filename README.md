# Low Level C/C++

![banner](/docs/banner.jpg)

https://github.com/cesanta/mongoose
https://www.gnu.org/software/libmicrohttpd/
https://github.com/DaveGamble/cJSON
https://github.com/akheron/jansson

Check file type: Run file hello to confirm it is a 64-bit or 32-bit ELF executable.
Extract strings: Run strings hello to see readable text embedded in the binary—such as "hello world!" and names of linked library functions like puts or printf


https://abiexplorer.org
https://godbolt.org


if we do bitwise & (AND) of 1 to any integer 
    if answer is 0 then it is even number
    otherwise it is odd number.



Learning assembly language on Linux (Ubuntu) typically means learning **x86-64 assembly** using the standard system assembler tools.

---

### 1. Essential Tools Setup

Ubuntu uses the GNU toolchain (`gcc`, `as`, `ld`) and optionally `nasm` (Netwide Assembler), which uses the widely preferred Intel syntax instead of AT&T syntax.

Install the essentials:

```bash
sudo apt update
sudo apt install build-essential nasm gdb

```

* **NASM:** The assembler that turns `.asm` source files into object files (`.o`).
* **LD / GCC:** Linkers that turn object files into executable binaries.
* **GDB:** The debugger used to step through assembly instructions and inspect CPU registers.

---

### 2. Core Concepts: Registers and Memory

Assembly provides direct control over the CPU's internal storage slots, called **registers**, which hold 64-bit values:

* **General Purpose:** `rax`, `rbx`, `rcx`, `rdx`, `rsi`, `rdi`, `rbp`, `rsp`, `r8`–`r15`.
* **Sub-registers:** You can access smaller portions of a 64-bit register:
* `rax` (64-bit) $\rightarrow$ `eax` (lower 32-bit) $\rightarrow$ `ax` (lower 16-bit) $\rightarrow$ `al` (lower 8-bit).


* **Stack Pointer:** `rsp` points to the top of the runtime call stack.
* **Instruction Pointer:** `rip` points to the next instruction to execute.

---

### 3. Basic Instruction Set

In NASM (Intel syntax), instructions follow the format: `instruction destination, source`

* `mov rax, 42` — Copies the value `42` into register `rax`.
* `mov rbx, rax` — Copies the value inside `rax` into `rbx`.
* `add rax, 5` — Adds `5` to `rax` (`rax = rax + 5`).
* `sub rax, 2` — Subtracts `2` from `rax` (`rax = rax - 2`).
* `inc rax` / `dec rax` — Increments or decrements `rax` by 1.
* `cmp rax, rbx` — Compares two values by internally subtracting them and setting CPU condition flags (Zero Flag, Sign Flag, etc.).
* `jmp label` — Jumps unconditionally to a code label.
* `je label` / `jne label` — Jump if equal / Jump if not equal (based on previous `cmp`).

---

### 4. Linux x86-64 System Calls (Syscalls)

In user-space Linux, programs interact with the kernel (e.g., printing to screen, opening files, exiting) via the `syscall` instruction.

Parameters are passed via specific registers in this exact order:

| Register | Role in Syscall |
| --- | --- |
| `rax` | Syscall number (`1` for `sys_write`, `60` for `sys_exit`) |
| `rdi` | 1st argument (e.g., file descriptor: `1` for stdout) |
| `rsi` | 2nd argument (e.g., pointer to buffer/string) |
| `rdx` | 3rd argument (e.g., count/length in bytes) |

---

### 5. Writing "Hello, World!"

Create a file named `hello.asm`:

```nasm
section .data
    msg db "Hello, Ubuntu!", 0xA    ; 0xA is the newline character ('\n')
    len equ $ - msg                 ; Calculate the length of the string

section .text
    global _start

_start:
    ; sys_write(stdout, msg, len)
    mov rax, 1          ; syscall number for sys_write
    mov rdi, 1          ; file descriptor 1 is stdout
    mov rsi, msg        ; pointer to string memory
    mov rdx, len        ; byte count
    syscall             ; invoke kernel

    ; sys_exit(0)
    mov rax, 60         ; syscall number for sys_exit
    xor rdi, rdi        ; exit code 0 (xor rdi, rdi sets rdi to 0 faster than mov)
    syscall

```

---

### 6. Assembling, Linking, and Running

Run these commands in your Ubuntu terminal:

```bash
# 1. Assemble NASM source to a 64-bit ELF object file
nasm -f elf64 hello.asm -o hello.o

# 2. Link the object file into an executable binary
ld hello.o -o hello

# 3. Execute the binary
./hello

```

---

### 7. Inspecting Execution with GDB

To see what the CPU does line-by-line:

```bash
# Assemble with debug symbols (-g)
nasm -f elf64 -g -F dwarf hello.asm -o hello.o
ld hello.o -o hello

# Launch GDB
gdb -q ./hello

```

Inside GDB, use these basic commands:

* `layout asm` — Opens the disassembly view.
* `layout regs` — Opens the live register viewer above the code.
* `break _start` — Sets a breakpoint at the program entry.
* `run` — Starts execution.
* `stepi` (or `si`) — Executes a single CPU instruction.
* `quit` — Exits GDB.


https://gemini.google.com/app/9328669cdee09c1c