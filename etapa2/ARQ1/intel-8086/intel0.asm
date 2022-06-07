        .model  small
        .stack  
		.data
;data
            BufferTec	    db	    100 dup (?)
            FileName		db		15 dup (?)		; Nome do arquivo a ser lido
            FileBuffer		db		10 dup (?)		; Buffer de leitura do arquivo
            FileHandle		dw		0				; Handler do arquivo
            FileHandleOut   dw      0
            FileNameBuffer	db		15 dup (?)
            FileNameOutput  db      15 dup (?)
            FileIndex       dw      0
            FileIndexKb     dw      0
            FileIndexOut    dw      0
            FileSize        dw      0
            FileSizeKb      dw      0
            FileNameSize    dw      0
            WriteBuffer     dw      13 dup (0)
            bufferSum       db      0
            SumIndex        dw      0
            SumMod4         dw      0
            IndexOutMod4    dw      0
            Output          db      4 dup (0)
            LineBreak       db      0dh, 0ah, 0
            space           db      ' ', 0
            MSGArqSaida     db      "Arquivo de saida: ", 0
            MSGArqEntrada   db      "Arquivo de entrada: ", 0
            MsgErroOpenOut  db      0dh, 0ah, "Erro ao abrir arquivo de saida", 0
            MsgErroWrtOut   db      0dh, 0ah, "Erro ao escrever no arquivo de saida", 0
            MsgErro128kb    db      0dh, 0ah, "Arquivo maior do que 128 kBytes", 0
            MsgErroName     db      0dh, 0ah, "Nome de arquivo invalido", 0
            MsgSoma         db      "Soma: ", 0
            MsgBytes        db      "Bytes: ", 0
            msgkb           db      "kB", 0
            msgb            db      "B", 0
            decBytes        db      13 dup (0)
            decKBytes       db      13 dup (0)
            ext_size        dw      0
            Hello           db      0dh, 0ah, "Hello", 0dh, 0ah
            sw_m            dw      0
            sw_n            dw      0
            sw_f            db      0
            bufferW1        db      13 dup (0)
            b               dw      0
;data
        .code

ReadString	proc	near

		;Pos = 0
		mov		dx,0

    RDSTR_1:
		;while(1) {
		;	al = Int21(7)		// Espera pelo teclado
		mov		ah,7
		int		21H

		;	if (al==CR) {
		cmp		al,0DH
		jne		RDSTR_A

		;		*S = '\0'
		mov		byte ptr[bx],0

		;		return
		ret
		;	}

    RDSTR_A:
		;	if (al==BS) {
		cmp		al,08H
		jne		RDSTR_B

		;		if (Pos==0) continue;
		cmp		dx,0
		jz		RDSTR_1

		;		Print (BS, SPACE, BS)
		push	dx
		
		mov		dl,08H
		mov		ah,2
		int		21H
		
		mov		dl,' '
		mov		ah,2
		int		21H
		
		mov		dl,08H
		mov		ah,2
		int		21H
		
		pop		dx

		;		--s
		dec		bx
		;		++M
		inc		cx
		;		--Pos
		dec		dx
		
		;	}
		jmp		RDSTR_1

    RDSTR_B:
		;	if (M==0) continue
		cmp		cx,0
		je		RDSTR_1

		;	if (al>=SPACE) {
		cmp		al,' '
		jl		RDSTR_1

		;		*S = al
		mov		[bx],al

		;		++S
		inc		bx
		;		--M
		dec		cx
		;		++Pos
		inc		dx

		;		Int21 (s, AL)
		push	dx
		mov		dl,al
		mov		ah,2
		int		21H
		pop		dx

		;	}
		;}
		jmp		RDSTR_1

ReadString	endp

printf_s	proc	near

    ;	While (*s!='\0') {
        mov		dl,[bx]
        cmp		dl,0
        je		ps_1

    ;		putchar(*s)
        push	bx
        mov		ah,2
        int		21H
        pop		bx

    ;		++s;
        inc		bx
            
    ;	}
        jmp		printf_s
            
    ps_1:
        ret
	
printf_s	endp

