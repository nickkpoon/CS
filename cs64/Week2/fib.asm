# xSpim Demo Program
# 
#   CPE 315
#   fall 2001
#
# By: Dan Stearns
# Date:  
# Modifications: 
#	4/10/03 knico Tabbed code
#	4/10/03 knico Modified to use s registers instead of t registers
#           
#
# declare global so programmer can see actual addresses.

.globl msg
.globl ans

#  Data Area - allocate and initialize variables
.data

	# TODO: Complete these declarations / initializations
msg:
	.asciiz "Enter the number you want the fibonacci value for:\n"
ans:
	.asciiz "The nth fibonacci number is:  "


#Text Area (i.e. instructions)
.text

main:

	# TODO: Write your code here
	
	#Ask to enter the first digits
	ori		$v0, $0, 4
	la		$a0, msg
	syscall
	
	#read integer
	ori		$v0, $0, 5
	syscall
	
	#add integer to t0
	add		$a0, $v0, $0
	
	jal fib 
	
	add 	$a0, $v0, $0
	ori		$v0, $0, 1
	syscall
	
	ori		$v0, $0, 10
	syscall
	
fib:
	
	beq $a0, $0, return0
	#add a 1 to t0, so if its equal to 0, return it
	addi $t0, $0, 1 
	beq $a0, $t0, return1
	
	add		$t1, $0, $0
	add		$t2, $0, $0
	addi	$t3, $0, 1
	addi	$t4, $0, 1


loop:
	bge		$t4, $a0, end
	add		$t1, $t2, $t3
	add		$t2, $0, $t3
	add		$t3, $0, $t1
	addi	$t4, $t4, 1
	j		loop

	
return0:
	add		$v0, $0, $0
	jr		$ra
	
return1:
	addi	$v0, $0, 1
	jr		$ra
	
end:
	add		$v0, $0, $t1
	jr		$ra
	

exit:

	# Exit
	ori     $v0, $0, 10
	syscall
