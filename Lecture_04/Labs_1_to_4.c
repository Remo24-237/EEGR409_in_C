/* 
    Lab_01: Write a program to compute a the squares of all numbers from 0 up to N.
    Lab_02: Write a program to compute the sum of an arithmetis series, from a starting 
            point through the value N.
    Lab_03: Write a program that asks the user for an integer number (N) and calculates 
            the number of digits and their sum. 
    Lab_04: Write a program that reads some text from the user (in one line then the user 
            hits Enter) and prints individual characters and their count.

    @author
    Remo24
     EEGR 409
     Lect_04_Lab_F22
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

/*----------------------------
    This is Lecture 04 Lab 01
    Modification: Compute and print only even / odd numbers.
    --------------------------*/
void print(){
    printf("---------------------\n");
    printf("| Numbers | Squares |\n"); 
    printf("---------------------\n");
}
int main(){
    int num,squ_num;

    printf("Enter a number N: ");
    scanf("%d", &num);

    print();
    for (int i = 0; i <= num; i++)
    {
        squ_num = i * i;
        printf("| %4d\t  | %7d |\n",i,squ_num );
    }
    printf("---------------------\n");

    printf("Printing only even numbers in the range 0 to %d \n",num);
    print();
    for (int i = 0; i <= num; i++)
    {
    if(i%2==0)
    {
        squ_num = i * i;
        printf("| %4d\t  | %7d |\n",i,squ_num );
    }else{ continue;}
    }
    printf("---------------------\n");

    printf("Printing only even numbers in the range 0 to %d \n",num);
    print();
    for (int i = 0; i <= num; i++)
    {
    if(i%2!=0)
    {
        squ_num = i * i;
        printf("| %4d\t  | %7d |\n",i,squ_num );
    }else{ continue;}
    }
    printf("---------------------\n");
    return 0;
}

/*----------------------------
    This is Lecture 04 Lab 02
    Modifications:
        1 - Ask the user to indicate the increment.
        2 - Ask the user to indicate the starting value and increment. 
        3 - Check if the user entered a number(s) or not(input validation)
            if Not, keep asking the user to enter a valid input.
    --------------------------*/

int main(){

    /* declaring variables */
    int num_N, sum_of_N, start_value, increment;
    
    /* requesting values from the user */
    do
    {
        printf("Please  enter a valid number for N: ");
        scanf("%d", &num_N);
        
    }while((getchar()!='\n') || (num_N<0));
    
    printf("Enter an increment value: ");
    scanf("%d", &increment);
    printf("Enter a starting value: ");
    scanf("%d", &start_value);

    printf("\nThe number entered is: %d\n", num_N);
    /* using a loop to sum the numbers of the series */
    sum_of_N=0;
    for(int i=start_value;i<=num_N;i+=increment){
        sum_of_N +=i;
    }
    /* printing out result */
    printf("The sum of the series is: %d\n", sum_of_N);

    return 0;
}

/*----------------------------
    This is Lecture 04 Lab 03
    Modifications:
       1 - Make sure the user enters a number (input validation).
       2 - Indicate how many characters in the input.
       3 - What are the digits of the mixed input (if any).
       4 - If all are digits indicate how many and their sum.
    --------------------------*/

int  main(){
    
    /* declaring variables */
    int num_N, num_digits, sum_digits;
    int num_N_copy; /* to hold the value of num_N for later use */

    /* requesting user to enter values */
    printf("\nEnter an integer (N>0) to count its digits,and sum : ");
    scanf("%d", &num_N);
    printf("The input number is %d,\n",num_N);
    /* while loop to count the number of characters from the input*/
    int count=0;
    while(1){
        if(getchar()=='\n')
        {
            break;
        }
        count++;
    }
    num_N_copy = num_N;
    num_digits=0;
    sum_digits=0;
    /* do while loop to compute the number of digits and their sum*/
    do
    {
        num_digits ++;
        sum_digits +=num_N%10;
        num_N = num_N/10;
    } while (num_N>0);
    /* printing number of characters and number from the input */
    printf("What you entered contained %d character(s).\n",count);
        if(count<=0) {
            printf("It consists of %d digits and their sum is %d\n", num_digits, sum_digits);
        }
    return 0;   
}

/*----------------------------
    This is Lecture 04 Lab 04
    Modifications:
       1 - Count the number of ALL characters.
       2 - Count the number of characters excluding the spaces and \n.
       3 - Count how many digits (if any) any how many characters (excluding the spaces and \n).
    --------------------------*/

int main(){

    /* declaring variables */
    int num_N, num_digits=0, sum_digits=0;
    int space_count=0; /* to hold count of spaces */
    char chr;
    int chr_count = 0; /* to hold count of all characters */
    int other_char = 0; /* to hold the count of other characters */

    /* requesting user to enter values */
    printf("\nEnter a text : ");
    scanf("%d",&num_N);
    /* while loop to loop through the input to count various characters*/
    while(1){
        chr=getchar();
        if(chr!='\n' )
        {
            if(chr==' '){
                printf("the next character is a space ");
                putchar(chr);
                putchar('\n');
                space_count++;
            }else if(isdigit(chr)){
                printf("the next character in line is  ");
                putchar(chr);
                putchar('\n');
                num_digits++;
            }else {
                printf("the next character in line is ");
                putchar(chr);
                putchar('\n');

            }
            chr_count++;
        }else{ break;} /* exiting loop if a newline is encountered*/
    }


    other_char = chr_count - (num_digits + space_count);
   printf("Your text contains a total of %d character, %d of which are digits, and %d other characters excluding spaces \n",chr_count,num_digits,other_char);


    return 0;
}
