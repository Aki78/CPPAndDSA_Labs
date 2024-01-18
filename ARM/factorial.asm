	.global factorial
factorial: 
	push {r0, lr} 
	cmp r0, #1 
	bgt else 
	mov r0, #1 
	add sp, sp, #8  // to ignore (undo) the last push because we got the return 1
	mov pc, lr 
else:
        sub r0, r0, #1 
	bl factorial 
	pop {r1, lr} 
	mul r0, r1, r0 
	mov pc, lr 
