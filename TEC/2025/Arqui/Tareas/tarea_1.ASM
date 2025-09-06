#Factorial  
res =0 


lw $a0 , varfact 
jal Factorial
sw $v0  res

Factorial 
addi $sp , $sp , -4
sw  $t0 , 0($sp)

IF
bne $a0 , $zero , ELSE
addi $v0 , $zero , 1
j exit 

Else_fact
add $t0 , $a0 , $zero
addi $a0 , $a0 , -1
$addi $sp , $sp , -4
sw  $t0 , 0($sp)
jal Factorial
lw $ra  0($sp)
addi $sp , $sp , 4
exit
mult	$t0, $v0
add $v0 , $zero , $lo
lw $t0 , 0($sp)
addi $sp , $sp , 4
jr $ra

#revisar esta mierda , que se me fue hacerla el else y exit. 

suma #revisar lo que hay en psp. 


main 
    addi $sp , $sp , -4
    li $v0 , 8 
    move $a0 , $sp 
    li $a1 , 32 $
    syscall 
    lbu $t0 , 0($sp)
    li $t1 , 70 #F
    beq $t0 , $t1 , Factorial
    li $v0 , 83 #s
    beq $s0 , $t1 , suma
    j exit

exit
    li $v0 , 10
    syscall

