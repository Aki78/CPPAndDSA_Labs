.global modify_array

modify_array:
    // x0 = buffer address, x1 = size

    add x2, x0, x1  // Initialize loop counter
    mov x5, #0  // Initialize sum register

loop:
    cmp x0, x2  // Compare counter with size
    bge end_loop

    ldr x4, [x0]  // Load value from array
    add x4, x4, #10   // Add 10 to the value
    str x4, [x0], #4  // Store the value back in the array then shift 4

    add x5, x5, x4    // Add the value to the sum
    B loop

end_loop:
    mov x0, x5  // Move the sum into x0 for return
    ret

//as -o modify_array.o modify_array.s

