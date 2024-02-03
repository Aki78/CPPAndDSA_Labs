	.global div_mod

div_mod:
    push    {r3, r4, lr}
    
    mov     r2, r0       
    mov     r3, r1    

    
    mov     r4, #0          
    mov     r1, #0          
    
division_loop:
    
    cmp     r2, r3
    blt     division_done   

    
    sub     r2, r2, r3      
    add     r4, r4, #1      
    
    b       division_loop

division_done:
    
    mov     r0, r2          
    mov     r1, r4          
    
    pop     {r3, r4, pc}
