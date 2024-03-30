#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void getCoefficientsAndConstant(int [], int);
void displayEquation(int [], int);
void getPolyValUsingHorner(int [], int, int);
void getPolyValUsingBruteForce(int [], int, int);

int main (void){
    int arrayOfCoefficientsAndConstant[]={};
    int highestExponent, valueOfX;
    int usersOption;

    do{
        printf("[1]Find the value of a polynomial \n[2]Exit \nEnter option: ");
        scanf("%d", &usersOption);
        switch(usersOption){
            case 1:{
                //CREATING POLYNOMIAL EQUATION (Coefficient, Constant, HighestExpo, ValueOfX)
                system("cls");
                printf("Enter highest exponent of your equation: ");
                scanf("%d", &highestExponent);
                getCoefficientsAndConstant(arrayOfCoefficientsAndConstant, highestExponent);
                system("cls");
                displayEquation(arrayOfCoefficientsAndConstant, highestExponent);
                printf("Enter value of x: ");
                scanf("%d", &valueOfX);

                do{
                    printf("[1]Horner's Algorithm \n[2]Brute Force Algorithm \nSelect Option ");
                    scanf("%d", &usersOption);
                    
                    if(usersOption == 1){
                        system("cls");
                        displayEquation(arrayOfCoefficientsAndConstant, highestExponent);
                        printf("x = %d\n", valueOfX);
			
                        getPolyValUsingHorner(arrayOfCoefficientsAndConstant, highestExponent, valueOfX);
                    }
                    else if(usersOption == 2){
                        system("cls");
                        displayEquation(arrayOfCoefficientsAndConstant, highestExponent);
                        printf("x = %d\n", valueOfX);
                        getPolyValUsingBruteForce(arrayOfCoefficientsAndConstant, highestExponent, valueOfX);
                    }
                    else{
                        system("cls");
                    }
                }while(usersOption != 1 && usersOption != 2);
                usersOption = 0;
                break;
            }
            case 2:{
                break;
            }
            default:{
                system("cls");
                break;
            }
        }
    }while(usersOption != 2);
    return 0;
}

void getCoefficientsAndConstant(int arrayOfCoefficientsAndConstant[], int highExpo){
    printf("Make sure to enter 0 when the term does not exist\n");

    for (int x=0; x<=highExpo; x++){ //Operator is less than and equal since constant is included
        if (x==0){
            printf("Enter constant value: ");
            scanf("%d", &arrayOfCoefficientsAndConstant[x]);
        }
        else{
            printf("Enter coefficient value x^%d: ", x);
            scanf("%d", &arrayOfCoefficientsAndConstant[x]);
        }
    }
}

void displayEquation(int arrayOfCoefficientsAndConstant[], int highExpo){
    printf("THE POLYNOMIAL EQUATION\n");

    for(int x=highExpo; x>=0; x--){
        if (arrayOfCoefficientsAndConstant[x] != 0){
            //DISPLAYING TERMS
            if(x!=0){
                printf("%dx^%d ", arrayOfCoefficientsAndConstant[x], x);
            }
            else{
                printf("%d", arrayOfCoefficientsAndConstant[x]);
            }
            
            //DISPLAYING OPERATIONS BETWEEN TERMS
            if(arrayOfCoefficientsAndConstant[x-1] >= 0 && x!=0){
                printf("+ ");
            }
        }
    }
    printf("\n");
}

void getPolyValUsingHorner(int arrayOfCoefficientsAndConstant[], int highExpo, int xVal){
    int result = arrayOfCoefficientsAndConstant[highExpo]; //Storing the coefficient with high expo or bringing down
	
	//Displaying Coefficients Purposes
	printf("Coefficients are: ");
	for(int x=highExpo; x>=0; x--){
    	printf("%d ", arrayOfCoefficientsAndConstant[x]);
    }

    for(int x=highExpo-1; x>=0; x--){ //Minus one since coefficient with high expo is stored already in result variable
    	result *= xVal;
        result += arrayOfCoefficientsAndConstant[x];
    }

    printf("\nValue is %d\n\n", result);
}

void getPolyValUsingBruteForce(int arrayOfCoefficientsAndConstant[], int highExpo, int xVal){
    int result = 0;
    
    for(int x=highExpo; x>=0; x--){
        result += (arrayOfCoefficientsAndConstant[x]*(pow(xVal, x)));
    }

    printf("Value is %d\n\n", result);
}