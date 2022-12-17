/*
 * Write a program that enables the user to search for all amino acid molecules that meet
 * the search requirements. The user can enter the minimum and maximum number of molecules
 * for each element and the program will display all amino acids whose number of elements
 * match the search criteria along with the corresponding molecular weights.
 *
 * @author
    Remo24
    EEGR409
    Mid_Term

 * */

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#include<stdbool.h>
#define array_length 7 //arbitrary value for array length

//Atomic weights
#define Oxygen (float)15.99994
#define Carbon 12.011
#define Nitrogen 14.00674
#define Sulfur 32.066
#define Hydrogen 1.00794

//input file
#define INPUT "Midterm_Data.txt"


//Global variables
int min_array[array_length];
int max_array[array_length];
bool srchRslts[array_length] = {false};

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

int main(){
    FILE * infile;
    int O[array_length],C[array_length],N[array_length],S[array_length],H[array_length];
    int i=0; //used to keep track of loop count
    float molecular_weight;
    infile=fopen(INPUT,"r");

    if(infile==NULL){
        printf("Error: file not opened\n");
    }
    else
    {while(!feof(infile)) {
            fscanf(infile, "%d %d %d %d %d", &O[i], &C[i], &N[i], &S[i], &H[i]);
            //printf("%d %d %d %d %d\n",O[i], C[i], N[i], S[i], H[i]);
            i++;
        }

        printf("Query Amino Acids Molecules\n");
        printf("----------------------------\n");
        checkInput();
        for(int j=0;j<array_length;j++){
            if((O[j]>=min_array[0] && O[j]<=max_array[0]) && (C[j]>=min_array[1] && C[j]<=max_array[1]) && (N[j]>=min_array[2] && N[j]<=max_array[2]) && (S[j]>=min_array[3] && S[j]<=max_array[1]) && (H[j]>=min_array[4] && H[j]<=max_array[4]))
            {
                srchRslts[j]=true;
            }else
            {
                srchRslts[j]=false;
            }
        }

        printf("Search Results for Your Query\n");
        printf("----------------------------\n");
        for(int k=0;k<array_length;k++){
            if(srchRslts[k]==true){
                molecular_weight = (O[k]*Oxygen)+(C[k]*Carbon)+(N[k]*Nitrogen)+(S[k]*Sulfur)+(H[k]*Hydrogen);
                printf("( %f )\n",molecular_weight);
            }

        }


    }
return 0;
}
