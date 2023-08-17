	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 13, 0	sdk_version 13, 3
	.globl	_avg                            ; -- Begin function avg
	.p2align	2
_avg:                                   ; @avg
	.cfi_startproc
; %bb.0:
	sub	sp, sp, #48
	.cfi_def_cfa_offset 48
	str	x0, [sp, #32]
	str	w1, [sp, #28]
	str	w2, [sp, #24]
	ldr	w8, [sp, #28]
	subs	w8, w8, #0
	cset	w8, le
	tbnz	w8, #0, LBB0_2
	b	LBB0_1
LBB0_1:
	ldr	w8, [sp, #24]
	subs	w8, w8, #0
	cset	w8, ne
	tbnz	w8, #0, LBB0_3
	b	LBB0_2
LBB0_2:
	movi	d0, #0000000000000000
	str	d0, [sp, #40]
	b	LBB0_12
LBB0_3:
	movi	d0, #0000000000000000
	str	d0, [sp, #8]
	str	wzr, [sp, #20]
	b	LBB0_4
LBB0_4:                                 ; =>This Inner Loop Header: Depth=1
	ldr	w8, [sp, #20]
	ldr	w9, [sp, #28]
	subs	w8, w8, w9
	cset	w8, ge
	tbnz	w8, #0, LBB0_11
	b	LBB0_5
LBB0_5:                                 ;   in Loop: Header=BB0_4 Depth=1
	ldr	w8, [sp, #24]
	subs	w8, w8, #1
	cset	w8, ne
	tbnz	w8, #0, LBB0_7
	b	LBB0_6
LBB0_6:                                 ;   in Loop: Header=BB0_4 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #20]
	ldr	s1, [x8, x9, lsl #2]
                                        ; implicit-def: $d0
	fmov	s0, s1
	sshll.2d	v0, v0, #0
                                        ; kill: def $d0 killed $d0 killed $q0
	scvtf	d1, d0
	ldr	d0, [sp, #8]
	fadd	d0, d0, d1
	str	d0, [sp, #8]
	b	LBB0_10
LBB0_7:                                 ;   in Loop: Header=BB0_4 Depth=1
	ldr	w8, [sp, #24]
	subs	w8, w8, #2
	cset	w8, ne
	tbnz	w8, #0, LBB0_9
	b	LBB0_8
LBB0_8:                                 ;   in Loop: Header=BB0_4 Depth=1
	ldr	x8, [sp, #32]
	ldrsw	x9, [sp, #20]
	ldr	w8, [x8, x9, lsl #2]
	ldr	x9, [sp, #32]
	ldrsw	x10, [sp, #20]
	ldr	w9, [x9, x10, lsl #2]
	mul	w8, w8, w9
	scvtf	d1, w8
	ldr	d0, [sp, #8]
	fadd	d0, d0, d1
	str	d0, [sp, #8]
	b	LBB0_9
LBB0_9:                                 ;   in Loop: Header=BB0_4 Depth=1
	b	LBB0_10
LBB0_10:                                ;   in Loop: Header=BB0_4 Depth=1
	ldr	w8, [sp, #20]
	add	w8, w8, #1
	str	w8, [sp, #20]
	b	LBB0_4
LBB0_11:
	ldr	d0, [sp, #8]
	ldr	s2, [sp, #28]
                                        ; implicit-def: $d1
	fmov	s1, s2
	sshll.2d	v1, v1, #0
                                        ; kill: def $d1 killed $d1 killed $q1
	scvtf	d1, d1
	fdiv	d0, d0, d1
	str	d0, [sp, #40]
	b	LBB0_12
LBB0_12:
	ldr	d0, [sp, #40]
	add	sp, sp, #48
	ret
	.cfi_endproc
                                        ; -- End function
.subsections_via_symbols
