			global  _ft_strcmp

			section	.text
_ft_strcmp:
			xor		rcx, rcx
.loop:
			mov		dl, byte[rdi + rcx]
			mov		al, byte[rsi + rcx]
			cmp		dl, 0
			je		.less
			inc		rcx
			cmp		dl, al
			je		.loop

.less:
			cmp		dl, al
			jge		.fin
			sub		al, dl
			movzx	rax, al
			neg		rax
			ret
.fin:
			sub		dl, al
			movzx	rax, dl
			ret
