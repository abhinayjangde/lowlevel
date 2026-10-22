section .data
    msg db "Hello, Ubuntu!", 0xA
    len equ $ - msg

section .text
    global _start

_start:
    ; sys_write(stdout, msg, len)
    mov rax, 1
    mov rdi, 1
    mov rsi, msg
    mov rdx, len
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall