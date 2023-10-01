

------what you achieved (2-3 sentences ea.)-----------
In this lab, a program was ultimately created which can sort, in ascending order, any desired sequence of integers defined by the user's terminal arguments, and then output it using to the standard output. Insertion Sort was the chosen sorting algorithm in this implementation. If no terms are entered when invoking the test command, the default sequence is sorted and that is the output instead.

--------awknowledgement of any any bugs-------
	-If non-numbers are used as arguments, there is no error message, instead the String will be given an integer value of 0.
	-If decimal numbers are used in the terminal arguments, they are rounded down 

--answer to final q (explain or write the few lines of codes)
This can be implemented by simply creating a betterSort header and including it in mySort, and then calling the betterSort function within the mySort function and passing it the following parameters using the following code:

i.e

#include <stdio.h>
void mySort(int d[], unsigned int n){
	betterSort(d[], d[0], d[n-1]);			
}

**It was acc betterSort(d[],0,n-1); since they want the portion of the array bto be sorted which is defined by the indexes, not the numbers themselves which of which is ambiguos for when it comes to finding that portion.
