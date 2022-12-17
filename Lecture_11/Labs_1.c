/*
 * Lab 1 : Use the previous code to read an N points from the same file "falseNeg.txt
 *          - store in an array origArr
 *          - write another function flipArray to flip origArr element using pointers
 *          - Display the original and flipped array in the main
 *
 * *@author
        Remo24
        EEGR409
        Lect_11_Labs_F22
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

/* defining file to pull data from*/
#define DATAFILE "FalseNeg.txt"

/* function used to flip the values in the array*/
void flipArray(int *origArr, int N);

void flipArray(int *origArr, int N){
        int *left = &origArr[0]; // creating a pointer to the first element
        int *right = &origArr[N-1]; //creating a pointer to the last element
        int temp;

        //using a while loop to swap array elements
        while(left < right){
            temp = *left;
            *left = *right;
            *right = temp;

            *left++;
            *right--;
        }
}

int main(){

    int N;
    printf("Please enter the number of data points needed: ");
    scanf("%d",&N);
    while(N<1){
        printf("Please enter a positive value, N>1: ");
        scanf("%d",&N);
    }
    int *origArr;
    int *origArrCopy;
    origArr = (int *)malloc(N* sizeof(int));
    origArrCopy = (int *)malloc(N* sizeof(int));
    FILE *innData = fopen(DATAFILE,"r");

    if(innData == NULL){
        printf("Error: file unable to open\n");
    }
    else {
        for (int i = 0; i < N; i++)
            fscanf(innData, "%d", &origArr[i]);
        fclose(innData);


        // copying saved data to a duplicate array "origArrCopy"
        for (int i = 0; i < N; i++) {
            *(origArrCopy + i) = *(origArr + i);
        }
        //flipping the Array origArr
        flipArray(origArr, N);
        // printing the saved data from the array origArr
        printf("+--------+------------------+----------------------+\n");
        printf("| Index  |    Original      |       Flipped        |\n");
        printf("+--------+------------------+----------------------+\n");
        for (int i = 0; i < N; i++) {
            printf("|   %2d   |  origArr[%2d]=%2d  |   flipArr[%2d]= %2d    |\n", i, i, origArrCopy[i], i, origArr[i]);
        }
        printf("+--------+------------------+----------------------+\n");
        free(origArr);
        free(origArrCopy);

    }
    return 0;
}

