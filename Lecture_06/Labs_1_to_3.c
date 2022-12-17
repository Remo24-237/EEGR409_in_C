/* 
    Lab_01: Write a C program that reads a number N that consist of m digits from user. 
            Use two functions to display the kth digit of N from the right and the total 
            number of digits.
            - the getKthDigit(N,K) accept the number N and the kth digit to display.
            - the getNumDigits(N) calculates how many digits in N.
            - if k>m the getKthDigit returns zero; otherwise, it return the correct digit.
    Lab_02: Write a program that raises a number x to power n. x and n are integers and 
            supplied by the user. This should be done recursively.
    Lab_03: Write a c program that simulates the rolling of a six-sided fair die for a number
            of times (nbrRolls).
    

    @author
    Remo24
     EEGR 409
     Lect_06_Lab_F22
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>

/*----------------------------
    This is Lecture 06 Lab 01
        Modification: use a for loop/if statements in main to display all digits
    --------------------------*/

int getNumDigits(int num_N);
int getKthDigit(int num_N, int k);

int getNumDigits(int num_N){
    int num_digits=0,sum_digits=0;
    do
    {
        num_digits ++;
        sum_digits +=num_N%10;
        num_N = num_N/10;
    } while (num_N>0);

    return num_digits;
}
int getKthDigit(int num_N, int k){
    int my_digit, num_N_digits;
    /* calling the getNumDigit to validate the k integer received from user*/
    num_N_digits= getNumDigits(num_N);
    if (k>num_N_digits){
        printf("The Kth value you entered is not valid and greater than the number of digits in N.\n");
        return 0;
    }else
    {
        for(int i=1;i<=k;i++){
            my_digit=num_N%10;
            num_N = num_N/10;
        }
        return my_digit;

    }
}
int main() {

    int num_N,k_position;
    /* requesting user to enter values */
    printf("Enter a number N: ");
    scanf("%d", &num_N);
    /* to obtain number of digits */
    int num_digits= getNumDigits(num_N);
    /* to print all digits in number N */
    for(int i=1;i<=num_digits;i++){
        int count = getKthDigit(num_N,i);
        printf("The number at position %d is %d\n",i,count);
    }

    printf("The input number %d has only %d digits!\n",num_N,num_digits);
    return 0;
}

/*----------------------------
    This is Lecture 06 Lab 02
        Modification: the getPower function should use recursion to produce a result.
    --------------------------*/

int getPower(int num_X,int power_N){
    /* declaration of return value */
    //float result = 1;
    if (power_N<=1)
    {return num_X;}
    else
    {return num_X * getPower(num_X,power_N-1);}
}

int main(){
    /* declaration of inout variables */
    int num_X,power_N;
    /* inout validation for integer and power */
    do{
        printf("Please enter an integer value: ");
        scanf("%d",&num_X);

    }while(num_X<0 || getchar()!='\n');

    do
    {
        printf("Enter a positive power value: ");
        scanf("%d",&power_N);
    } while (power_N<0 || getchar()!='\n');

    int result=getPower(num_X,power_N);

    printf("the integer X=%d raised to the power N=%d is %d",num_X,power_N,result);

    return 0;
}

/*----------------------------
    This is Lecture 06 Lab 03
        Modification: 
    --------------------------*/

#define RAND_MAX 6
#define RAND_MIN 1

int getRandInt(){
    int rand_num;
    /* generating random value with range 1 through 6*/
    rand_num = rand()%(RAND_MAX-RAND_MIN+1)+RAND_MIN;
    return rand_num;
}
int main(){
    /* variable declaration */
    int nbrRolls, rand_num, count_1=0, count_2=0,count_3=0,count_4=0, count_5=0,count_6=0;
    printf("Enter number of fair die rolls: ");
    scanf("%d",&nbrRolls);
    /* using for loop to compute number of individual rolls*/
    for(int i=1;i<=nbrRolls;i++){
        rand_num=getRandInt();
        if(rand_num==1){
            count_1++;
        }
        if (rand_num==2){
            count_2++;
        }
        if (rand_num==3){
            count_3++;
        }if(rand_num==4){
            count_4++;
        }
        if (rand_num==5){
            count_5++;
        }
        if (rand_num==6){
            count_6++;
        }

    }

    /* Printing output */
    printf("Number of rolls: %d \n", nbrRolls);
    printf("Number of ones   = %d or %.3lf %%\n", count_1, (float)count_1/nbrRolls*100);
    printf("Number of twos   = %d or %.3lf %%\n", count_2, (float)count_2/nbrRolls*100);
    printf("Number of threes = %d or %.3lf %%\n", count_3, (float)count_3/nbrRolls*100 );
    printf("Number of fours  = %d or %.3lf %%\n", count_4, (float)count_4/nbrRolls*100);
    printf("Number of fives  = %d or %.3lf %%\n", count_5, (float)count_5/nbrRolls*100);
    printf("Number of sixes  = %d or %.3lf %%\n", count_6, (float)count_6/nbrRolls*100);

    return 0;
}
