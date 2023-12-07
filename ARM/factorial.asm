    .global factorial

    // Function: factorial
    // Argument: w0 (32-bit integer)
    // Returns: w0 (32-bit integer)
factorial:
    // Save LR and FP (Link Register and Frame Pointer)
    stp x29, x30, [sp, #-16]!
    mov x29, sp

    // Base case: if the input is less than 2, return 1
    cmp w0, #2
    b.lt end_factorial

    // Prepare for recursive call: decrement the input
    sub w0, w0, #1

    // Recursive call
    bl factorial

    // Restore the original input value (now in w1)
    add w1, w0, #1

    // Multiply the result of the recursive call with the original input value
    mul w0, w0, w1

    // Restore FP and LR, and return
    ldp x29, x30, [sp], #16
    ret

end_factorial:
    // For base case, return 1
    mov w0, #1

    // Restore FP and LR, and return
    ldp x29, x30, [sp], #16
    ret

