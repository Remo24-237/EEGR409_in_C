/* 
    Lab_01: Write a C code that read n data points from the user (use a for loop + 
            scanf) and store them in an array dataX. Define the array length as a 
            symbolic constant (use n=6).
            - Get the max value of the array dataX.
            - Sort the array.
            - Print the max value, the original and the sortef array.
    Lab_02: Modify the C code from lab1 in lecture 5, to read the data from file test.txt
            and stores the three recoreds in three arrays "aX1, aX2, aX3". Then make
            the following calculations using four functionss.
            - Maximum, and minimum value of each array (getMax,getMin).
            - Average values of the three (getMean).
            - Standard deviation of values in each array (getSTD).
    Lab_03: Write a program that reads data from a file Lect07Labs.txt, stores the 
            first column ONLY in an array "dArray" and then write a function 
            getKthCount(dArray,nPnts,k) accepts the array dArray, its length, and 
            a int k to determine how many times k occurs in dArray.
    

    @author
    Remo24
     EEGR 409
     Lect_07_Lab_F22
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<ctype.h>
#define array_length 1000

/*----------------------------
    This is Lecture 07 Lab 01
        Modification: Sort array in descending order
    --------------------------*/
#define arrayLen 6

int main_01(){

    float array[arrayLen],array_copy[arrayLen],max_num=0;

    printf("Enter 6 values for the array:\n");
    for(int i=0;i<arrayLen;i++){
        scanf("%f",&array[i]);
    }
    /* printing elements and determining maximum value */
    printf("Here are the numbers you entered\n");
    for(int j=0;j<arrayLen;j++){
        printf("%d: %.1f\n",j,array[j]);
        if(array[j]>=max_num){
            max_num=array[j];
        }
    }
    printf("The maximum value is %.1f. \n",max_num);

    /* Copying array to new array */
    for(int m=0;m<arrayLen;m++){
        array_copy[m]=array[m];
    }
    /* Sorting array*/
    float temp=0;
    for(int k=0;k<arrayLen;k++){
        for(int l=k+1;l<arrayLen;l++){

            if(array_copy[k]<array_copy[l]){
                temp = array_copy[k];
                array_copy[k] = array_copy[l];
                array_copy[l] = temp;
            }
        }
    }
    printf("Sorting results:\n");
    printf("+--------+---------+---------+\n");
    printf("|Index\t |Original |Sorted   |\n");
    printf("+--------+---------+---------+\n");
    for(int i=0;i<arrayLen;i++){
        printf("|%d\t\t |%.1f\t   |%.1f \t |\n",i,array[i],array_copy[i]);
    }
    printf("+----------------------------+\n");
    return 0;
}

/*----------------------------
    This is Lecture 07 Lab 02

    --------------------------*/
#define INPUT_FILE "test.txt"
#define OUTPUT_FILE "newStats.txt"


double getMax(double array[], int num_points);
double getMin(double array[], int num_points);
double getMean(double array[],int num_points);
double getSTD(double array[],int num_points);


