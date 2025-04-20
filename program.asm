sys_exit equ 1
sys_read equ 3
sys_write equ 4
stdin equ 0
stdout equ 1
stderr equ 3

section .data
M DW 13
N DW 56
lit97 DW 97
lit18 DW 18
section .bss
X RESW 1
Y RESW 1
Z RESW 1
T1 RESW 1
T2 RESW 1
T3 RESW 1
global _start
section .text

_start:
mov ax, [lit97]
mov [Y], ax
mov ax, [M]
mul [N]
mov [T1], ax
mov ax, [T1]
add ax, [lit18]
mov [T2], ax
mov ax, [T2]
sub ax, [Y]
mov [T3], ax
mov ax, [T3]
mov [X], ax
mov eax, sys_exit
xor ebx, ebx
int 80h
