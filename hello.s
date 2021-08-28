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
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	leaq	L_.str(%rip), %rdi
	xorl	%ebx, %ebx
	leaq	-12(%rbp), %rsi
	xorl	%eax, %eax
	callq	_scanf
	movl	-12(%rbp), %eax
	cmpl	$2, %eax
	jl	LBB0_4
## %bb.1:
	xorl	%ebx, %ebx
	.p2align	4, 0x90
LBB0_2:                                 ## =>This Inner Loop Header: Depth=1
	incl	%ebx
	movl	%eax, %ecx
	shrl	%ecx
	testb	$1, %al
	leal	1(%rax,%rax,2), %eax
	cmovel	%ecx, %eax
	cmpl	$1, %eax
	jg	LBB0_2
## %bb.3:
	movl	%eax, -12(%rbp)
LBB0_4:
	leaq	L_.str.1(%rip), %rdi
	movl	%ebx, %esi
	xorl	%eax, %eax
	callq	_printf
	xorl	%eax, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%d"

L_.str.1:                               ## @.str.1
	.asciz	"%d\n"


.subsections_via_symbols
