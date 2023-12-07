.global to_upper

to_upper:
    // x0 = chars

    mov x1, #0  // Initialize sum register

loop:
    cmp x1, x0  // Compare counter with size
    bge end_loop

    ldrb w0, [x0, x1]  // load char to reg
    add x2, x2, #32   // Add 10 to the value
    strb w0, [x0, x1]  // Store the value back in the array then shift 4

    add x1, x1, #1    // Add the value to the sum
    B loop

end_loop:
    ret

//as -o to_upper.o to_upper.ams

