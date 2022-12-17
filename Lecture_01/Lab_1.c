/* Program to measure the distance between 2 point
     @autor Remo24
     EEGR 409
     Lab 1 */

#include<stdio.h>
#include<math.h>
 
 int main()
 {
    /* Declaration and initialisation of variables to be used*/
    int x1, y1,x2, y2 ; 
    double dist, xdiff,ydiff;
    
    printf("Enter first point (x,y): ");
    scanf( "%d ,%d", &x1,&y1);
    printf("Enter second point (x,y): ");
    scanf("%d ,%d",&x2,&y2);
    //side1 = (x1-x2)*(x1-x2);
    //side2 = (y1-y2)*(y1-y2);
    xdiff=x2-x1;
    ydiff=y2-y1;

    dist = sqrt((xdiff*xdiff)+(ydiff*ydiff));

    printf("The distance between point (%d,%d) and point (%d,%d) is %2.2f\n", x1,y1,x2,y2,dist);

    return 0 ;
 }
