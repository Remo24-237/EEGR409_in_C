/*
 * Lab_01: Write a C program that uses the 4X3 Xnew array ti find:
 *  - The sum of each row of Xnew
 *  - The sum of each column Xnew
 *  - The sum of the diagonal of Xnew
 *  - Construct a 5X4 new Ynew as shown below
 *  @author
    Remo24
    EEGR409
 *  Lecture_09
 *  Lab_01*/

#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
/* defining fixed values for the array dimensions*/
#define XnRows 4
#define XnCols 3
#define YnRows 5
#define YnCols 4

int main() {

    /* declaring and defining array Xnew */
    int Xnew[XnRows][XnCols] = {{2,  3,  -1},
                                {0,  -3, 5},
                                {2,  6,  3},
                                {-2, 10, 4}};

    /* declarind and defining array Ynew */
    int Ynew[YnRows][YnCols]={0};
    int i=0, j=0,k,l, rowSum = 0, diagSum = 0, colSum = 0;

    /* printing arrays */
    /* Xnew */
    printf("The Xnew matrix values are:\n");
    printf("--------------------------\n");
    for (int k = 0; k < XnRows; k++) {
        for (int l = 0; l < XnCols; l++) {
            printf(" %2d ", Xnew[k][l]);
        }
        printf("\n");
    }
    printf("\n");

    printf("\n");
    /* finding rowSum and diagSum */
    {
        for (i = 0; i < XnRows; i++) {
            rowSum=0;
            for (j = 0; j < XnCols; j++) {
                Ynew[i][j] = Xnew[i][j];
                rowSum += Xnew[i][j];
                Ynew[i][j + 1] = rowSum;
                if (i == j) {
                    diagSum += Xnew[i][j];
                }

            }
        }

        /* finding colSum */
        for (j = 0; j < XnCols; j++) {
            colSum=0;
            for (i = 0; i < XnRows; i++) {
                colSum += Xnew[i][j];

            }
            Ynew[XnRows][j]=colSum;
        }
        Ynew[4][3]=diagSum;

    }
    printf("The Ynew matrix values are:\n");
    printf("--------------------------\n");
    for ( k = 0; k < YnRows; k++) {
        for ( l = 0; l < YnCols; l++) {
            printf(" %2d ", Ynew[k][l]);
        }
        printf("\n");
    }

    return 0;
}
