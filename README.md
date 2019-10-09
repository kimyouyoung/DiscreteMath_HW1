# DiscreteMath_HW1
#### 21800147 Kim YouYoung

# Number Cross
Number Cross consists of an M x N grid, so that the sum of the black square labels matches the label of the column and the sum of the white square labels matches the label of the row.
### Input : There are two conditions for input file.
* Input should be read as standard input.
* The size of the input should not be greater than 50 * 50
* The first of column and the end of the row indicate the sum of the black square labels and the sum of the white square labels, respectively.
* All square labels shall be not less than 1 and not more than 9.
#### Build & Execute(+input file)
      gcc numberCross.c -o num
      ./num numbers
#### Input File(numbers)
      20 23 30 29 34 6 9 21 19
      8 2 1 8 1 3 5 7 6 18
      9 1 4 2 5 6 3 1 7 28
      3 5 1 4 9 1 3 9 1 8
      8 6 6 3 5 1 1 4 1 4
      8 6 6 2 6 8 3 3 9 31
      8 7 8 8 4 5 2 1 1 18
      4 8 3 5 5 2 1 2 8 24
      1 2 8 8 8 3 7 2 7 22
      8 3 9 5 9 2 1 4 9 35
      
### Output : Output is printed in black(1) or white(0) and if there is no solution then print out “No solution”.
#### Output File 
      1 1 0 1 0 0 1 0 0 
      0 1 1 0 1 0 0 0 0 
      1 1 1 0 1 0 0 1 1 
      1 1 1 1 1 1 1 0 1 
      0 0 0 1 1 0 0 1 1 
      0 1 1 1 0 0 1 1 0 
      0 0 1 0 0 0 1 1 1 
      1 1 1 1 0 1 0 1 0 
      0 0 0 0 1 1 0 1 0 
      
# Makefile
    $ make
    gcc -c -o numberCross.o numberCross.c
    gcc -o num numberCross.o
    $ ./num numbers
* If you want to delete the object file and the executable file
    $ make clean
    
# Files
* https://github.com/kimyouyoung/DiscreteMath_HW1/blob/master/numberCross.c - source code about **Number Cross**
* https://github.com/kimyouyoung/DiscreteMath_HW1/blob/master/numbers - Input File
* https://github.com/kimyouyoung/DiscreteMath_HW1/blob/master/Makefile - Build Script : Makefile
