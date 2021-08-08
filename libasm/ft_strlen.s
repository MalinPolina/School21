			global _ft_strlen

			section	.text
_ft_strlen:
			xor		rax, rax
.loop:
			cmp		byte [rdi + rax], 0
			je		.fin
			inc		rax
			jmp		.loop
.fin:
			ret
