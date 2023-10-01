#include <stdlib.h>
#include <stdio.h>
#include "towers.h"

int main(int argc, char **argv)
{
    int n = 3;
    int from = 1;
    int dest = 2;

	if (argc > 2) {		// for more than 1 arguments (the only other option is 3, but that is validated later), the first argument is set to the number of discs
        n = atoi(argv[1]);
	}
		
	if(argc == 3 || argc >4){	//check if there is a valid number of arguments
		fprintf(stderr, "Invalid Number of Arguments: Only 0, 1 or 3 arguments are permitted.");
		exit(1);
	}

	if (argc == 4){	//(when it has 3 arguments, which is the only option other than 1 or none)

		if ( atoi(argv[2]) >3 || atoi(argv[2]) <1 || atoi(argv[3]) >3 || atoi(argv[3]) <1){	//validate from and dest arguments are either 1,2, or 3
		fprintf(stderr, "Invalid Arguments: The from and destination parameters must can only be the following: 1 (left rod), 2 (middle rod) or 3(right rod).");
		exit(2);
		}

		if ( atoi(argv[2]) == atoi(argv[3])){	//validate that from and dest are not the same
		fprintf(stderr, "Invalid Arguments: The from and destination paramerters cannot be the same.");
		exit(3);
		}
		
		if ( atoi(argv[1]) <1){		//validate number of discs is 1 or more
		fprintf(stderr, "Invalid Arguments: The number of discs n, must be atleast 1 and cannot be negative.");
		exit(4);
		}

		from = atoi(argv[2]);
		dest = atoi(argv[3]);
	}
		
    towers(n, from, dest);
    exit(0);
}

