	.text
	.intel_syntax noprefix
	.file	"dynamicdispatch.cpp"
	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90
	.type	__cxx_global_var_init,@function
__cxx_global_var_init:                  # @__cxx_global_var_init
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp0:
	.cfi_def_cfa_offset 16
.Ltmp1:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp2:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	movabs	rdi, _ZStL8__ioinit
	call	_ZNSt8ios_base4InitC1Ev
	movabs	rdi, _ZNSt8ios_base4InitD1Ev
	movabs	rsi, _ZStL8__ioinit
	movabs	rdx, __dso_handle
	call	__cxa_atexit
	mov	dword ptr [rbp - 4], eax # 4-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end0:
	.size	__cxx_global_var_init, .Lfunc_end0-__cxx_global_var_init
	.cfi_endproc

	.text
	.globl	main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp3:
	.cfi_def_cfa_offset 16
.Ltmp4:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp5:
	.cfi_def_cfa_register rbp
	sub	rsp, 32
	lea	rdi, [rbp - 24]
	mov	dword ptr [rbp - 4], 0
	call	_ZN3catC2Ev
	lea	rdi, [rbp - 24]
	mov	qword ptr [rbp - 16], rdi
	mov	rdi, qword ptr [rbp - 16]
	mov	rax, qword ptr [rdi]
	call	qword ptr [rax]
	mov	rdi, qword ptr [rbp - 16]
	call	_ZN6feline4purrEv
	mov	eax, 1
	add	rsp, 32
	pop	rbp
	ret
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc

	.section	.text._ZN3catC2Ev,"axG",@progbits,_ZN3catC2Ev,comdat
	.weak	_ZN3catC2Ev
	.p2align	4, 0x90
	.type	_ZN3catC2Ev,@function
_ZN3catC2Ev:                            # @_ZN3catC2Ev
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp6:
	.cfi_def_cfa_offset 16
.Ltmp7:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp8:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	mov	rax, rdi
	mov	qword ptr [rbp - 16], rdi # 8-byte Spill
	mov	rdi, rax
	call	_ZN6felineC2Ev
	movabs	rax, _ZTV3cat
	add	rax, 16
	mov	rdi, qword ptr [rbp - 16] # 8-byte Reload
	mov	qword ptr [rdi], rax
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end2:
	.size	_ZN3catC2Ev, .Lfunc_end2-_ZN3catC2Ev
	.cfi_endproc

	.section	.text._ZN6feline4purrEv,"axG",@progbits,_ZN6feline4purrEv,comdat
	.weak	_ZN6feline4purrEv
	.p2align	4, 0x90
	.type	_ZN6feline4purrEv,@function
_ZN6feline4purrEv:                      # @_ZN6feline4purrEv
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp9:
	.cfi_def_cfa_offset 16
.Ltmp10:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp11:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	movabs	rax, _ZSt4cout
	movabs	rsi, .L.str.2
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	mov	qword ptr [rbp - 16], rax # 8-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end3:
	.size	_ZN6feline4purrEv, .Lfunc_end3-_ZN6feline4purrEv
	.cfi_endproc

	.section	.text._ZN6felineC2Ev,"axG",@progbits,_ZN6felineC2Ev,comdat
	.weak	_ZN6felineC2Ev
	.p2align	4, 0x90
	.type	_ZN6felineC2Ev,@function
_ZN6felineC2Ev:                         # @_ZN6felineC2Ev
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp12:
	.cfi_def_cfa_offset 16
.Ltmp13:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp14:
	.cfi_def_cfa_register rbp
	movabs	rax, _ZTV6feline
	add	rax, 16
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, qword ptr [rbp - 8]
	mov	qword ptr [rdi], rax
	pop	rbp
	ret
.Lfunc_end4:
	.size	_ZN6felineC2Ev, .Lfunc_end4-_ZN6felineC2Ev
	.cfi_endproc

	.section	.text._ZN3cat5soundEv,"axG",@progbits,_ZN3cat5soundEv,comdat
	.weak	_ZN3cat5soundEv
	.p2align	4, 0x90
	.type	_ZN3cat5soundEv,@function
_ZN3cat5soundEv:                        # @_ZN3cat5soundEv
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp15:
	.cfi_def_cfa_offset 16
.Ltmp16:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp17:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	movabs	rax, _ZSt4cout
	movabs	rsi, .L.str.1
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	mov	qword ptr [rbp - 16], rax # 8-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end5:
	.size	_ZN3cat5soundEv, .Lfunc_end5-_ZN3cat5soundEv
	.cfi_endproc

	.section	.text._ZN6feline5soundEv,"axG",@progbits,_ZN6feline5soundEv,comdat
	.weak	_ZN6feline5soundEv
	.p2align	4, 0x90
	.type	_ZN6feline5soundEv,@function
