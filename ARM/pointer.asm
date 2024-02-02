	.global point

point(int*, int*):
        mov     r3, #10
        stmfd   sp!, {r4, lr}
        str     r3, [r1, #0]
        mov     r0, #16
        bl      operator new[](unsigned int)
        mov     r4, r0
        mov     r0, #16
        bl      operator new[](unsigned int)
        ldr     r2, [r4, #0]
        str     r2, [r0, #0]
        ldr     r2, [r4, #4]
        str     r2, [r0, #4]
        bl      operator delete[](void*)
        ldr     r0, [r4, #0]
        ldmfd   sp!, {r4, pc}