GetFileName	proc	near

        ;	// Lê uma linha do teclado
        ;	FileNameBuffer[0]=100;
        ;	gets(ah=0x0A, dx=&FileNameBuffer)
        mov		ah,0ah
        lea		dx,FileNameBuffer
        mov		byte ptr FileNameBuffer,100
        int		21h

        ;	// Copia do buffer de teclado para o FileName
        ;	for (char *s=FileNameBuffer+2, char *d=FileName, cx=FileNameBuffer[1]; cx!=0; s++,d++,cx--)
        ;		*d = *s;		
        lea		si,FileNameBuffer+2
        lea		di,FileName
        mov		cl,FileNameBuffer+1
        mov		ch,0
        mov		ax,ds						; Ajusta ES=DS para poder usar o MOVSB
        mov		es,ax
        rep 	movsb
        ;	// Coloca o '\0' no final do string
        ;	*d = '\0';
        mov		byte ptr es:[di],0

        
    end_getName:

        ret
GetFileName	endp

FileOpen    proc    near
        ;	GetFileName();
        call	GetFileName

        ;	if ( (ax=fopen(ah=0x3d, dx->FileName) ) ) {
        ;		printf("Erro na abertura do arquivo.\r\n");
        ;		exit(1);
        ;	}
        lea     si, FileName
        lea     di, FileNameOutput
        mov     cx, 15
        rep     movsb


        lea     bx, FileNameOutput
        call    calc_str_size
        mov     fileNameSize, bx
        
        lea     bx, FileNameOutput        
        call    change_file_ext 
            
        mov     bx, fileNameSize
        sub     bx, ext_size
        dec     bx
        cmp     bx, 8
        jg      invalid_name_file

        call    openOutput

        mov		al,0
        lea		dx,FileName
        mov		ah,3dh
        int		21h
        jnc		FileOpen1
        
        .exit	1
        
    FileOpen1:

        

        ;	FileHandle = ax
        mov		FileHandle,ax		; Salva handle do arquivo

        ;	while(1) {
    FileOpen2:
        ;		if ( (ax=fread(ah=0x3f, bx=FileHandle, cx=1, dx=FileBuffer)) ) {
        ;			printf ("Erro na leitura do arquivo.\r\n");
        ;			fclose(bx=FileHandle)
        ;			exit(1);
        ;		}
        mov		bx,FileHandle
        mov		ah,3fh
        mov		cx,1
        lea		dx,FileBuffer
        int		21h
        jnc		FileOpen3
        
        mov		al,1
        jmp		CloseAndFinal

    FileOpen3:
        ;		if (ax==0) {
        ;			fclose(bx=FileHandle);
        ;			exit(0);
        ;		}
        cmp		ax,0
        jne		FileOpen4

        mov		al,0
        jmp		CloseAndFinal

    FileOpen4:
        ;		inputRead[i] = FileBuffer; i++;	// Coloca um caractere no vetor
        
        mov     al, FileBuffer
        cmp     al, 7Eh
        jg		FileOpen2

    SumAscii1:

        mov     ah, 0

        mov     bufferSum, al
        
        call    IntToHex
        mov     bx, 0
        lea     di, WriteBuffer
        mov     [di+bx], ah
        inc     bx
        mov     [di+bx], al
        
        mov     bx, FileHandleOut
        mov     cx, 2
        lea     dx, WriteBuffer
        mov     ah, 40h
        int     21H
        jc      error_write

        mov     bx,SumMod4
        lea     di,Output                       ;   Output[SumIndex % 4] = al
        mov     al, bufferSum
        add     [di+bx],al

        inc     SumIndex                        ;   SumIndex ++
        inc     SumMod4 
        inc     IndexOutMod4
        
        cmp     SumMod4, 4                      ;   if SumMod4 == 4: 
        jne     SumAscii2                       ;       SumMod4 = 0
        
        mov     SumMod4, 0

    SumAscii2:

        cmp     IndexOutMod4, 4
        jne     SumAscii3

        mov     IndexOutMod4, 0
        mov     ah, 0
        mov     bx, 0
        lea     di, WriteBuffer
        mov     [di+bx], 0DH
        inc     bx
        mov     [di+bx], 0AH
        mov     bx, FileHandleOut
        mov     cx, 2
        lea     dx, WriteBuffer
        mov     ah, 40h
        int     21H
        jc      error_write

    SumAscii3:        
        inc     FileIndex
        cmp     FileIndex, 1024
        jne     SumAscii4
        inc     FileIndexKb
        cmp     FileIndexKb, 128
        je      error_greater_than_128



        mov     FileIndex, 0
        ;	}

    SumAscii4:
        jmp		FileOpen2

    CloseAndFinal:
        mov     ax, FileIndex
        mov     FileSize, ax
        mov     ax, FileIndexKb
        mov     FileSizeKb, ax
        mov		bx,FileHandle		; Fecha o arquivo
        mov		ah,3eh
        int		21h

    Final:
        ret

