/*
 * Write a program that enables the user to search for all amino acid molecules that meet
 * the search requirements. The user can enter the minimum and maximum number of molecules
 * for each element and the program will display all amino acids whose number of elements
 * match the search criteria along with the corresponding molecular weights.
 *
 * @author
    Remo24
    
    

 * */
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>

void checkInput();
void findMatches();
//input file
#define INPUT "Data_Acid_All.txt"
#define nAcids 20
#define nElmnt 5

//Global variables
int dataX[nAcids][nElmnt]={0}; //array to hold data from file
int matchX[nAcids][nElmnt]={0};
char acidX[nAcids][100]; //array to hold names of acids
// Array used to store atomic weights
const double atmic_weight[nElmnt]={15.99994,
                                   12.011,
                                   14.00674,
                                   32.066,
                                   1.00794};
int min_array[nElmnt]; //array used to store min value provided by user
int max_array[nElmnt]; //array used to store min value provided by user
double molecular_weight=0,weightSum=0,AveWeight=0;



//function definition
void checkInput(){
    int i=0;
    while(1) {
        do {
            printf("Enter the Oxygen atom range (min,max): ");
            scanf("%d,%d", &min_array[i], &max_array[i]);
        } while ( min_array[i] < 0 || max_array[i] < 0 );
        i++;
        do {
            printf("Enter the Carbon atom range (min,max): ");
            scanf("%d,%d", &min_array[i], &max_array[i]);
        } while (min_array[i] < 0 || max_array[i] < 0);
        i++;
        do {
            printf("Enter the Nitrogen atom range (min,max): ");
            scanf("%d,%d", &min_array[i], &max_array[i]);
        } while (min_array[i] < 0 || max_array[i] < 0);
        i++;
        do {
            printf("Enter the Sulfur atom range (min,max): ");
            scanf("%d,%d", &min_array[i], &max_array[i]);
        } while (min_array[i] < 0 || max_array[i] < 0);
        i++;
        do {
            printf("Enter the Hydrogen atom range (min,max): ");
            scanf("%d,%d", &min_array[i], &max_array[i]);
        } while (min_array[i] < 0 || max_array[i] < 0);

        break;
    }

}

void findMatches() {
    int rowSum = 0;
    int count=0; //used to keep track of how many acids meet the user query requirement

    //comparing the array data to the user input to generate the match array
    for (int i = 0; i < nAcids; i++) {
        for (int j = 0; j < nElmnt; j++) {
            if ((dataX[i][j] >= min_array[j]) && (dataX[i][j] <= max_array[j])) {
                matchX[i][j] = 1;
            }
        }
    }
    

    //for loop to compute the molecular weight of the acid based on meeting the query request
    for (int i = 0; i < nAcids; i++) {
        rowSum = 0;
        for (int j = 0; j < nElmnt; j++) {
            rowSum += matchX[i][j];
            if (rowSum == 5) {
                count+=1;
                molecular_weight = (dataX[i][0] * atmic_weight[0]) + (dataX[i][1] * atmic_weight[1]) +
                                   (dataX[i][2] * atmic_weight[2]) + (dataX[i][3] * atmic_weight[3]) +
                                   (dataX[i][4] * atmic_weight[4]);
                weightSum+=molecular_weight;
                printf("%13s (%2lf) ", acidX[i],molecular_weight);
            }
        }
        printf("\n");
    }

    if(count!=0) {
        AveWeight = weightSum / count;
        printf("---------------------------------------\n");
        printf("Average weights of all found Acids %2lf\n", AveWeight);
    }
    else
    {
        printf("----------------------------\n");
        printf("No Results match your query.\n");
    }
}


int main(){

    FILE *infile = fopen(INPUT,"r");
    int i=0; //used to keep track of loop count

    if(infile==NULL){
        printf("Error: File unable to be opened");
    }
    else
    {
        while(!feof(infile)) {
            fscanf(infile, "%s %d %d %d %d %d", &acidX[i], &dataX[i][0], &dataX[i][1], &dataX[i][2], &dataX[i][3],
                          &dataX[i][4]);
            i++;
        }
        fclose(infile);
        printf("MiniProject_02: Query Amino Acids Molecules\n");
        printf("-------------------------------------------\n");
        checkInput();
        printf("\nThe file contains %d data points.\n",i);
        printf("------------------------------------\n");

        //printing data array (dataX)
        for (int k = 0; k < nAcids; k++){
            printf(" %13s ",acidX[k]);
            for(int j=0;j<nElmnt;j++){
                printf(" %2d ",dataX[k][j]);
            }
            printf("\n");
        }

        printf("\n");
        printf("Search Results for Your Query\n");
        printf("-----------------------------");
        findMatches();
    }

    return 0 ;
}
