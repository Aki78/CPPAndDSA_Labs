.global factorial

factorial:
    stp x29, x30, [sp, #-16]!  // Push x29 (Frame Pointer) and x30 (Link Register) to the stack
    mov x29, sp                // Set x29 to current stack pointer

    cmp x0, #1                 // Compare x0 with 1
    bgt else                   // If greater, branch to 'else' label

    mov x0, #1                 // Set x0 to 1 for factorial of 0 or 1
    ldp x29, x30, [sp], #16    // Pop x29 and x30 from the stack
    ret                        // Return

else:
    sub x0, x0, #1             // Subtract 1 from x0
    bl factorial               // Recursive call to factorial

    ldp x1, x30, [sp], #16     // Pop x1 (previous x0) and x30 (Link Register) from the stack
    mul x0, x1, x0             // Multiply x0 by x1 (previous x0)
    ret                        // Return

