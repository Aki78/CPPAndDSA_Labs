.global factorial

factorial:
    push {x0, lr}
    cmp x0, #1
    bgt else
    mov x0, #1
    add sp, sp, #8
    ret

else:
    sub x0, x0, #1
    bl factorial
    pop {x1, lr}
    mul x0, x1, x0
    ret
