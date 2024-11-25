global _start

section .text

_start:
	mov rdi, 1
	mov rsi, msg
	mov rdx, 15
	mov rax, 1
	syscall

	mov rdi, 0
	mov rax, 60
	syscall

section .rodata
	msg: db "Hello, world!", 10

