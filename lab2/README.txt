----------Acknowledgement of Bugs-------------
-If decimal numbers are used in the terminal arguments, they are rounded down

1) What was accomplished in this lab
A program solves the "Towers of Hanoi" problem using a recursive algorithm, defined in the towers.c code by author K. Clowes. Prints moves done in stdout, while each recursive call and a description of each move is printed to stderr. The towers function is called by towersMain, in which the arguments for the number of discs, initial starting postion of the stack, and the destination which the stack is to be moved, are validated in order to ensure the program only outputs a solution when the parameters provided reflect a real towers of hanoi scenario.

2) Requirement 1 Questions
	1. towers(4,2,1)
	2. 31
	3. "2 3" as in a move from tower 2 to tower 3
	4. towers(3,2,3)

	Q: Towers(8,2,1) will print 2^8-1=255 lines to STDout, which is where the moves are printed to


 
