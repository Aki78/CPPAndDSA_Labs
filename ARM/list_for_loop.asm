.global modify_array

modify_array:

    // x0 = buffer address, x1 = size

    mov x1, #0  // Initialize loop counter

loop:
    cmp x1, x2  // Compare counter with size
    bge end_loop

    lsl x3, x1, #2    // Calculate offset (x1 * 4 for int)
    ldr x4, [x0, x3]  // Load value from array
    add x4, x4, #10   // Add 10 to the value
    str x4, [x0, x3]  // Store the value back in the array

    add x1, x1, #1    // Increment counter
    B loop

end_loop:
    ret


;as -o modify_array.o modify_array.s

