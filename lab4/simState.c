#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//----------------------variables--------------------------------//
char input[15]; 

char stateTable[8][3] ={
		{'A', 'D', 'E'},
		{'B', 'C', 'B'},
		{'C', 'H', 'G'},
		{'D', 'B', 'F'},
		{'E', 'A', 'B'},
		{'F', 'G', 'A'},
		{'G', 'E', 'H'},
		{'H', 'F', 'D'}
	};

bool delFlag[8]=
	{false, false, false, false,
	 false, false, false, false};

int state = 4;
int inputDig;

bool garbageFlag; //just used when scanning through `reachability to see if any undeleted states are unreachable

bool reachable[]={true,true,true,true,true,true,true,true}; //all states should default be true before running g or d commands. Tf need to add a reset after each while iteration 

//----------------------------helper functions--------------------------//

bool isValidStateName(char c){
	if(
		c=='A'||
	    c=='B'||
		c=='C'||
		c=='D'||
		c=='E'||
		c=='F'||
		c=='G'||
		c=='H'
		)return true;

	return false;
}

int toIndex(char state){
	switch(state){
		case 'A': return 0; break;
		case 'B': return 1; break;
		case 'C': return 2; break;
		case 'D': return 3; break;
		case 'E': return 4; break;
		case 'F': return 5; break;
		case 'G': return 6; break;
		case 'H': return 7; break;
		default:
			printf("L usage\n");
		return -1;
	}
}

char toChar(int state){
	switch(state){
		case 0: return 'A'; break;
		case 1: return 'B'; break;
		case 2: return 'C'; break;
		case 3: return 'D'; break;
		case 4: return 'E'; break;
		case 5: return 'F'; break;
		case 6: return 'G'; break;
		case 7: return 'H'; break;
		default:
			printf("L usage\n");
			return 'L';
	}
}

//REQUIRES: index, x, of current state, s.
//MODIFIES:reachable[x](will be temporary since it is to be reset)
//EFFECTS: Assigns a true value to state s' reachable[x] and to reachable[x1]reachable[x2]..., where x1,x2... are the indicies which correspond to the children states of s.
void recursive(int x){
	reachable[x]=true;	//since current state obvi reachable
	
	//if statements prevents recursive loop by skipping the binary search of states that were already found to be reachable(True), and those which are deleted(True)
	if(		reachable[toIndex(stateTable[x][0+1])] == false		)				
		recursive(toIndex(stateTable[x][0+1]));	//confirms reachable the 0-branch child (i.e left branch) and it's children and so on
	if(		reachable[toIndex(stateTable[x][1+1])] == false		)				
		recursive(toIndex(stateTable[x][1+1]));	//confirms reachable the 1-branch child (i.e right branch) and it's children and so on
}

	
//REQUIRES: reachable[] is reset
//MODIFIES: reachable[]
//EFFECTS: sets all undeleted states, x, to reachable[x]=false. Then, calls recursive(x)
void reachability() 
{	
	for(int i=0;i<8;i++){
		if (delFlag[i]==false) reachable[i]=false;	//non deleted values will be false until checked, only non deleted will be output
	}
	int x = state; //so the current state itself does not get modified by recursive(x)
	recursive(x);
	//at this point, all undeleted states' reachable[] value should be true if it is reacable.	
}

//-------------------------------main function------------------------//

int main(int argc, char * argv[])
{
	printf("Starting state: %c \n" ,stateTable[state][0]);
	printf("Enter a command.\n");
    while(1==1){	///to take commands until ctrl+d
		//printf("Debug\n");

		for(int i=0;i<15;i++){
			input[i]=0;	
		}//reset input

		scanf(" %[^\n]s",input);	//scans until it sees newline(enter). ***I assume it dosen't take the newline character, and that empty elements in the char array have a vlaue of 0. That is what mt command length checks arecoded w/the assumption of.The space apparently consumes the new line
		//fflush(stdin);

        inputDig = 1;	//in case the advance 1 is ran, this must be 1 since advance input 1 switch case is used for 0 as well.
        switch(input[0]){

            case 'c':
                if
                    (
                    //*** (input[1]==' ' && input[3]==' ')&&	//check if spaces are used
                    (input[2]=='0' || input[2]=='1')&&	//checks if binary-input param is valid
                    isValidStateName(input[4]) //checks if state param is valid
					&& input[5]==0						//*?: should check if there are no more follow-up inputs
                    )					
                {
                    stateTable[state][ ( (int)(input[2]-'0') ) +1]=input[4];
                }else{printf("Invalid Input: change command was not used properly...\n");}
                break;

            case 'd':
                garbageFlag=false;	//reset garbage checker
				reachability();	//edits reachable
				for(int i=0;i<8;i++){
                	if(delFlag[i]==false && reachable[i]==false){garbageFlag=true;}
                }//checks if there is garbage
                if(input[1]==0){	//on condition of only d arg w/ no state defined
                    
                    if(garbageFlag==true){
                        printf("Deleted: ");
                        for(int i=0;i<8;i++){
                            if(delFlag[i]==false && reachable[i]==false){
                                printf("%c ",toChar(i) );
                                delFlag[i]=true;
                            }
                        }
                        printf("\n");
                    }else{printf("No states deleted\n");}

					//for a specrific state
		            }else if	
		                (	
		                input[1]==' ' 
		                && isValidStateName(input[2])	
		                && input[3]==0
		                ){
		                if(	(delFlag[toIndex(input[2])]==false) && (reachable[toIndex(input[2])] == false)	){ //if the state is not already deleted and is unreachable
		                    delFlag[toIndex(input[2])]=true;
		                    printf("Deleted.\n");
		                }else{printf("Not deleted.\n");}

                }else{printf("Invalid Input:delete command is invalid. Was not used on it's own or with a valid state.\n");} //invalid delete command

				for(int i=0;i<8;i++){reachable[i]=true;}//reset reachable
                break;
            
            case 'g':	//garbage identify command
				if(input[1]==0){
		            garbageFlag=false;	//reset garbage checker
					reachability();	//edits reachable
		            for(int i=0;i<8;i++){
		                if(delFlag[i]==false && reachable[i]==false){garbageFlag=true;} //if not deleted and not reachable, set garbage flag to true
		            }
		            if(garbageFlag==true){
		                printf("Garbage: ");
		                for(int i=0;i<8;i++){
		                    if(delFlag[i]==false && reachable[i]==false){	//if state is not deleted and unreachable,
		                        printf("%c ",toChar(i) );		//print that state
		                    }
		                }
		                printf("\n");
		            }else{printf("No Garbage\n");}
				
					for(int i=0;i<8;i++){reachable[i]=true;}//reset reachable
				}else{printf("Invalid Input:garbage command should have no follow-up arguments\n");}
                break;

            case 'p':	//print command
                if(input[1]==0){
                    for(int i=0;i<8;i++){
                        if(delFlag[i]==false){
                            printf("%c %c %c\n",
                            stateTable[i][0],stateTable[i][1],stateTable[i][2]);
                        }
                    }
                }else{printf("Invalid Input: print command should have no follow up-arguments\n");}
                break;

            case '0':	//input=0 advance command
                inputDig = 0;
            case '1':	//input=1 advance command
                if(input[1]==0){
                    int nextState=0;
                    while(stateTable[nextState][0] != stateTable[state][inputDig +1]){
                        nextState++;
                    }
                    state=nextState;
                    printf("%c \n",stateTable[state][0]);
                }else{printf("Invalid Input:advance command should have no follow-up arguments\n");}
                break;

            default:	//checks for invalid first input
                printf("Invalid Input.\n");
        }
    }
	exit(0);
}

