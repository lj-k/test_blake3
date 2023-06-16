	.file	"perftest_module_many.c"
	.text
	.section	.rodata
	.align 32
	.type	IV, @object
	.size	IV, 32
IV:
	.long	1779033703
	.long	-1150833019
	.long	1013904242
	.long	-1521486534
	.long	1359893119
	.long	-1694144372
	.long	528734635
	.long	1541459225
	.align 32
	.type	MSG_SCHEDULE, @object
	.size	MSG_SCHEDULE, 112
MSG_SCHEDULE:
	.string	""
	.ascii	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017"
	.string	"\002\006\003\n\007"
	.ascii	"\004\r\001\013\f\005\t\016\017\b"
	.string	"\003\004\n\f\r\002\007\016\006\005\t"
	.ascii	"\013\017\b\001"
	.string	"\n\007\f\t\016\003\r\017\004"
	.ascii	"\013\002\005\b\001\006"
	.string	"\f\r\t\013\017\n\016\b\007\002\005\003"
	.ascii	"\001\006\004"
	.string	"\t\016\013\005\b\f\017\001\r\003"
	.ascii	"\n\002\006\004\007"
	.string	"\013\017\005"
	.ascii	"\001\t\b\006\016\n\002\f\003\004\007\r"
	.text
	.type	highest_one, @function
highest_one:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movq	%rdi, -8(%rbp)
	bsrq	-8(%rbp), %rax
	xorq	$63, %rax
	xorl	$63, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	highest_one, .-highest_one
	.globl	data
	.data
	.align 32
	.type	data, @object
	.size	data, 2048
data:
	.string	""
	.string	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372"
	.string	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372"
	.string	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372"
	.string	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372"
	.string	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372"
	.string	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372"
	.string	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037 !\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357\360\361\362\363\364\365\366\367\370\371\372"
	.ascii	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017\020\021\022"
	.ascii	"\023\024\025\026\027\030\031\032\033\034\035\036\037 !\"#$%&"
	.ascii	"'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`a"
	.ascii	"bcdefghijklmnopqrstuvwxyz{|}~\177\200\201\202\203\204\205\206"
	.ascii	"\207\210\211\212\213\214\215\216\217\220\221\222\223\224\225"
	.ascii	"\226\227\230\231\232\233\234\235\236\237\240\241\242\243\244"
	.ascii	"\245\246\247\250\251\252\253\254\255\256\257\260\261\262\263"
	.ascii	"\264\265\266\267\270\271\272\273\274\275\276\277\300\301\302"
	.ascii	"\303\304\305\306\307\310\311\312\313\314\315\316\317\320\321"
	.ascii	"\322\323\324\325\326\327\330\331\332\333\334\335\336\337\340"
	.ascii	"\341\342\343\344\345\346\347\350\351\352\353\354\355\356\357"
	.ascii	"\360\361\362"
	.string	"\363\364\365\366\367\370\371\372"
	.ascii	"\001\002\003\004\005\006\007\b\t\n\013\f\r\016\017\020\021\022"
	.ascii	"\023\024\025\026\027\030\031\032\033\034\035\036\037 !\"#$%&"
	.ascii	"'"
	.globl	num_inputs
	.align 8
	.type	num_inputs, @object
	.size	num_inputs, 8
num_inputs:
	.quad	2
	.globl	blocks
	.align 8
	.type	blocks, @object
	.size	blocks, 8
blocks:
	.quad	16
	.globl	key
	.section	.rodata
	.align 32
	.type	key, @object
	.size	key, 32
key:
	.long	1779033703
	.long	-1150833019
	.long	1013904242
	.long	-1521486534
	.long	1359893119
	.long	-1694144372
	.long	528734635
	.long	1541459225
	.globl	counter
	.bss
	.align 8
	.type	counter, @object
	.size	counter, 8
counter:
	.zero	8
	.globl	increment_counter
	.data
	.type	increment_counter, @object
	.size	increment_counter, 1
increment_counter:
	.byte	1
	.globl	flags
	.bss
	.type	flags, @object
	.size	flags, 1
flags:
	.zero	1
	.globl	flags_start
	.data
	.type	flags_start, @object
	.size	flags_start, 1
flags_start:
	.byte	1
	.globl	flags_end
	.type	flags_end, @object
	.size	flags_end, 1
flags_end:
	.byte	2
	.globl	out
	.bss
	.align 32
	.type	out, @object
	.size	out, 64
out:
	.zero	64
	.section	.rodata
	.align 8
.LC0:
	.string	"\n## blake3_hash_many  (M%d%d):\n"
	.align 8
.LC1:
	.string	"\tsize_t num_inputs=%llu, \n\tsize_t blocks=%llu,\n\tuint64_t counter=%llu \n"
	.align 8
.LC2:
	.string	"\tbool increment_counter=%d, \n\tuint8_t flags=%x,\n\tuint8_t flags_start=%x,\n\tuint8_t flags_end=%x \n"
.LC3:
	.string	"\n### input message: [0~%d]\n"
.LC4:
	.string	"\n####  Parallel %d\n"
