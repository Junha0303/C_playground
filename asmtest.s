	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 4
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	leaq	L_.str(%rip), %rdi
	leaq	-4(%rbp), %rsi
	xorl	%eax, %eax
	callq	_scanf
	cmpl	$0, -4(%rbp)
	jne	LBB0_2
## %bb.1:
	leaq	L_str(%rip), %rdi
	callq	_puts
LBB0_2:
	xorl	%eax, %eax
	addq	$16, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_str:                                  ## @str
	.asciz	"Hi"


.subsections_via_symbols
