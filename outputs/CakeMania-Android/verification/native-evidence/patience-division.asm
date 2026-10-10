
/Users/myrarc/Documents/Projects/Games/Cake Mania/CakeMania_data.exe:	file format coff-i386

Disassembly of section .text:

00401000 <.text>:
  412c07: 8b 46 3c                     	movl	0x3c(%esi), %eax
  412c0a: 3b c3                        	cmpl	%ebx, %eax
  412c0c: 8b 4e 38                     	movl	0x38(%esi), %ecx
  412c0f: 89 8e 24 03 00 00            	movl	%ecx, 0x324(%esi)
  412c15: 89 44 24 10                  	movl	%eax, 0x10(%esp)
  412c19: 74 15                        	je	0x412c30 <.text+0x11c30>
  412c1b: db 44 24 10                  	fildl	0x10(%esp)
  412c1f: d8 be 28 03 00 00            	fdivrs	0x328(%esi)
  412c25: e8 3e d9 14 00               	calll	0x560568 <.text+0x15f568>
  412c2a: 89 86 24 03 00 00            	movl	%eax, 0x324(%esi)
  412c30: 8b 46 34                     	movl	0x34(%esi), %eax
  412c33: 39 86 24 03 00 00            	cmpl	%eax, 0x324(%esi)
  412c39: 7e 06                        	jle	0x412c41 <.text+0x11c41>
  412c3b: 89 86 24 03 00 00            	movl	%eax, 0x324(%esi)
