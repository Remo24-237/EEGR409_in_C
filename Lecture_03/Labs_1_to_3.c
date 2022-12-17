/* 
    Lab_01::This program is used to compare three numbers
        and print out the largest one.
    Lab_02::Program used to compare images and find which of these
        have the smallest ratios.
    Lab_03::Program using the conditional IF statement to 
        print out a resistivity value based on a guage provided by the user. 
    
    @author
    Remo24
     EEGR 409
     Lect_03_Labs_F22
    
    */

#include<stdio.h>
#include<math.h>

/*----------------------------
    This is Lecture_03_Lab_01
    --------------------------*/

int main()
{
    /* Declaring variables to be used as input */
    float num_1, num_2, num_3;

    /* Requesting numbers from user*/
    printf("Enter any 3 numbers (integer or floating point) \n");
    
    printf("Enter the first number: ");
    scanf("%f", &num_1);
    printf("Enter the second number: ");
    scanf("%f", &num_2);
    printf("Enter the third number: ");
    scanf("%f", &num_3);

    /* Printing output based on input received */
    if(num_1>num_2 && num_1>num_3)
    {
        printf("\nThe largest number is: %.4f", num_1);
    }
    else if(num_2>num_1 && num_1>num_3)
    {
        printf("\nThe largest number is: %.4f", num_2);
    }
    else 
    {
        printf("\nThe largest number is: %.4f", num_3);
    }
    
    return 0;
}

/*----------------------------
    This is Lecture_03_Lab_02
    --------------------------*/

int main()
{
    /* Declaring variables used for input, ouput and computation */
    float f1_eye_dist , f1_nose_to_chin, f2_eye_dist, f2_nose_to_chin, f3_eye_dist, f3_nose_to_chin;
    float ratio_1, ratio_2, ratio_3, dist_f1_f2, dist_f1_f3, dist_f2_f3;

    /* Requesting data points from user */
    printf("Enter face 1 eye distance: ");
    scanf("%f", &f1_eye_dist);
    printf("Enter face 1 nose to chin distance: ");
    scanf("%f",&f1_nose_to_chin);
    printf("Enter face 2 eye distance: ");
    scanf("%f", &f2_eye_dist);
    printf("Enter face 2 nose to chin distance: ");
    scanf("%f",&f2_nose_to_chin);
    printf("Enter face 3 eye distance: ");
    scanf("%f", &f3_eye_dist);
    printf("Enter face 3 nose to chin distance: ");
    scanf("%f",&f3_nose_to_chin);

    /* Calculating the ratio of the eye distance to the nose to chin distance for each face */
    ratio_1 = f1_eye_dist/f1_nose_to_chin;
    ratio_2 = f2_eye_dist/f2_nose_to_chin;
    ratio_3 = f3_eye_dist/f3_nose_to_chin;

    /* Calculating the absolute distance between the ratios  */
    dist_f1_f2 = fabs(ratio_1 - ratio_2);
    dist_f1_f3 = fabs(ratio_1 - ratio_3);
    dist_f2_f3 = fabs(ratio_2 - ratio_3);

    /* Printing output using conditional if statements */
    if(dist_f1_f2<dist_f1_f3 && dist_f1_f2<dist_f2_f3)
    {
        printf("The images 1 and 2 have the smallest ratio distance.\n");
    }
    else if (dist_f1_f3<dist_f1_f2 && dist_f1_f3<dist_f2_f3)
        {
            printf("The images 1 and 3 have the smallest ratio distance.\n");
        }
        else 
            {
                printf("The images 2 and 3 have the smallest ratio distance.\n");
            }

    return 0;
}

/*----------------------------
    This is Lecture_03_Lab_03
    --------------------------*/

int main()
{
    /* Declaring variables for input and output */
    int guage;
    float rho;

    /* Requesting input from the user */
    printf("\nEnter a guage value (integer) in the range [12, 14, 16, 18]:");
    scanf("%d", &guage);

    /* Printing output based on input received */
    if(guage==12 || guage==14 || guage==16 || guage==18)
    {
        if(guage==12)
        {
            rho = 5.211;
            printf("The resistivity for guage %d is: %f \n",guage,rho);
        }
        else if(guage==14)
        {
            rho = 8.285;
            printf("The resistivity for guage %d is: %f \n",guage,rho);
        }
        else if(guage==16)
        {
            rho = 13.170;
            printf("The resistivity for guage %d is: %f \n",guage,rho);
        }
        else{
            rho = 20.950;
            printf("The resistivity for guage 18 is: %f \n",rho);
            }
    }
    else
     {
        printf("You entered an invalid Guage.\n");
    }

    return 0;
}