FileOpen    endp

calc_str_size       proc    near
        ; bx -> string (input)
        ; bx -> size (output)

        mov     di, bx
        mov     bx, 0
    loop_calc_size:
        cmp     [bx+di], 0
        je      size_found
        inc     bx
        jmp     loop_calc_size

    size_found:
        ret
calc_str_size       endp

change_file_ext     proc    near
        ; ax -> output string
        ; bx -> source string effective address, ended with 0
        ; cx -> string size
        
        push    bx
        push    cx
        call    size_of_file_ext
        
        pop     cx
        pop     bx

        mov     di, bx

        cmp     ext_size, 0FFFFH
        je      file_whout_ext

        cmp     ext_size, 3
        jg      invalid_name_file

        cmp     ext_size, 0
        je      invalid_name_file
        
        
    txt:

        mov     bx, FileNameSize
        sub     bx, ext_size
        dec     bx
        mov     [bx+di], '.'
        inc     bx
        mov     [bx+di], 'r'
        inc     bx
        mov     [bx+di], 'e'
        inc     bx
        mov     [bx+di], 's'
        inc     bx
        mov     [bx+di], 0
        inc     bx
        jmp     end_putres

    file_whout_ext:

        mov     bx, FileNameSize
        mov     [bx+di], '.'
        inc     bx
        mov     [bx+di], 'r'
        inc     bx
        mov     [bx+di], 'e'
        inc     bx
        mov     [bx+di], 's'
        inc     bx
        mov     [bx+di], 0
        inc     bx

    end_putres:
        ret

    

change_file_ext     endp

size_of_file_ext    proc    near
        ; INPUT
        ; bx -> source string address
        ; cx -> string size including '\0'

        ; OUTPUT
        ; cx -> size of extension

        push    ax

        lea     di, FileNameOutput
        mov     bx, FileNameSize
        
        dec     bx
        mov     ax, 0
    size_ext_1:
        mov     cl, [bx+di]

        cmp     cl, '.'
        je      dot_found
        dec     bx
        inc     ax

        cmp     bx, 0
        jne     size_ext_1

        mov     ax, 0FFFFH

    dot_found:
        mov     ext_size, ax

        lea     bx, LineBreak 
        call    printf_s

        pop     ax
        ret 
size_of_file_ext    endp

invalid_name_file:
    
        lea     bx, MsgErroName
        call    printf_s
        .exit   1
;invalid_name_file

IntToHex   proc    near
        push    cx
        mov     cl, 4

        shl     ax, cl
        shr     al, cl

        cmp     ah, 9
        jle     numberAh
        add     ah, 55
        jmp     nextAl
    numberAh:
        add     ah, 48
    nextAl:
        cmp     al, 9
        jle     numberAl
        add     al, 55
        jmp     endIntToHex
    numberAl:
        add     al, 48
    endIntToHex:
        pop     cx
        ret
IntToHex    endp

hexPrint    proc    near
        
        push    bx

        call    IntToHex
        mov     bx, ax

        mov     ah, 2
        mov     dl, bh
        int     21h

        mov     ah, 2
        mov     dl, bl
        int     21h

        pop     bx

        ret

hexPrint    endp    

openOutput  proc    near

        mov     ah, 3ch
        mov     cx, 0
        lea     dx, FileNameOutput
        int     21h
        jnc     not_error_open
        lea     bx, MsgErroOpenOut
        call    printf_s
        .exit   1

    not_error_open:
        mov     FileHandleOut, ax
        ret
openOutput  endp

fileBreakLine proc  near
        mov     IndexOutMod4, 0
        mov     ah, 0
        mov     bx, 0
        lea     di, WriteBuffer
        mov     [di+bx], 0DH
        inc     bx
        mov     [di+bx], 0AH
        mov     bx, FileHandleOut
        mov     cx, 2
        lea     dx, WriteBuffer
        mov     ah, 40h
        int     21H
        jc      error_write

        ret
