.data 96
.global a          
    1 2 3
.global b
    1 2 3

.data 112
.global c
    0 
.global n  3

.program 100
    li R1, a
    li R2, b
    li R3, c

.WEIGHTEDSUM
    li R4, (R1)
    li R5, (R2)
    add R9, R3, c 
    mult R6, R5, R4
    add R7, R7, R6

    add R1, R1, 1
    add R2, R2, 1

    sub R8, R8, 1
    brnz R8, WEIGHTEDSUM
    si (R3), R7
    
    exit
.end