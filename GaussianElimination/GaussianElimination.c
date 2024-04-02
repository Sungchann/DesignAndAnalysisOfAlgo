#include <stdio.h>
#include <stdlib.h>

const int COLUMN_MAX_SIZE = 50; 
void getMatrixCoefficientsAndConstant(int, int, float [][COLUMN_MAX_SIZE]);
void displayMatrix(int, int, float [][COLUMN_MAX_SIZE]);
void displayCoefficientsAndConstant(int, int, float [][COLUMN_MAX_SIZE]);
void solveByGaussianElimiation(int, int, float [][COLUMN_MAX_SIZE]);
float getLCM(int, int);
float getGCD(int, int);

int main (void){
    int usersOption;
    int numRows, highestSubNumber;

    do{
        printf("[1]Try Gaussian Elimination \n[2]Exit \nChoose option: ");
        scanf("%d", &usersOption);
        switch(usersOption){
            case 1:{
            	system("cls");
                //Getting values for creating matrix
                printf("Gaussian Elimination\n");
                printf("Enter number of rows: ");
                scanf("%d", &numRows);

                printf("\nLet C = constant \nLet n a number where -> x sub n\n");
                printf("xn + xn+1 + xn+2 ... xn+n = C\n");
                printf("\nEnter the highest value of n: ");
                scanf("%d", &highestSubNumber);

                //Initialize and Getting coefficients matrix
                //Interation for column will include 0 as since constant will be included
                float coefficientsAndConstantMatrix[numRows][COLUMN_MAX_SIZE];
                getMatrixCoefficientsAndConstant(numRows, highestSubNumber, coefficientsAndConstantMatrix);
                displayMatrix(numRows, highestSubNumber, coefficientsAndConstantMatrix);
                if(usersOption == 1){
                	displayCoefficientsAndConstant(numRows, highestSubNumber, coefficientsAndConstantMatrix);
                	solveByGaussianElimiation(numRows, highestSubNumber, coefficientsAndConstantMatrix);
				}
				usersOption=0; //RESET
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

void getMatrixCoefficientsAndConstant(int rows, int columns, float coefficientsAndConstantMatrix[][COLUMN_MAX_SIZE]){
    
    for(int r=0; r<rows; r++){
        printf("\nRow %d\n", r+1);
        for(int c=0; c<=columns; c++){ //Interation for column will include 0 as since constant will be included
            if(c!=columns){ 
                printf("Enter coefficent for x%d: ", c+1);
                scanf("%f", &coefficientsAndConstantMatrix[r][c]);
            }
            else{
                printf("Enter constant: ");
                scanf("%f", &coefficientsAndConstantMatrix[r][c]);
            }
            
        }
    }
}

void displayMatrix(int rows, int columns, float coefficientsAndConstantMatrix[][COLUMN_MAX_SIZE]){
	
	system("cls");
	printf("EQUATIONS ARE: \n");
    for(int r=0; r<rows; r++){
        for(int c=0; c<=columns; c++){ //Interation for column will include 0 as since constant will be included
            if(c!=columns){ 
                printf("%.1fx%d ", coefficientsAndConstantMatrix[r][c], c+1);
            }
            else{
                printf(" = %.1f", coefficientsAndConstantMatrix[r][c]);
            }
            if (coefficientsAndConstantMatrix[r][c+1] >= 0 && c != columns){
                printf("+ ");
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

void displayCoefficientsAndConstant(int rows, int columns, float coefficientsAndConstantMatrix[][COLUMN_MAX_SIZE]){
	
	system("cls");
	printf("EQUATIONS ARE: \n");
    for(int r=0; r<rows; r++){
        for(int c=0; c<=columns; c++){ //Interation for column will include 0 as since constant will be included
            if(c!=columns){ 
                printf("%.1f\t", coefficientsAndConstantMatrix[r][c], c+1);
            }
            else{
                printf(" = %.1f", coefficientsAndConstantMatrix[r][c]);
            }
        }
        printf("\n");
    }
    printf("\n\n");
}

void solveByGaussianElimiation(int rows, int columns, float coefficientsAndConstantMatrix[][COLUMN_MAX_SIZE]) {
    for (int k = 0; k < rows - 1; k++) {
        for (int i = k + 1; i < rows; i++) {
            float factor = coefficientsAndConstantMatrix[i][k] / coefficientsAndConstantMatrix[k][k];
            for (int j = k; j <= columns; j++) {
                coefficientsAndConstantMatrix[i][j] -= factor * coefficientsAndConstantMatrix[k][j];
            }
        }
    }
	displayCoefficientsAndConstant(rows, columns, coefficientsAndConstantMatrix);
	
    // Back substitution
    float solution[rows];
    for (int i = rows - 1; i >= 0; i--) {
        float sum = 0;
        for (int j = i + 1; j < rows; j++) {
            sum += coefficientsAndConstantMatrix[i][j] * solution[j];
        }
        solution[i] = (coefficientsAndConstantMatrix[i][columns] - sum) / coefficientsAndConstantMatrix[i][i];
    }

    // Display solution
    printf("Solution:\n");
    for (int i = 0; i < rows; i++) {
        printf("x%d = %.2f\n", i + 1, solution[i]);
    }
}
