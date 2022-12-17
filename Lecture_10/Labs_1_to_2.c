/*
 * lab_01: Write a C program with a void function called getMinMax() that
 *          accepts a 2D array dataX (read from the file Midterm_Data.txt
 *          and finds its maximum and minimum values.
 *              - the function should accept the 2D array (dataX) and two pointers
 *                  for the min and max values (two variables)
 *              - the size of dataX is 7x5 and should be defined as symbolic constant
 *              - print the values in the main function.
 *  Lab_02: Write a C program to read a file "charTest.txt" fromm canvas.
 *           Based on the text provided by the user will be cross-referenced
 *           with the data in the file to find number of occurrences.
 *              - long string is read from data file.
 *              - short string is input from user.
 *
 *@author
    Remo24
    EEGR409
    Lect_10_Labs_F22
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/*----------------------------
    This is Lecture 10 Lab 01
    --------------------------*/
//Global variables
#define INPUT "Midterm_Data.txt"
#define dataX_rows 7
#define dataX_cols 5
int min_value = 0, max_value =0;
int *min = &min_value;
int *max = &max_value;
int dataX[dataX_rows][dataX_cols];
void getMinMax(int dataX[dataX_rows][dataX_cols],int *min,int *max);

void getMinMax(int dataX[dataX_rows][dataX_cols],int *min,int *max){
    /* determining minimum value */
    //*min = dataX[0][0];
    for(int k=0;k<dataX_rows;k++){
        for (int l = 0; l <dataX_cols; l++) {
            if(dataX[k][l]< *min){
                *min = dataX[k][l];
            }
        }
    }

    /* determining maximum value */
    //*max = dataX[0][0];
    for(int k=0;k<dataX_rows;k++){
        for (int l = 0; l <dataX_cols; l++) {
            if(dataX[k][l]> *max){
                *max = dataX[k][l];
            }
        }
    }
}
int mian_01(){

    FILE *infile = fopen(INPUT,"r");
    int i=0; // used to keep count in while loop

    if(infile==NULL)
    {
        printf("Error: File unable to be found\n");
    }
    else
    {
        while(!feof(infile)){
            fscanf(infile,"%d %d %d %d %d", &dataX[i][0],&dataX[i][1],&dataX[i][2],&dataX[i][3],&dataX[i][4]);
            i++;
        }
    }

    printf("The file contains tabulated data of %d rows\n------------------------\n",i);
    for(int k=0;k<dataX_rows;k++){
        for (int l = 0; l <dataX_cols; l++) {
            printf(" %2d  ", dataX[k][l]);
        }
        printf("\n");
    }
    printf("------------------------\n");
    getMinMax(dataX,min,max);
    printf("Largest value in dataX is: %2d\n", max_value);
    printf("Smallest value in dataX is: %2d\n",min_value);

    fclose(infile);
    return 0;
}

/*----------------------------
    This is Lecture 10 Lab 02
    --------------------------*/
/* Global variables */
#define INPUT_FILE "charTest.txt"
#define long 10000
#define short 100
char longStr[long];
char shortStr[short];
char *ptr1 = longStr, *ptr2=shortStr;

/* function used to compute the occurrence of the string inputted by the user in the long string */
void occurrence(char longStr[], char shortStr[]);

void occurrence(char longStr[], char shortStr[]){
    int count = 0;
    while((ptr1 = strstr(ptr1,ptr2)) !=NULL)
    {
        printf("Found location %ld \n", ptr1-longStr+1);
        count++;
        ptr1 += strlen(shortStr);
    }
    printf("---------------------------\n");
    printf("Total number of occurrences is %d \n", count);

}

int main_02(){
    FILE *infile_1 = fopen(INPUT_FILE,"r");
    int i=0;
    if(infile_1 ==NULL){
        printf("Error: file not opened\n");
    }
    else
    {
        while(fgets(longStr,long,infile_1)!=NULL) {
            i++;
        }
    }
    //used to confirm data in the array
    //printf("%s\n",longStr);

    /* Requesting input from user */
    printf("Enter a short string (NO SPACES): ");
    scanf("%s",shortStr);
    /* passing both string to the function */
    occurrence(longStr,shortStr);

    /* closing the file */
    fclose(infile_1);
}