fileBreakLine endp

writeBufferFile proc    near

        mov     bx, FileHandleOut
        mov     cx, 2
        lea     dx, WriteBuffer
        mov     ah, 40h
        int     21H
        inc     IndexOutMod4

        ret
writeBufferFile endp

printBytes      proc    near

        lea     bx, LineBreak
        call    printf_s
        lea     bx, MsgBytes
        call    printf_s

        mov     ax, FileSizeKb
        lea     bx, decKBytes
        call    sprintf_w

        lea     bx, decKBytes
        call    printf_s
        lea     bx, msgkb
        call    printf_s

        lea     bx, space
        call    printf_s

        mov     ax, FileSize
        lea     bx, decBytes
        call    sprintf_w

        lea     bx, decBytes
        call    printf_s
        lea     bx, msgb
        call    printf_s

        
        ret
printBytes      endp

sprintf_w	proc	near

    ;void sprintf_w(char *string, WORD n) {
        mov		sw_n,ax

    ;	k=5;
        mov		cx,5
        
    ;	m=10000;
        mov		sw_m, 10000
        
    ;	f=0;
        mov		sw_f,0
        
    ;	do {
    sw_do:

    ;		quociente = n / m : resto = n % m;	// Usar instru��o DIV
        mov		dx,0
        mov		ax,sw_n
        div		sw_m
        
    ;		if (quociente || f) {
    ;			*string++ = quociente+'0'
    ;			f = 1;
    ;		}
        cmp		al,0
        jne		sw_store
        cmp		sw_f,0
        je		sw_continue
    sw_store:
        add		al,'0'
        mov		[bx],al
        inc		bx
        
        mov		sw_f,1
    sw_continue:
        
    ;		n = resto;
        mov		sw_n,dx
        
    ;		m = m/10;
        mov		dx,0
        mov		ax,sw_m
        mov		bp,10
        div		bp
        mov		sw_m,ax
        
    ;		--k;
        dec		cx
        
    ;	} while(k);
        cmp		cx,0
        jnz		sw_do

    ;	if (!f)
    ;		*string++ = '0';
        cmp		sw_f,0
        jnz		sw_continua2
        mov		[bx],'0'
        inc		bx
    sw_continua2:


    ;	*string = '\0';
        mov		byte ptr[bx],0
            
    ;}
        ret
            
sprintf_w	endp

error_write:
        lea     bx, MsgErroWrtOut
        call    printf_s
        .exit   1
;error_write   

error_greater_than_128:
        lea     bx, MsgErro128kb
        call    printf_s
        .exit   1
;error_greater_than_128

.startup

        lea     bx, MSGArqEntrada
        call    printf_s

        call    FileOpen

        

        

        lea     bx, LineBreak
        call    printf_s
        lea     bx, MSGArqSaida
        call    printf_s
        lea     bx, FileNameOutput
        call    printf_s
        lea     bx, LineBreak
        call    printf_s

        

        lea     bx, LineBreak
        call    printf_s
        lea     bx, MsgSoma
        call    printf_s

        mov     bx, 0
    print:
        lea     di, Output
        mov     ah, 0
        mov     al, [di+bx]

        push    ax
        call    hexPrint
        pop     ax
        
        push    bx

        call    IntToHex
        mov     bx, 0
        lea     di, WriteBuffer
        mov     [di+bx], '0'
        inc     bx
        mov     [di+bx], ah
        push    ax
        
        call    writeBufferFile

        cmp     IndexOutMod4, 4
        jne     print_1
        
        call    fileBreakLine

    print_1:
        
        mov     bx, 0
        lea     di, WriteBuffer
        mov     [di+bx], '0'
        inc     bx
        pop     ax
        mov     [di+bx], al
        
        call    writeBufferFile

        cmp     IndexOutMod4, 4
        jne     print_2
        
        call    fileBreakLine

    print_2:
        lea     bx, space
        call    printf_s
        pop     bx

        inc     bx
        cmp     bx, 4
        jne     print

        

    endApp:
        
        call    printBytes
        lea     bx, LineBreak
        call    printf_s
        
        mov     bx, FileHandle
        mov     ah, 3eh
        int     21H

        mov     bx, FileHandleOut
        mov     ah, 3eh
        int     21H
        
.exit
end

