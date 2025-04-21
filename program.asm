sys_exit equ 1
sys_read equ 3
sys_write equ 4
stdin equ 0
stdout equ 1
stderr equ 3

section .data
newline db 0xA
Result db 'Ans = '
ResultValue db 'aaaaa'
db 0xA
ResultEnd equ $-Result
M DW 7
N DW 85
lit12 DW 12
lit13 DW 13
section .bss
ReadInt RESW 1
X RESW 1
Y RESW 1
Z RESW 1
A RESW 1
T1 RESW 1
T2 RESW 1
T3 RESW 1
T4 RESW 1
T5 RESW 1
T6 RESW 1
global _start
section .text
ConvertIntegerToString:
mov ebx, ResultValue + 4
ConvertLoop:
sub dx, dx
mov cx, 10
div cx
add dl, '0'
mov [ebx], dl
dec ebx
cmp ebx, ResultValue
jge ConvertLoop
ret
_start:
mov ax, [Y]
mul word [Z]
mov [T1], ax
mov ax, [M]
add ax, [T1]
mov [T2], ax
mov ax, [T2]
add ax, [lit12]
mov [T3], ax
mov ax, [T3]
mov [X], ax
mov ax, [X]
mul word [Z]
mov [T4], ax
mov ax, [T4]
add ax, [lit13]
mov [T5], ax
mov ax, [T5]
mov [A], ax
mov ax, [A]
cmp ax, [X]
JGE L1
mov ax, [X]
sub ax, [lit13]
mov [T6], ax
mov ax, [T6]
mov [X], ax
L1: nop
mov ax, [X]
call ConvertIntegerToString
mov eax, 4
mov ebx, 1
mov ecx, Result
mov edx, ResultEnd
int 80h
mov eax, sys_exit
xor ebx, ebx
int 80h
