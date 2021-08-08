				global	_ft_list_size

				section	.text
_ft_list_size:
				xor		rax, rax
				mov		rdx, rdi
.loop:
				cmp		rdx, 0
				je		.fin
				mov		rdx, [rdx + 8]
				inc		rax
				jmp		.loop
.fin:
				ret
