; reassembly of "GccBoardProject1.hex"
; created by ReAVR V3.4.0
; at 2017/03/04 - 13:23:50
; for Atmel AVR assembler
;---------------------------------------
; AVR_TYPE=<unknown>
; FLASH_SIZE=8KB
; SRAM_START=0x60
;---------------------------------------
	.cseg
	.org	0x0000
;---------------------------------------
; byte constants:
;
.equ	k00	= 0x00	;
.equ	k01	= 0x01	;
.equ	k02	= 0x02	;
.equ	k04	= 0x04	;
.equ	k07	= 0x07	;
.equ	k38	= 0x38	; '8'
.equ	k5F	= 0x5F	; '_'
.equ	k7B	= 0x7B	; '{'
.equ	k7F	= 0x7F	; ''
.equ	kFF	= 0xFF	; 'ÿ'
;
; io register addresses:
;
.equ	p10	= 0x10
.equ	p11	= 0x11
.equ	p12	= 0x12
.equ	p14	= 0x14
.equ	p15	= 0x15
.equ	p3D	= 0x3D
.equ	p3E	= 0x3E
.equ	p3F	= 0x3F
;
; bit numbers:
;
.equ	b0	= 0x00
.equ	b1	= 0x01
.equ	b2	= 0x02
.equ	b3	= 0x03
.equ	b4	= 0x04
.equ	b5	= 0x05
.equ	b6	= 0x06
.equ	b7	= 0x07
;---------------------------------------
;
L0000:
	rjmp	_reset	; L002A
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
	rjmp	L0032
;	-----------	jump on last line
	nop
;
_reset:
; L002A:
	clr	r1
	out	p3F,r1
	ldi	r28,k5F
	ldi	r29,k04
	out	p3E,r29
	out	p3D,r28
	 rcall	L0033
	rjmp	L005B
;	-----------	jump on last line
L0032:
	rjmp	L0000
;	-----------	jump on last line
L0033:
	ldi	r24,kFF
	out	p14,r24
	out	p15,r1
	out	p11,r1
	out	p12,r24
	ldi	r24,k7B
	ldi	r25,k00
	ldi	r18,k02
	ldi	r19,k01
L003C:
;	--------- this is skippy
	 sbic	p10,b0
	 rjmp	L004E
;	--------- last may be skipped
; pc=0x3E(0x7C)
;
	ldi	r20,k7F
	ldi	r21,k38
	ldi	r22,k01
L0041:
	subi	r20,k01
	sbci	r21,k00
	sbci	r22,k00
	 brne	L0041
;	-----		branch on last line
	rjmp	L0046
;	-----------	jump on last line
L0046:
	nop
	adiw	r24,k07
;	--------- this is skippy
	 sbrc	r24,b0
	 rjmp	L003C
;	--------- last may be skipped
; pc=0x4A(0x94)
;
;	--------- this is skippy
	 sbic	p10,b0
	 rjmp	L003C
;	--------- last may be skipped
; pc=0x4C(0x98)
;
	out	p15,r19
	rjmp	L003C
;	-----------	jump on last line
L004E:
	ldi	r20,k7F
	ldi	r21,k38
	ldi	r22,k01
L0051:
	subi	r20,k01
	sbci	r21,k00
	sbci	r22,k00
	 brne	L0051
;	-----		branch on last line
	rjmp	L0056
;	-----------	jump on last line
L0056:
	nop
;	--------- this is skippy
	 sbis	p10,b0
	 rjmp	L003C
;	--------- last may be skipped
; pc=0x59(0xB2)
;
	out	p15,r18
	rjmp	L003C
;	-----------	jump on last line
L005B:
	cli
L005C:
	rjmp	L005C
;	-----------	jump on last line
; pc=0x5D(0xBA)
;
; last flash byte address = 0x00B9
; last flash word address = 0x005C
;---------------------------------------
; Code not seems to use any RAM.
;---------------------------------------
;<eof>
