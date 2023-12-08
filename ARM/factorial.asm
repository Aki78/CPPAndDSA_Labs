    .global factorial

    // Function: factorial
    // Argument: w0 (32-bit integer)
    // Returns: w0 (32-bit integer)
factorial:
	push {r0, lr} 
	cmp r0, #1 
	bgt else 
	mov r0, #1 
	add sp, sp, #8 
	mov pc, lr 
else:
        sub r0, r0, #1 
	blt factorial 
	pop {r1, lr} 
	mul r0, r1, r0 
	mov pc, lr 