_ZN6feline5soundEv:                     # @_ZN6feline5soundEv
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp18:
	.cfi_def_cfa_offset 16
.Ltmp19:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp20:
	.cfi_def_cfa_register rbp
	sub	rsp, 16
	movabs	rax, _ZSt4cout
	movabs	rsi, .L.str
	mov	qword ptr [rbp - 8], rdi
	mov	rdi, rax
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movabs	rsi, _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
	mov	rdi, rax
	call	_ZNSolsEPFRSoS_E
	mov	qword ptr [rbp - 16], rax # 8-byte Spill
	add	rsp, 16
	pop	rbp
	ret
.Lfunc_end6:
	.size	_ZN6feline5soundEv, .Lfunc_end6-_ZN6feline5soundEv
	.cfi_endproc

	.section	.text.startup,"ax",@progbits
	.p2align	4, 0x90
	.type	_GLOBAL__sub_I_dynamicdispatch.cpp,@function
_GLOBAL__sub_I_dynamicdispatch.cpp:     # @_GLOBAL__sub_I_dynamicdispatch.cpp
	.cfi_startproc
# BB#0:
	push	rbp
.Ltmp21:
	.cfi_def_cfa_offset 16
.Ltmp22:
	.cfi_offset rbp, -16
	mov	rbp, rsp
.Ltmp23:
	.cfi_def_cfa_register rbp
	call	__cxx_global_var_init
	pop	rbp
	ret
.Lfunc_end7:
	.size	_GLOBAL__sub_I_dynamicdispatch.cpp, .Lfunc_end7-_GLOBAL__sub_I_dynamicdispatch.cpp
	.cfi_endproc

	.type	_ZStL8__ioinit,@object  # @_ZStL8__ioinit
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.type	_ZTV3cat,@object        # @_ZTV3cat
	.section	.rodata._ZTV3cat,"aG",@progbits,_ZTV3cat,comdat
	.weak	_ZTV3cat
	.p2align	3
_ZTV3cat:
	.quad	0
	.quad	_ZTI3cat
	.quad	_ZN3cat5soundEv
	.size	_ZTV3cat, 24

	.type	_ZTS3cat,@object        # @_ZTS3cat
	.section	.rodata._ZTS3cat,"aG",@progbits,_ZTS3cat,comdat
	.weak	_ZTS3cat
_ZTS3cat:
	.asciz	"3cat"
	.size	_ZTS3cat, 5

	.type	_ZTS6feline,@object     # @_ZTS6feline
	.section	.rodata._ZTS6feline,"aG",@progbits,_ZTS6feline,comdat
	.weak	_ZTS6feline
_ZTS6feline:
	.asciz	"6feline"
	.size	_ZTS6feline, 8

	.type	_ZTI6feline,@object     # @_ZTI6feline
	.section	.rodata._ZTI6feline,"aG",@progbits,_ZTI6feline,comdat
	.weak	_ZTI6feline
	.p2align	3
_ZTI6feline:
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16
	.quad	_ZTS6feline
	.size	_ZTI6feline, 16

	.type	_ZTI3cat,@object        # @_ZTI3cat
	.section	.rodata._ZTI3cat,"aG",@progbits,_ZTI3cat,comdat
	.weak	_ZTI3cat
	.p2align	4
_ZTI3cat:
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16
	.quad	_ZTS3cat
	.quad	_ZTI6feline
	.size	_ZTI3cat, 24

	.type	_ZTV6feline,@object     # @_ZTV6feline
	.section	.rodata._ZTV6feline,"aG",@progbits,_ZTV6feline,comdat
	.weak	_ZTV6feline
	.p2align	3
_ZTV6feline:
	.quad	0
	.quad	_ZTI6feline
	.quad	_ZN6feline5soundEv
	.size	_ZTV6feline, 24

	.type	.L.str,@object          # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"hello"
	.size	.L.str, 6

	.type	.L.str.1,@object        # @.str.1
.L.str.1:
	.asciz	"meow"
	.size	.L.str.1, 5

	.type	.L.str.2,@object        # @.str.2
.L.str.2:
	.asciz	"purrpurr"
	.size	.L.str.2, 9

	.section	.init_array,"aw",@init_array
	.p2align	3
	.quad	_GLOBAL__sub_I_dynamicdispatch.cpp

	.ident	"clang version 3.9.1-4ubuntu3~14.04.3 (tags/RELEASE_391/rc2)"
	.section	".note.GNU-stack","",@progbits
