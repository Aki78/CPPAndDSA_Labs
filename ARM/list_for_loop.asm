.global modify_array

modify_array:
    // x0 = buffer address, x1 = size

    mov x2, #0  // Initialize loop counter
    mov x5, #0  // Initialize sum register

loop:
    cmp x2, x1  // Compare counter with size
    bge end_loop

    lsl x3, x2, #2    // Calculate offset (x2 * 4 for int)
    ldr x4, [x0, x3]  // Load value from array
    add x4, x4, #10   // Add 10 to the value
    str x4, [x0, x3]  // Store the value back in the array

    add x5, x5, x4    // Add the value to the sum
    add x2, x2, #1    // Increment counter
    B loop

end_loop:
    mov x0, x5  // Move the sum into x0 for return
    ret


//as -o modify_array.o modify_array.s