double getMax(double array[], int num_points){
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

double getMin(double array[], int num_points){
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

double getMean(double array[], int num_points){
    double avg,sum_points=0;
    /* Determining the mean value of the array recieved as argument*/
    for(int i=0;i<num_points;i++)
       { sum_points +=array[i];
       }
    avg=sum_points/num_points;
return avg;
}

double getSTD(double array[], int num_points){
    /* Determining the standard deviation value of the array received as argument*/
    double num_sum=0, num_var,array_var,array_std;
    num_var= getMean(array,num_points);
    /* Determining the variance of the array received as argument*/
    for(int i=0;i<num_points;i++)
       { 
        num_sum += ((array[i] - num_var)*(array[i] - num_var));
       }
    array_var= num_sum/(num_points-1);
    array_std = sqrt(array_var);
    
    return array_std;
}

int main_02(){

    FILE *infile, *outfile;
    double aX1[array_length], aX2[array_length], aX3[array_length];
    double max_val_aX1,max_val_aX2,max_val_aX3;
    double min_val_aX1,min_val_aX2,min_val_aX3;
    double mean_val_aX1,mean_val_aX2,mean_val_aX3;
    double std_val_aX1,std_val_aX2,std_val_aX3;
    int num_points=0;
    int i=0; // used for while loop count

    infile = fopen(INPUT_FILE,"r");
    outfile = fopen(OUTPUT_FILE,"w");

    /* checking if the file was opened successfully */
    if(infile ==NULL)
    {
        printf("The file could not be opened\n");
    }else {
        
        fprintf(outfile, "\t X1\t X2\t X3\n");
        /* checking for EOF (end of file) */
        while (!feof(infile)) {
            fscanf(infile, "%lf %lf %lf", &aX1[i], &aX2[i], &aX3[i]);
            i++;
        }
        num_points = i - 1;
        for (int j = 0; j < num_points; j++) {
            fprintf(outfile, "\t %.2lf\t %.2lf\t %.2lf\n", aX1[j], aX2[j], aX3[j]);
        }


        max_val_aX1 = getMax(aX1, num_points);
        max_val_aX2 = getMax(aX2, num_points);
        max_val_aX3 = getMax(aX3, num_points);
        min_val_aX1 = getMin(aX1, num_points);
        min_val_aX2 = getMin(aX2, num_points);
        min_val_aX3 = getMin(aX3, num_points);
        mean_val_aX1 = getMean(aX1, num_points);
        mean_val_aX2 = getMean(aX2, num_points);
        mean_val_aX3 = getMean(aX3, num_points);
        std_val_aX1 = getSTD(aX1, num_points);
        std_val_aX2 = getSTD(aX2, num_points);
        std_val_aX3 = getSTD(aX3, num_points);

        /* printing result in the file */
        fprintf(outfile, "--------------------------------------\n");
        fprintf(outfile, "Number of data points in the file = %d\n", num_points);
        fprintf(outfile, "--------------------------------------\n");
        fprintf(outfile, "--------+All Record Statistics+-------\n");
        fprintf(outfile, "--------------------------------------\n");
        fprintf(outfile, "\t X1\t X2\t X3\n");
        fprintf(outfile, "Max: \t%.2lf\t %.2lf\t %4.2lf\n", max_val_aX1, max_val_aX2, max_val_aX3);
        fprintf(outfile, "Min: \t%.2lf\t %.2lf\t %.2lf\n", min_val_aX1, min_val_aX2, min_val_aX3);
        fprintf(outfile, "Avg: \t%.2lf\t %.2lf\t %.2lf\n", mean_val_aX1, mean_val_aX2, mean_val_aX3);
        fprintf(outfile, "STD: \t%.2lf\t %.2lf\t %.2lf\n", std_val_aX1, std_val_aX2, std_val_aX3);
        /* printing result on the console */
        printf("--------------------------------------\n");
        printf("Number of data points in the file = %d\n", num_points);
        printf("--------------------------------------\n");
        printf("--------+All Record Statistics+-------\n");
        printf("--------------------------------------\n");
        printf("\t X1\t\t X2\t\t X3\n");
        printf("Max: %.2lf\t %.2lf\t %.2lf\n", max_val_aX1, max_val_aX2, max_val_aX3);
        printf("Min: %.2lf\t %.2lf\t %.2lf\n", min_val_aX1, min_val_aX2, min_val_aX3);
        printf("Avg: %.2lf\t %.2lf\t %.2lf\n", mean_val_aX1, mean_val_aX2, mean_val_aX3);
        printf("STD: %.2lf\t %.2lf\t %.2lf\n", std_val_aX1, std_val_aX2, std_val_aX3);

    }
    
    return 0;
}

/*----------------------------
    This is Lecture 07 Lab 03

    --------------------------*/
#define INPUT_FILE "Lec07Labs.txt"


double getMax(double dArray[], int num_points);
double getMin(double dArray[], int num_points);
int getKthCount(double dArray[],int num_points,int k);

double getMax(double dArray[], int num_points){
    double max_value=0;
    /* Determining maximum value of the array received as argument*/
    for(int i=0;i<num_points;i++){
        if(dArray[i]>max_value)
        {
            max_value=dArray[i];
        }
    }
    return max_value;
}

double getMin(double dArray[], int num_points){
    double min_value=0;
    /* Determining minimum value of the array received as argument*/
    min_value=dArray[0];
    for(int i=0;i<num_points;i++){
        if(dArray[i]<min_value)
        {
            min_value=dArray[i];
        }
    }
    return min_value;
}

int getKthCount(double dArray[],int num_points,int k){
    int count=0;
    for(int i=0;i<num_points;i++){
        if(dArray[i]==k){
            count++;
        }
    }
    return count;
}


int main_03()
{
    FILE *infile; 
    double dArray[array_length]; //array operations will be carried upon
    double aX1[array_length], aX2[array_length]; //dummy arrays to store unsed data
    int num_points; int i=0; //used for counting in the while loop
    int occurance; //used to track occurance of numbers in dArray

    infile=fopen(INPUT_FILE,"r");

    if(infile==NULL)
    {
        printf("ERROR: File was not opened.\n");
    }else
    {
        while (!feof(infile))
        {
            fscanf(infile, "%lf %lf %lf", &dArray[i], &aX1[i], &aX2[i]);
            i++;
        }
        num_points=i-1;

        printf("---------------------------------------\n");
        printf("The file's first record contains %d data points\n",num_points);
        printf("Max value is %.1lf \n", getMax(dArray,num_points));
        printf("Min Value is %.1lf \n",getMin(dArray,num_points));
        printf("+-------+----------+\n");
        printf("| Index | Occurance|\n");
        printf("+-------+----------+\n");
        for(int j=5;j<num_points;j+=5)
        {
            int k=j;
            occurance=getKthCount(dArray,num_points,k);
            printf("|# %d\t| %d times |\n",j,occurance);
        }
        printf("+-------+----------+\n");
    }

    return 0;
}
