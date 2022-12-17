/* 
    Lab_01: Write a C code that reads the data from file text.txt then calculate
            - the average value of the record X1 in the file column.
            - the sum of the value of the records X1, X2, and X3.
            - Display the calculations on th screen (as shown) and store the three records and 
                their sums (newX) in another file called stats.txt .
    Lab_02: Write a program that computes the length of the hypotenus (c) of a right triangle
            given the lengths of the other two sides (a,b).
    Lab_03: Write a program that raises a number x to power n. x and n are integers and 
            supplied by the user.
    

    @author
    Remo24
     EEGR 409
     Lect_05_Lab_F22
*/

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>

/*----------------------------
    This is Lecture 05 Lab 01
    --------------------------*/

#define INPUT_FILE "test.txt"
#define OUTPUT_FILE "stats.txt"

int main(){

    FILE *infile, *outfile;
    float x1, x2, x3;
    int  num_points=0;
    float new_X;
    double sum = 0;

    infile = fopen(INPUT_FILE , "r");
    outfile = fopen(OUTPUT_FILE , "w");

    /* Checking if there file was opened successfully */
    if(infile ==NULL)
    {
        printf("\n The file was not open successfully!");
    }else
    {
        printf("\n The file was open successfully!\n");
        fprintf(outfile, "X1 \tX2\t X3\t New_X\n");
        /* checking for end of file */
       while(!(feof(infile))) 
       {
        fscanf(infile, "%f %f %f", &x1,&x2,&x3);
            new_X= x1 + x2 + x3;
            sum += x1;
            num_points +=1;
            fprintf(outfile, "%2.2f \t%2.2f\t %2.2f\t %2.2f\n", x1,x2,x3, new_X);
       } 
       fprintf(outfile,"-----------------------------\n");
       fprintf(outfile,"The number of data readings: %d\n", num_points);
        fprintf(outfile, "The Average reading of first record is: %.3f\n", (sum/(num_points)));

    }

    fclose(infile);
    fclose(outfile);

    return 0;
}

/*----------------------------
    This is Lecture 05 Lab 02
    Modification: Please check the user input for both 0<a,b<100, otherwise ask him to 
                    change his/her input.
    --------------------------*/

/* function to compute hypotenus length */
double hyp_func (double a, double b)
{
    double c;
    c = sqrt((a*a)+(b*b));
    return c;
}
int main(){
    /* declaring values for the main function*/
    double a,b, my_result;

    /* using a loop to validate the inputted values */
    do{
        printf("Please enter 2 numbers seperated by a space character: ");
        scanf("%lf %lf", &a,&b);
        if((a<0) || (a>100) || (b<0) || (b>100)){
            printf("Invalid values for a or b: 0 < a,b <100. \n");
        }
    }while((a<0) || (a>100) || (b<0) || (b>100));
    
    /* calling function with values */
    my_result = hyp_func(a,b);

    /* printing out result */
    printf("The lenght of the hypotenous is %.3lf.\n", my_result);

}
/*----------------------------
    This is Lecture 05 Lab 03
    Modification: Modify the lab and use two functions
                    - getPower to raise x to power n.
                    - getInput to get user input for the two values.
                        *verifies that inputs are valid (x>1, n>=0, and no charater).
                        *Ask user to provide a different value if not.
    --------------------------*/
void getPower(int num_X, int power_n)
{
    float result=1;
    for(int i=1;i<=power_n;i++){
        result *= num_X;
    }
    printf("The integer x = %d raised to the power n = %d is %.1f  \n",num_X,power_n,result);
}
void getInput(void)
{
    int num_X,power_n;
    /* input validation for integer and power */
    do{
        printf("Please enter a valid integer: ");
        scanf("%d",&num_X);
    }while(num_X<0 || getchar()!='\n');

    do
    {
        printf("Enter a positive power value: ");
        scanf("%d",&power_n);
    } while (power_n<0 || getchar()!='\n');
    getPower(num_X,power_n);
}

int main{
    /* calling getInput to request input from user */
    getInput();
    
}
