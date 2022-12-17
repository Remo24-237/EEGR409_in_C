/*This is a program written to calculate and display balance of a loan,
    it will also display all balances and payments till the loan is 
    paid off.
 
 @author
    Remo24
     EEGR 409
     Assignment 03

 */

#include<stdio.h>
#include<math.h>

int main(){
    
    /* Declaring variables for input values */
    float loan_amount, monthly_pay, balance, tot_pay, interest_rate, monthly_interest, interest_paid, origin_loan;
    int num_of_pay ;

    /* Requesting and validating user input*/
    
    /* verification and validating of loan amount */
    do{
        printf("Enter amount of loan: ");
        scanf("%f", &loan_amount);
        if(loan_amount<1000){
            printf("INVALID LOAN AMOUNT:Monthly payment should be greater than 1000\n");
        }
    }while (loan_amount<1000);
    
    /* verification and validating of interest rate */
    do{
        printf("Enter interest rate in percentage [Values between 2 and 10]: ");
        scanf("%f", &interest_rate);
        if((interest_rate<2.00) || (interest_rate>10.00)){
            printf("INVALID INTEREST RATE: Interest rate must be between 2 and 10\n");
        }
    }while ((interest_rate<2.00) || (interest_rate>10.00));
    
    /* verification and validating of monthly payment */
    do{
        printf("Enter monthly payment amount: ");
        scanf("%f", &monthly_pay);
        if(monthly_pay<0){
            printf("INVALID MONTHLY PAYMENT:Monthly payment should be greater than 0\n");
        }
    }while (monthly_pay<0);
    
     origin_loan=loan_amount; //variable to value of original loan
     monthly_interest = (interest_rate/12); // Calculating the monthly interest
     tot_pay = monthly_pay; // Starting total payment with 1st monthly payment
     num_of_pay=1; // Starting the number of payments required at a value of 1

     /* Outputing data in specified format*/
    printf("+----------+------------+---------------+---------------+\n");
    printf("|Payment No| Payment Amt| Balance\t| Total Payments|\n");
    printf("+----------+------------+---------------+---------------+\n");

        /* do...while loop to keep track of the balance left and total payment after the payments are done */
     do{
        balance = loan_amount - monthly_pay + (loan_amount * (monthly_interest/100));
        printf("| %d\t   | %.2f\t| %5.2f \t| %.2f\t| \n", num_of_pay,monthly_pay,balance,tot_pay);
        if(balance<monthly_pay) 
        {
            monthly_pay=balance;
            balance=0;
            tot_pay+=monthly_pay;
            num_of_pay++;
            printf("| %d\t   | %.2f\t| %5.2f \t| %.2f\t| \n", num_of_pay,monthly_pay,balance,tot_pay);
        }else
        {num_of_pay++;
        tot_pay +=monthly_pay;
        loan_amount=balance;
        }
     }while (balance>0);
     
     printf("+----------+------------+---------------+---------------+\n\n");

    interest_paid = tot_pay - origin_loan;
    printf("Loan Summary\n");
    printf("------------\n");
     printf("Total number of payments: %d\n", num_of_pay);
     printf("Total interest paid: %.2f\n", interest_paid);
     printf("Total payments: %.2f\n", tot_pay);
}
