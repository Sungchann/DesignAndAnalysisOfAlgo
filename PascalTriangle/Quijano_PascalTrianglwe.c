#include <stdio.h>
#include <stdlib.h>

void generateUsingIteration(int );
void generateUsingRecusion(int );

int main (void){
    int numRows, usersChoice;

    do{
        printf("PASCAL TRIANGLE\n");
        printf("Enter number of rows: ");
        scanf("%d", &numRows);
        printf("[1]Generate using Iteration \n[2]Generate using Recursion\n[3]Exit\n");
        printf("Enter option: ");
        scanf("%d," &usersChoice);
        if(usersChoice == 1){
            generateUsingIteration(numRows);
        }
        else if (usersChoice == 2){
            generateUsingRecusion(numRows);
        }
        else if (usersChoice != 3){
            system("cls");
        }
    }while(usersChoice != 3);
    

    return 0; 
}

void generateUsingIteration(int num){
    int numOfValuesInARow =0;
    int valBeforeCurrentVal; 
    int currentVal = 1; 
    int numPlus; 

    for(int x=0; x<num; x++){
        numPlus = 0;

        for(int j=0; j<numOfValuesInARow+x; j++){
            if (j == 0 || j == numOfValuesInARow+1){
                valBeforeCurrentVal = currentVal; 
                printf("%d\t", currentVal);
            }
            else{
                numPlus = valBeforeCurrentVal + currentVal;
                printf("%d", numPlus);
            }
        }
    }

}
