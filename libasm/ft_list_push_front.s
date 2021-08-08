						global	_ft_list_push_front
						extern	_malloc

						section	.text
_ft_list_push_front:
						push	rcx
						push	rdi
						mov		rdi, 16d
						push	rsi
						call	_malloc
						pop		rsi
						pop		rdi
						pop		rcx
						cmp		rax, 0
						je		.fin
						mov		[rax], rsi
						mov		rdx, qword [rdi]
						mov		[rax + 8], rdx
						mov		[rdi], rax
.fin:
						ret
