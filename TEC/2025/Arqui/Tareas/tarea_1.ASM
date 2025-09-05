#Factorial  
varfact=4
res=0 

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

