;bubble sort



.data 0

.global ARR             
    4 3 5 2 9 1



.alias LEN 6            


.program 100

    sub R0, (LEN), 1   


.WHILE                 
    li R1, ARR         



.FOR                    
    add R3, R1, 0       
    add R4, R3, 1       



    li R5, (R3)         
    li R6, (R4)



    sub R7, R5, R6     
    brn R7, NOSWAP



    si (R3), R6         
    si (R4), R5



.NOSWAP

    add R1, R1, 1       


    sub R2, R0, R1     
    brnz R2, FOR



    sub R0, R0, 1      
    brnz R0, WHILE      


.EXIT

    exit

.end