

# xSpim Memory Demo Program

#  Data Area
.data

welcome:
	.asciiz "This program loads, stores, and operates on variables\nLooking at the comments in the code, perform the operations specified.  Make sure you make changes to this code in order to test it.  You can change the initial value sof variables as well as the inputs you test."

initial1:
	.asciiz "\nGlobal variable values are: "

initial2:
	.asciiz "\nArray values are: "

initial3:
	.asciiz "\nregister values are: "

comma:
	.asciiz ", "

enter:
	.asciiz "\nEnter a value: "

# global variables
globalA:
        .word 0x23
globalB:
        .word 0x27
globalC:
        .word 0x36
globalD:
        .word 0x5a

# myArray declaration allocates & initializes a 9 integer array,
myArray:
        .word 0x20030112 0x200202f1 0x100b00a1 0x6b502a
        .word 0x15400003 0x1084020 0x20840000 0x800fffa
        .word 0x1001020

question:
	.asciiz "What functions would you like to test? "

#Text Area (i.e. instructions)
.text

main:

	# Display the welcome message;  lui and ori constants are obtained
	#  manually from the global symbol table.  One will surely appreciate
	#  the la pseudoinstruction after this exercise.
	ori     $v0, $0, 4			
	la     $a0, welcome
	syscall

	add $a0, $0, $0
	add $a1, $0, $0
	add $a2, $0, $0
	add $a3, $0, $0
	jal printvalues

	# ask which question to test
	ori     $v0, $0, 4			
	la     $a0, enter
	syscall
        # read number
        ori     $v0, $0, 5
        syscall
	add	$s7, $v0, $0
 	

	# wipe regs clean
	add $a0, $0, $0
	add $a1, $0, $0
	add $a2, $0, $0
	add $a3, $0, $0
	add $v0, $0, $0
	add $v1, $0, $0
	add $a0, $0, $0
	add $a1, $0, $0
	add $a2, $0, $0
	add $a3, $0, $0
	add $t0, $0, $0
	add $t1, $0, $0
	add $t2, $0, $0
	add $t3, $0, $0
	add $t4, $0, $0
	add $t5, $0, $0
	add $t6, $0, $0
	add $t7, $0, $0
	add $s6, $0, $0
	add $s5, $0, $0
	add $s4, $0, $0
	add $s3, $0, $0
	add $s2, $0, $0
	add $s1, $0, $0
	add $s0, $0, $0

	# print out which they are going to call
	ori     $v0, $0, 1			
	add	$a0, $s7, $0
	syscall
	add $a0, $0, $0
	add $a1, $0, $0
	add $a2, $0, $0
	add $a3, $0, $0

	addi $t0, $0, 1
	slt $t1, $s7, $t0
	beq $t1, $0, F1
	# first function call
	jal storevalues
	jal printvalues
	j end

F1:	addi $t0, $t0, 1
	slt $t1, $s7, $t0
	beq $t1, $0, F2
	addi $a0, $0, 23
	addi $a1, $0, 155
	addi $a2, $0, 33
	addi $a3, $0, 74
	jal printregs
	jal storeregvalues
	jal printvalues
	j end

F2:	addi $t0, $t0, 1
	slt $t1, $s7, $t0
	beq $t1, $0, F3
	jal copyvalues
	jal printvalues
	j end

F3:	addi $t0, $t0, 1
	slt $t1, $s7, $t0
	beq $t1, $0, F4
	jal operations
	jal printvalues
	j end

F4:	addi $t0, $t0, 1
	slt $t1, $s7, $t0
	beq $t1, $0, F5
	addi $a0, $0, 9
	addi $a1, $0, 6
	jal printregs
	jal arrays
	jal printvalues
	j end

F5:	jal arraycalcs
	jal printvalues
	j end

end:
	# Exit
	ori     $v0, $0, 10
	syscall

printregs:
	addi $sp, $sp, -24
	sw $ra, 0($sp)
	sw $a0, 4($sp)
	sw $a1, 8($sp)
	sw $a2, 12($sp)
	sw $a3, 16($sp)
	# print out the initial values
	ori     $v0, $0, 4			
	la     $a0, initial3
	syscall
	# load and print out globalA
	ori     $v0, $0, 1			
	lw	$a0, 4($sp)
	syscall
	# print a comma
	ori     $v0, $0, 4			
	la     $a0, comma
	syscall
	# load and print out globalA
	ori     $v0, $0, 1			
	lw	$a0, 8($sp)
	syscall
	# print a comma
	ori     $v0, $0, 4			
	la     $a0, comma
	syscall
	# load and print out globalA
	ori     $v0, $0, 1			
	lw	$a0, 12($sp)
	syscall
	# print a comma
	ori     $v0, $0, 4			
	la     $a0, comma
	syscall
	# load and print out globalA
	ori     $v0, $0, 1			
	lw	$a0, 16($sp)
	syscall

	lw $a0, 4($sp)
	lw $a1, 8($sp)
	lw $a2, 12($sp)
	lw $a3, 16($sp)
	lw $ra, 0($sp)
	addi $sp, $sp, 24
	jr $ra

