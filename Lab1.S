.data

N:
.word 5
M:
.word 6

array:
.word -18, -14, 24, 22, 23, -22
.word 29, -18, 21, -18, -20, -8
.word -9, 28, 30, 13, -3, -3
.word -25, 22, 30, -24, 14, -27
.word -27, 4, -21, -10, 16, 11

positive:
.word 0
negative:
.word 0

.text

.globl _start
_start:
la t0, array # Загрузка адреса массива
lw t1, N	 # Загрузка кол-ва строк
lw t2, M	 # Загрузка кол-ва столбцов
li t3, 0	 # Инициализация счетчика строк
li t4, 0	 # Инициализация счетчика положительных чисел
li t5, 0	 # Инициализация счетчика отрицательных чисел

outer_loop:
bge t3, t1, end_outer
li t6, 0 	 # Инициализация счетчика столбцов

inner_loop:
bge t6, t2, end_inner

# Вычисление адреса текущего элемента: array + (i * cols + j) * 4
mul a0, t3, t2
add a0, a0, t6
slli a0, a0, 2 # Смещение на 2 бита эквивалентно * 4
add a0, t0, a0

lw a1, 0(a0) # Запись текущего элемента в а1

# Проверка: является ли число положительным
blez a1, check_negative
addi t4, t4, 1
j next_element

# Проверка: является ли число отрицательным
check_negative:
bgez a1, next_element
addi t5, t5, 1

next_element:
addi t6, t6, 1 # Увеличение счетчика столбцов
j inner_loop

end_inner:
addi t3, t3, 1
j outer_loop

end_outer:
la a0, positive
sw t4, 0(a0) # Сохранение кол-ва положительных чисел
la a0, negative
sw t5, 0(a0) # Сохранение кол-ва отрицательных чисел чисел

exit:
li a0, 10
ecall