			global  _ft_strcpy

			section	.text
_ft_strcpy:
			xor		rax, rax
.loop:
			mov		dl, byte[rsi + rax]
			mov		byte[rdi + rax], dl
			cmp		dl, 0
			je		.fin
			inc		rax
			jmp		.loop
.fin:
			mov		rax, rdi
			ret
