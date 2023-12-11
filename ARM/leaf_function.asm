    .global f1
f1:
	push {r4, r5,r6, lr} 
	add r5, r0, r1 
	sub r12, r0, r1 
	mul r6, r5, r12
	mov r4, #0
for:
	cmp r4, r0
	bge return
	push {r0, r1}
	add r0, r1, r4
	bl f2
	add r6, r6, r0
	pop {r0, r1}
	add r4, r4, #1
	b for
return:
	mov r0, r6
	pop {r4, r5, r6, lr}
	mov pc, lr
f2:
	push {r4}
	add r4, r0, #5
	add r0, r4, r0
	pop {r4}
	mov pc, lr
