//includes the getchar function used in given code:
//int getchar(void) <--gets a character (an unsigned char) from stdin 
#include <stdio.h>

#include <stdlib.h>
#include <stdbool.h>

//void strncat(tag, &ch,1); 
//int strcmp (const char* str1, const char* str2);
#include <string.h>

//declare sseveral function useful for testing and mapping characters,particularly
//int isalpha(int c) :This function checks whether the passed character is alphabetic.
#include <ctype.h>

//variables w/ extern keyword are available globally throughout the function execution

//methods with the extern keyword are defined outside of this c source code file
extern char *  pop(); //return a character pointer(string)
extern void push(char *);	//takes a character pointer(string)
extern int isEmpty(); 
//no need to give the "string" a name, the pointer that will be passed already points to it, just as a variable name wouldS

int main(int argc, char * argv[])
{
	int ch;	
	bool isTag=false;
	bool isEndTag=false;
	bool toPop=false;
	char tag[100] = "";
	char * temp;
	
	while ((ch = getchar()) != EOF) { //ctrl+D gives EOF
		
		//skips any invalid characters
		if (!(isalpha(ch) || ch == '>' || ch == '<' || ch == '/'))continue;	

		switch (ch){
			//we know the characters which follow are part of a tag
			case '<':
				isTag=true;
				break;
			//we know more specifically that the tag is an end tag
			case '/':
				if(isTag){isEndTag=true;} //wont care if the slash is somehwere else in the tag***
				break;

			case '>':
				if(isTag && isEndTag){ //if terminating start tag
					toPop=true;
					isTag=false;
				}
				else if(isTag && !isEndTag){	//if termanating end tag
					temp= (char*) malloc(100 * sizeof(char));
					temp = tag;	
//i think think tag has to be the same type an pointer tpye or whatever to work with the push. I'm not sure what tp multiply char size yet either, if at all
					push(tag);	//how to put string??
					isTag=false;
				}
				else{	//if the character was used before a <
					//ignore
				}
				break;
					
			//if currently inputting a tag, add the character to the tag string. Otherwise, we should ignore the character 				
			default:
				if(isTag){ strncat(tag, (char *)&ch, 1); }		
		}//end of switch
		
		//execute the pop
		if(toPop){
			temp=(char*) malloc(100 * sizeof(char)); //need to fix this too
			temp=pop();
			if( strcmp(tag, temp) != 0 ){ //does the pop (?), and compares it to tag. if they are not the same,	****tag and pop comparison problem:
				fprintf(stderr, "Invalid XML");
				break;	//stop the algoritm
			}
			toPop=false;
		}


  }
	if(isEmpty() !=0)
		fprintf(stderr, "Valid XML");
	else
		fprintf(stderr, "Invalid XML");
  exit(0);
}
