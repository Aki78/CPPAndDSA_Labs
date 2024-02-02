	.global blank2
blank2:
        str     fp, [sp, #-4]!
        add     fp, sp, #0
    //    sub     sp, sp, #20
        mov     r3, #1
        str     r3, [fp, #-8]
        mov     r3, #2
        str     r3, [fp, #-12]
        ldr     r2, [fp, #-8]
        ldr     r3, [fp, #-12]
        add     r3, r2, r3
        str     r3, [fp, #-16]
        ldr     r3, [fp, #-16]
        mov     r0, r3
        add     sp, fp, #0
        ldmfd   sp!, {fp}
        bx      lr