printvalues:
	addi $sp, $sp, -16
	sw $ra, 0($sp)
	# print out the initial values
	ori     $v0, $0, 4			
	la     $a0, initial1
	syscall
	# load and print out globalA
	ori     $v0, $0, 1			
	la	$t0, globalA
	lw	$a0, 0($t0)
	syscall
	# print a comma
	ori     $v0, $0, 4			
	la     $a0, comma
	syscall
	# load and print out globalB
	ori     $v0, $0, 1			
	la	$t0, globalB
	lw	$a0, 0($t0)
	syscall
	# print a comma
	ori     $v0, $0, 4			
	la     $a0, comma
	syscall
	# load and print out globalC
	ori     $v0, $0, 1			
	la	$t0, globalC
	lw	$a0, 0($t0)
	syscall
	# print a comma
	ori     $v0, $0, 4			
	la     $a0, comma
	syscall
	# load and print out globalD
	ori     $v0, $0, 1			
	la	$t0, globalD
	lw	$a0, 0($t0)
	syscall


	# print out the initial values
	ori     $v0, $0, 4			
	la     $a0, initial2
	syscall
	# load and print out globalA
	ori     $v0, $0, 1			
	la	$s0, myArray
	lw	$a0, 0($s0)
	syscall
	# print a comma
	ori     $v0, $0, 4			
	la     $a0, comma
	syscall
	# load and print out globalB
	ori     $v0, $0, 1			
	lw	$a0, 4($s0)
	syscall
	# print a comma
	ori     $v0, $0, 4			
	la     $a0, comma
	syscall
	# load and print out globalB
	ori     $v0, $0, 1			
	lw	$a0, 8($s0)
	syscall
	# print a comma
	ori     $v0, $0, 4			
	la     $a0, comma
	syscall
	# load and print out globalB
	ori     $v0, $0, 1			
	lw	$a0, 12($s0)
	syscall
	lw $ra, 0($sp)
	addi $sp, $sp, 16
	jr $ra


# COPYFROMHERE - DO NOT REMOVE THIS LINE

storevalues:

        # TODO: translate each line into mips
        # use only regs $v0-$v1, $t0-$t7, $a0-$a3
        # you may assume nothing about their starting values

        # globalA = 6

        # globalB = 6

        # globalC = 30

        # globalD = 30

        # do not remove this line
        jr $ra

storeregvalues:
        # TODO:  In this case, instead of storing constants,
        # we are storing register values into the variables
        # use only regs $v0-$v1, $t0-$t7,
        # you may assume that $a0-$a3 have already been set

        # globalA = $a3

        # globalB = $a2

        # globalC = $a1

        # globalD = $a0

        # do not remove this line
        jr $ra


copyvalues:
        # TODO: translate each line into mips
        # use only regs $v0-$v1, $t0-$t7, $a0-$a3
        # you may assume nothing about their starting values
        # globalA = globalB

        # globalD = globalC

        # do not remove this line
        jr $ra


operations:
        # TODO: translate each line into mips
        # use only regs $v0-$v1, $t0-$t7, $a0-$a3
        # you may assume nothing about their starting values


        # globalA = globalC + globalB

        # globalD = globalB + globalA

        # do not remove this line
        jr $ra


arrays:
        # TODO: translate each line into mips
        # use only regs $v0-$v1, $t0-$t7, $a2-$a3
        # you may assume nothing about their starting values
        # $a0 and $a1 have already been set for you

        #myArray[0] = $a0

        #myArray[1] = $a1

        #myArray[2] = globalD

        #globalB = myArray[3]

        # do not remove this line
        jr $ra

arraycalcs:
        # TODO: translate each line into mips
        # use only regs $v0-$v1, $t0-$t7, $a0-$a3
        # you may assume nothing about their starting values

        # globalB = myArray[0] + myArray[5]

        # do not remove this line
        jr $ra