.LC5:
	.string	"%02x,"
.LC6:
	.string	"\n\n#### Parallel %d"
.LC7:
	.string	"\n### input key: [0~7]"
.LC8:
	.string	" % 02X,"
.LC9:
	.string	"\nblake3_hash_many_avx512"
.LC10:
	.string	"\n### output out: [0~%d]\n"
.LC11:
	.string	"%02X,"
	.text
	.globl	main
	.type	main, @function
main:
.LFB9:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	leaq	data(%rip), %rax
	movq	%rax, -32(%rbp)
	leaq	1024+data(%rip), %rax
	movq	%rax, -24(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -40(%rbp)
	movq	blocks(%rip), %rax
	movl	%eax, %edx
	movq	num_inputs(%rip), %rax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	counter(%rip), %rcx
	movq	blocks(%rip), %rdx
	movq	num_inputs(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movzbl	flags_end(%rip), %eax
	movzbl	%al, %esi
	movzbl	flags_start(%rip), %eax
	movzbl	%al, %ecx
	movzbl	flags(%rip), %eax
	movzbl	%al, %edx
	movzbl	increment_counter(%rip), %eax
	movzbl	%al, %eax
	movl	%esi, %r8d
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movq	blocks(%rip), %rax
	movl	%eax, %edx
	movq	num_inputs(%rip), %rax
	imull	%edx, %eax
	sall	$6, %eax
	subl	$1, %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -64(%rbp)
	movl	$1, -60(%rbp)
	movl	$0, -56(%rbp)
	movl	-60(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC4(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -52(%rbp)
	jmp	.L4
.L7:
	movl	-52(%rbp), %eax
	movslq	%eax, %rdx
	movq	-40(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC5(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -64(%rbp)
	movl	-64(%rbp), %eax
	cltq
	movq	blocks(%rip), %rdx
	salq	$6, %rdx
	cmpq	%rdx, %rax
	jne	.L5
	movl	$0, -64(%rbp)
	addl	$1, -60(%rbp)
	movl	-52(%rbp), %eax
	cltq
	movq	blocks(%rip), %rcx
	movq	num_inputs(%rip), %rdx
	imulq	%rcx, %rdx
	salq	$6, %rdx
	subq	$1, %rdx
	cmpq	%rdx, %rax
	jnb	.L5
	movl	-60(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC6(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
.L5:
	addl	$1, -56(%rbp)
	cmpl	$16, -56(%rbp)
	jne	.L6
	movl	$0, -56(%rbp)
	movl	$10, %edi
	call	putchar@PLT
.L6:
	addl	$1, -52(%rbp)
.L4:
	movl	-52(%rbp), %eax
	cltq
	movq	blocks(%rip), %rcx
	movq	num_inputs(%rip), %rdx
	imulq	%rcx, %rdx
	salq	$6, %rdx
	cmpq	%rdx, %rax
	jb	.L7
	leaq	.LC7(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -48(%rbp)
	jmp	.L8
.L9:
	movl	-48(%rbp), %eax
	cltq
	leaq	0(,%rax,4), %rdx
	leaq	key(%rip), %rax
	movl	(%rdx,%rax), %eax
	movl	%eax, %esi
	leaq	.LC8(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	addl	$1, -48(%rbp)
.L8:
	cmpl	$6, -48(%rbp)
	jle	.L9
	movl	$10, %edi
	call	putchar@PLT
	leaq	.LC9(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movzbl	flags_end(%rip), %eax
	movzbl	%al, %r8d
	movzbl	flags_start(%rip), %eax
	movzbl	%al, %edi
	movzbl	flags(%rip), %eax
	movzbl	%al, %ecx
	movzbl	increment_counter(%rip), %eax
	movzbl	%al, %r11d
	movq	counter(%rip), %r10
	movq	blocks(%rip), %rdx
	movq	num_inputs(%rip), %rsi
	leaq	-32(%rbp), %rax
	leaq	out(%rip), %r9
	pushq	%r9
	pushq	%r8
	pushq	%rdi
	pushq	%rcx
	movl	%r11d, %r9d
	movq	%r10, %r8
	leaq	key(%rip), %rcx
	movq	%rax, %rdi
	call	blake3_hash_many_portable@PLT
	addq	$32, %rsp
	movl	$64, %esi
	leaq	.LC10(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, -44(%rbp)
	jmp	.L10
.L12:
	movl	-44(%rbp), %eax
	cltq
	leaq	out(%rip), %rdx
	movzbl	(%rax,%rdx), %eax
	movzbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC11(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	-44(%rbp), %eax
	addl	$1, %eax
	andl	$31, %eax
	testl	%eax, %eax
	jne	.L11
	movl	$10, %edi
	call	putchar@PLT
.L11:
	addl	$1, -44(%rbp)
.L10:
	cmpl	$63, -44(%rbp)
	jle	.L12
	movl	$0, %eax
	movq	-8(%rbp), %rdx
	subq	%fs:40, %rdx
	je	.L14
	call	__stack_chk_fail@PLT
.L14:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE9:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
