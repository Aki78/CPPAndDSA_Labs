.global to_upper

to_upper:
    // x0 = pointer to chars

    mov x1, #0  // Initialize index register

loop:
    ldrb w2 , [x0, x1]  // Load byte from [x0 + x1] into w2 
    cmp w2 , #0         // Check if the byte is null terminator
    beq end_loop       // If it is null terminator, exit loop

    cmp w2 , #97        // Check if the character is 'a' or higher
    blt skip           // If lower, skip conversion
    cmp w2 , #122       // Check if the character is 'z' or lower
    bgt skip           // If higher, skip conversion

    sub w2 , w2 , #32    // Convert to uppercase by subtracting 32
    strb w2 , [x0, x1]  // Store the updated character back

skip:
    add x1, x1, #1    // Increment the index
    b loop            // Repeat the loop

end_loop:
    ret

