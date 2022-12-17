/* 
    Write a program that reads a file (Lec07Assignment-1.txt) containing 100 points, with data 
    values ranging from 0 to 10. Store all data in an array histArray. This program should 
    use functions to then represent the data as histograms (vertical and horizontal).
    
 * @author
    Remo24
    EEGR409
    Assignment 07

 * */
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define array_length 1000
#define numBins 11
#define INPUT "Lec07Assignment-1.txt"

/* fucntion definitions */
int getBinCount(int histArray[], int num_points, int k);
int getMax(int array[], int num_points);
int getMin(int array[], int num_points);
void print_Index(int freqVal[],int binVals[],int num_points);
void print_Horizontal_hist(int freqVal[],int binVals[],int num_points);
void print_Vertical_hist(int freqVal[],int binVals[]);
void print_Vertical_hist_block(int freqVal[],int binVals[]);

int getBinCount(int histArray[], int num_points, int k){
    int count=0;
    for(int i=0;i<num_points;i++){
        if(histArray[i]==k){
            count++;
        }
    }
    return count;
}
int getMax(int array[], int num_points){
    double max_value=0;
    /* Determining maximum value of the array received as argument*/
    for(int i=0;i<num_points;i++){
        if(array[i]>max_value)
        {
            max_value=array[i];
        }
    }
    return max_value;
}
int getMin(int array[], int num_points){
    double min_value=0;
    /* Determining minimum value of the array received as argument*/
    min_value=array[0];
    for(int i=0;i<num_points;i++){
        if(array[i]<min_value)
        {
            min_value=array[i];
        }
    }
    return min_value;
}

/* Function to print occurance frequency based on bin number */
void print_Index(int freqVal[],int binVals[],int num_points){
    printf("---------------------------------\n");
    printf("The file contains %d data points.\n",num_points);
    printf("+-------+----------+\n");
    printf("| Index | Occurance|\n");
    printf("+-------+----------+\n");
    for(int m=0;m<numBins;m++){
        printf("|Bin_%d\t| %2d times |\n",binVals[m+1],freqVal[m]);
    }
    printf("+-------+----------+\n");
}

/* function to print horizontal histogram */
void print_Horizontal_hist(int freqVal[],int binVals[],int num_points){

    printf("---------------------------------\n");
    printf("Horizontal Histogram \n");
    printf("---------------------------------\n");
    for(int i=0;i<numBins;i++){
        printf(" %2d |",i);
        for(int j=0;j<freqVal[i];j++){
            printf("*");
        }
        printf("[%d]",freqVal[i]);
        printf("\n");
    }
    printf("\t--------------------------\n");
}

/* function to print vertical histogram */
void print_Vertical_hist(int freqVal[],int binVals[]){
      printf("---------------------------------\n");
      printf("Vertical Histogram \n");
      printf("---------------------------------\n");
      for(int i=getMax(freqVal,numBins);i>0;i--){
        printf(" %2d |",i);
        for(int j=0;j<numBins;++j){
            if(freqVal[j]<i){
                printf("   ");
            }else
            printf(" * ");
        }printf("\n");
        
      }
      printf("\t  --------------------------------\n");
      printf("\t ");
      for(int k=0;k<numBins;k++){
            printf(" %d ",k);
        }     
}

/* function to print vertical histogram using block charaters */
void print_Vertical_hist_block(int freqVal[],int binVals[]){

      printf("\n---------------------------------\n");
      printf("Vertical Histogram \n");
      printf("---------------------------------\n");
      for(int i=getMax(freqVal,numBins);i>0;i--){
        printf(" %2d |",i);
        for(int j=0;j<numBins;++j){
            if(freqVal[j]<i){
                printf("   ");
            }else
            printf(" \xE2\x96\x92 ");
        }printf("\n");
        
      }
      printf("\t  --------------------------------\n");
      printf("\t ");
      for(int k=0;k<numBins;k++){
            printf(" %d ",k);
        }     
}

int main(){

    FILE *infile;
    int histArray[array_length], freqVal[array_length], binVals[array_length];
    int i=0; //used to keep count in while loop
    int num_points=0; //used to hold number of data points in files

    infile = fopen(INPUT,"r");

    if(infile==((void *)0))
    {
        printf("ERROR: Unable to open file \n");
    }
    else
    {
        while((fscanf(infile,"%d", &histArray[i]))==1)
            i++;

        num_points=i;

        /* Passing histArray to function getBinCount to store in freqVal (frequency of occurance)*/
        for(int j=0;j<num_points;j++)
        {
            int k=j;
            freqVal[j]=getBinCount(histArray,num_points,k);
        }
        for(int l=0;l<=numBins;l++)
        {binVals[l]=l;}

        print_Index(freqVal,binVals,num_points);
        print_Horizontal_hist(freqVal,binVals,num_points);
        print_Vertical_hist(freqVal,binVals);
        print_Vertical_hist_block(freqVal,binVals);
    }

}
