/*This is a program written to calculate the reminding of a balance,
 after 3 payments
 
 @author
    Remo24
     EEGR 409
     Assignment 02

 */

#include<stdio.h>
#include<math.h>

int main(){
    
    /* Declaring variables for input values */
    float loan_amount, interest_rate, monthly_pay;
    /* Declaring variables for output values*/
    float first_balance, second_balance, third_balance, monthly_interest;

    /* Requesting user input */
    printf("Enter amount of loan: ");
    scanf("%f",&loan_amount);
    printf("Enter interest rate: ");
    scanf("%f",&interest_rate);
    printf("Enter monthly payment: ");
    scanf("%f",&monthly_pay);

    /* Calculating monthly interest*/
    monthly_interest=(interest_rate/12);
    /* Calculating resulting balances */
    first_balance = loan_amount - monthly_pay + (loan_amount * (monthly_interest/100));
    second_balance = first_balance - monthly_pay + (first_balance * (monthly_interest/100));
    third_balance = second_balance - monthly_pay + (second_balance * (monthly_interest/100));

    /* Displaying resulting balances */
    printf("Balance remaining after first payment: %.2f \n", first_balance);
    printf("Balance remaining after second payment: %.2f \n", second_balance);
    printf("Balance remaining after third payment: %.2f \n", third_balance);

   

    return 0;
}
