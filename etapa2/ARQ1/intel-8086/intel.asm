        .model  small
        .stack
		.data
    BufferTec	db	100 dup (?)
    FileName		db		15 dup (?)		; Nome do arquivo a ser lido
    FileBuffer		db		10 dup (?)		; Buffer de leitura do arquivo
    FileHandle		dw		0				; Handler do arquivo
    FileNameBuffer	db		15 dup (?)
    FileNameOutput  db      15 dup (?)
    FileIndex       dw      0
    FileSize        dw      0
    FileNameSize    dw      0
    InputRead       db      256 dup (0)
    SumIndex        dw      0
    SumMod4         dw      0
    Output          db      4 dup (0)
    Message         db      0dh, 0ah, 0dh, 0ah, 0
    

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
        lea     di, InputRead
        mov     al, FileBuffer
        mov     bx, FileIndex
        mov     [di+bx], al 

        
        inc     FileIndex
        
        ;	}
        jmp		FileOpen2

    CloseAndFinal:
        mov     ax, FileIndex
        mov     FileSize, ax
        mov		bx,FileHandle		; Fecha o arquivo
        mov		ah,3eh
        int		21h

    Final:
        ret

FileOpen    endp


SumAscii    proc    near

    SumAscii1:
        
        mov     bx,SumIndex                     ;   al = InputRead[SumIndex]
        lea     di,InputRead
        mov     al,[di+bx]
        
        mov     bx,SumMod4
        lea     di,Output                       ;   Output[SumIndex % 4] = al
        add     [di+bx],al

        inc     SumIndex                        ;   SumIndex ++
        inc     SumMod4 

        cmp     SumMod4, 4                      ;   if SumMod4 == 4: 
        jne     SumAscii2                       ;       SumMod4 = 0
        
        mov     SumMod4, 0

    SumAscii2:

        mov     ax, FileSize                    ;   if SumIndex == FileIndex:
        cmp     SumIndex, ax                    ;       break
        jne     SumAscii1

    SumAsciiEnd:    
        ret

SumAscii    endp   

putRes      proc    near

        lea     di, FileNameOutput
        mov     bx, 0
        mov     FileNameSize, 0 
    loop_putRes:
        mov     ax, [bx+di]
        
        inc     FileNameSize
        inc     bx
        cmp     ax, 0
        je      size_set
        
        jmp     loop_putRes

    size_set:
        lea     di, FileNameOutput
        mov     bx, FileNameSize
        sub     bx, 4
        cmp     [bx+di], '.'
        jne     not_txt
        inc     bx
        cmp     [bx+di], 't'
        jne     not_txt
        inc     bx
        cmp     [bx+di], 'x'
        jne     not_txt
        inc     bx
        cmp     [bx+di], 't'
        jne     not_txt
        
        jmp     txt

    txt:

        mov     bx, FileNameSize
        sub     bx, 1
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

    not_txt:

        mov     bx, FileNameSize
        sub     bx, 5
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
putRes      endp

    .startup
        call    FileOpen
        call    SumAscii

        lea     si, FileName
        lea     di, FileNameOutput
        mov     cx, 15
        rep     movsb
        call    putRes

        lea     bx, Message
        call    printf_s

        lea     bx, FileNameOutput
        call    printf_s

    print:
        lea     di, Output
        mov     dl, [di]
        mov     dh, [di+1]
        mov     bl, [di+2]
        mov     bh, [di+3]

    .exit
    end

