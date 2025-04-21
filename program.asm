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
M DW 13
N DW 56
lit97 DW 97
lit18 DW 18
section .bss
ReadInt RESW 1
X RESW 1
Y RESW 1
Z RESW 1
T1 RESW 1
T2 RESW 1
T3 RESW 1
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
mov ax, [lit97]
mov [Y], ax
mov ax, [M]
mul word [N]
mov [T1], ax
mov ax, [T1]
add ax, [lit18]
mov [T2], ax
mov ax, [T2]
sub ax, [Y]
mov [T3], ax
mov ax, [T3]
mov [X], ax
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
