	.global exercize

exercize: 
    push { r4, lr }  // we need to save return address because we call another subroutine

    mov r4, r0
    //mov r1, #0

    //str r1, [r0]
    ldrb r0, [r0]

repeat:
    cmp r0, #0
    beq end



    cmp r0, #0x41 //A
    blt notUpper
    cmp r0, #0x5a //Z
    bgt notUpper
    mov r6, #0x41
    sub r7, r0, r6
    mov r6, #13
    add r0, r7, r6
    mov r1, #26

    bl __aeabi_idiv //pretty sure this divides r0 by r1 and stores the result in r0

    mul r2, r0, r7
    sub r0, r7, r2
    add r0, r0, r7



notUpper:

    bl putchar
    add r4, r4, #1
    ldrb r0, [r4]
    b repeat

end:

