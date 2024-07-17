; Assume matA and matB are defined as 4x4 matrices
; matC will store the result

N EQU 4  ; Number of rows
M EQU 4  ; Number of columns
P EQU 4  ; Common dimension

.CODE
.STARTUP

XOR  AX, AX
XOR  BX, BX
XOR  CX, CX
XOR  DX, DX
XOR  SI, SI
XOR  DI, DI
XOR  BP, BP

MOV  CX, N
decN:
    PUSH CX
    PUSH BX
    MOV  CX, P
    decP:
        PUSH CX
        PUSH BP
        MOV  CX, M
        MOV  DI, 0
        decM:
            PUSH CX
            XOR  AH, AH
            MOV  AL, matA[BX][DI]
            PUSH BX
            MOV  BX, BP
            MOV  DL, matB[DI][BX]
            POP  BX
            IMUL DL
            MOV  SI, BP
            ADD  matC[BX][SI], AX
            INC  DI
            POP  CX
        LOOP decM
        INC  BP
        POP  CX
    LOOP decP
    INC  BX
    POP  CX
LOOP decN

; Exit code here

.EXIT
END
