/*
 Owner: James Quijano
 Initial Approach: 
 	[1] Check first and last array if the same, if not dont accept
	[2] If same, check all characters if a or b, if yes then accept, if not dont accept
	
 Submitted Approach:
 	[1] Initialize state = 0 and input = 0
	[2] If empty is submitted then accept
	[3] If a single character is submitted [a or b] then accept
	[4] Draw the FA and initialize the transition table based on the FA,
	[5] Tracing Method using the functions  
*/
#include <stdio.h>
#include <string.h>

int checkInputCode(char ch);
int check(char *st);
int isAtFinalState(int state);

int main(void) {
	char getString[80];
	char getOption;
	
	do {
		printf("Enter the string: ");
		gets(getString);
		fflush(stdin);
		
		strlwr(getString);
		
		if (check(getString)){
			printf("%s is accepted!\n", getString);
		}
		else{
			printf("%s is not accepted!\n",getString);
		}
		
		printf("\n[1]Wish to continue\n[0 or any number]Quit\n");
		printf("Enter option: ");
		scanf("%d", &getOption);
		fflush(stdin);
		printf("\n");
	} while (getOption == 1);

	return 0;
}
int checkInputCode(char ch) {
  	int convert = 0;
  
  	switch (ch) {
		case 'a':{
			convert = 0;
			break;
		}
		case 'b':{
			convert = 1;
			break;
		}
		default:{
			convert = -1;
			break;
		}
  	}
  	return convert;
}

int check(char *st) {
	int isAccepted = 0;
	int length = strlen(st)-1;
	int getStringIndex =0, state=0, input=0;
	char transitionTable[5][2] = {{1,2}, {1,3}, {4,2}, {1,3}, {4,2}}; 
	
	while(st[getStringIndex] != '\0'){
		input = checkInputCode(st[getStringIndex]);
		if(input == -1){
			state = -1;
			break;
		}
		state = transitionTable[state][input];
		getStringIndex++;
	}
	
 	return isAtFinalState(state);
}

int isAtFinalState(int state){
	if (state == 2 || state == 1 || state == 0){
		return 1;
	}else{
		return 0;
	}
}

