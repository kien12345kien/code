
Duy
Nguyễn Duy
.global a
    1 1 1 1 1 1 1 1 
	2 2 2 2 2 2 2 2 
	3 3 3 3 3 3 3 3
	4 4 4 4 4 4 4 4 
	5 5 5 5 5 5 5 5    
	6 6 6 6 6 6 6 6
	7 7 7 7 7 7 7 7  
	8 8 8 8 8 8 8 8

.global b
    1 1 1 1 1 1 1 1 
	2 2 2 2 2 2 2 2 
	3 3 3 3 3 3 3 3
	4 4 4 4 4 4 4 4 
	5 5 5 5 5 5 5 5    
	6 6 6 6 6 6 6 6
	7 7 7 7 7 7 7 7  
	8 8 8 8 8 8 8 8

.data 0
.global c
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0
	0 0 0 0 0 0 0 0

.alias LEN 64
.alias N 8
.program 100

--for (row = 0, row<N, row++)
--  for (col=0, col<N, col ++)
--      fpr (k = 0, k<N, k++)
--          c[row*N+col] += a[ row * N + k] + b[k * N + col]
   SUB R1, 0 , 1
L1
   ADD R1,R1,1
   ...
   SUB R2, N , R1
   BRNZ R2,L1
c[row*N+col] += a[ row * N + k] + b[k * N + col]:
c_index = row * N + col
a_index = row *N + k
b_index = k*N + col
a' = a[a_index]
b' = b[b_index]
c' = a' * b'
c[cindex] = c'

 a = a[aindx]
 ADD tmp,a,a_index
 li a', (a)

 c[cindex] = c'
 add temp,c,cindex
 si (tmp), c'



.EXIT
    exit

.end