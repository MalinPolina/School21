			global	_ft_strdup
			extern	_malloc
			extern	_ft_strlen
			extern	_ft_strcpy

			section	.text
_ft_strdup:
			xor		rax, rax
			call	_ft_strlen
			inc		rax
			push	rdi
			mov		rdi, rax
			call	_malloc
			pop		rsi
			cmp		rax, 0
			je		.fin
			mov		rdi, rax
			call	_ft_strcpy
.fin:
			ret
