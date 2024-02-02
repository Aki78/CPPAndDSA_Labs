	.global blank
blank:
        str     fp, [sp, #-4]!
        add     fp, sp, #0
        add     sp, fp, #0
        ldmfd   sp!, {fp}
        bx      lr
