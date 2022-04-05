.MODEL  small 
.STACK  1024
.DATA   

var1        dw  5
var2        dw  ?                           ;Cria uma variavel nao inicializada
string      db  'Hello, world!'             ;cria uma string
size        equ $-string                    ;cria uma variavel com o tamanho da string
vector1     dw  5    dup(0)                 ;Inicializa um vetor de 5 variaveis iguais a 0
vector2     dw  5    dup(?)                 ;Cria um vetor de 5 variaveis nao inicializadas

.CODE   
.STARTUP 

                mov     var2, 10
    while:
                call    frase
                dec     var2
                jnz     while

.EXIT   0

frase       proc near

            mov     bx, 0001H
            lea     dx, string
            mov     cx, size
            mov     ah, 40H
            int     21H
            ret

frase       endp

END