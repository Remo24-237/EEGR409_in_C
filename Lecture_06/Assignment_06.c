/* Write a C program that uses recursive function and random sequence generator in an
 * attempt to predict user's age (15 - 80 years old). The designed logic must use a
 * recursive loop.

 * @author
    Remo24
    EEGR409
    Assignment 05

 * */
#define _CRT_SECURE_NO_DEPRECATE
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
int max,min,count=0;
int getRandInt(int max,int min);
void guessNum(int upper_limit,int lower_limit);

int getRandInt(int max,int min){
    int newAge;
    srand(time(0));
    newAge = (int)((double)rand() / RAND_MAX * (max - min) + min);
    return newAge;
}
void guessNum(int upper_limit, int lower_limit) {
    int rand_num, response_1, response_2;
    rand_num = getRandInt(upper_limit, lower_limit);
    count++;
    printf("Is your age %d (Y/N): ", rand_num);
    scanf("%d", &response_1);

    switch (tolower(getchar())) {
        case 'y':
            printf("Fantastic! It only took me %d ties to guess your age\n", count);
            while(getchar()!='\n');
            break;
        case 'n':
            printf("Is your age lower or higher than %d (L/H): ", rand_num);
            scanf("%d", &response_2);
            switch (tolower(getchar())) {
                case 'h':
                    while(getchar()!='\n');
                    guessNum(rand_num,lower_limit);
                    break;
                case 'l':
                    while(getchar()!='\n');
                    guessNum(upper_limit,rand_num);
                    break;
                default:
                    while(getchar()!='\n');
                    printf("INVALID CHOICE, TRY AGAIN\n");
                    guessNum(upper_limit,lower_limit);
            }
        default:
            while(getchar()!='\n');
            printf("INVALID CHOICE, TRY AGAIN\n");
            guessNum(upper_limit, lower_limit);
    }
}
int main(){

    printf("Let me try to guess your age!\n");
    printf("-----------------------------\n");
    guessNum(15,80);
    return 0;
}
