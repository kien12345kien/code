.data 96
.global a          
    1 2 3
.data 112
.global b
    1 2 3
.data 128
.global c
    0 0 0
.alias n  3

.program 100
    li R1, a
    li R2, b
    li R3, c
    li R8, n
.WEIGHTEDSUM
    li R4, (R1)
    li R5, (R2)
    
    mult R6, R5, R4
    add R7, R7, R6
    
    add R1, R1, 1
    add R2, R2, 1
    
    sub R8, R8, 1
    brnz R8, WEIGHTEDSUM
    li R4, (R1) ; Moved to delay slot

    ; Function name ReLU
    li R9, R7
    j ReLU_function
    li R5, (R2) ; Moved to delay slot

    st R7, (R3) ; Store the value R7 in memory at the address specified by R3
    
    exit
    
.ReLU_function
    ; R9 contains the value R7 to perform ReLU
    bz R9, ReLU_done
    li R4, (R1) ; Moved to delay slot
    li R7, 0 ; If R9 < 0 then assign R7 = 0
.ReLU_done
    ret
.end
