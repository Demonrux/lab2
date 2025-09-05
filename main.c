#include <stdio.h>
#include <math.h>
#define CORRECT_INPUT_DATA 3
#define CORRECT_ITERATIONS 2
typedef enum{
    CORRECT_INPUT,
    INCORRECT_INPUT,
}StatusInput;

double function(double x);
double step(double leftBorder,double rightBorder,int iterations);
StatusInput inputData(double* leftBorder, double* rightBorder,int* iterations);
void functionFor(double leftBorder, int iterations, double step);
void functionWhile(double leftBorder, double rightBorder, double step);
void functionDoWhile(double leftBorder, double rightBorder, double step);

int main(){
    double leftBorder;
    double rightBorder = 0;
    int iterations = 0;
    StatusInput statusInput = inputData(&leftBorder, &rightBorder , &iterations);
    if (statusInput == INCORRECT_INPUT){
        printf("Incorrect input");
    }
    else {
        double step = (rightBorder - leftBorder)/(iterations - 1);
        functionFor(leftBorder, iterations, step);
        functionWhile(leftBorder, rightBorder, step);
        functionDoWhile(leftBorder, rightBorder, step);

    }
    return statusInput;
}

double function(double x){
    return (sin(x)*sin(x)) / x;
}
StatusInput inputData(double* leftBorder, double* rightBorder, int* iterations) {
    StatusInput statusInput;
    if ((scanf("%lf %lf %d", leftBorder, rightBorder, iterations) != CORRECT_INPUT_DATA) || (*leftBorder >= *rightBorder) || (*iterations < CORRECT_ITERATIONS)){
        statusInput = INCORRECT_INPUT;
    }
    else {
        statusInput = CORRECT_INPUT;
    }
    return statusInput;
}
void functionFor(double leftBorder,int iterations,  double step) {
    double leftBorder0 = leftBorder;
    printf("for:\nx    |");
    for(int i  = 0; i < iterations ; i ++ )
    {
        printf(" %.3lf\t|", leftBorder);
        leftBorder += step;
    }
    printf("\nf(x) |");
    for(int i  = 0; i < iterations ; i ++  )
    {
        if(isinf (function(leftBorder0)))
        {
            printf(" inf\t|");
        }
        if(isnan (function(leftBorder0)))
        {
            printf(" nan\t|");
        }
        else
        {
            printf(" %.3lf\t|", function(leftBorder0));
        }
        leftBorder0 += step;
    }
}
void functionWhile(double leftBorder, double rightBorder, double step) {
    double leftBorder0 = leftBorder;
    printf("\nwhile:\nx    |");
    while(leftBorder <= rightBorder)
    {
        printf(" %.3lf\t|",leftBorder);
        leftBorder += step;
    }
    printf("\nf(x) |");
    while(leftBorder0 <= rightBorder)
    {
        if(isinf (function(leftBorder0)))
        {
            printf(" inf\t|");
        }
        if(isnan (function(leftBorder0)))
        {
            printf(" nan\t|");
        }
        else
        {
            printf(" %.3lf\t|",function(leftBorder0));
        }
        leftBorder0 += step;
    }
}
void functionDoWhile(double leftBorder, double rightBorder, double step) {
    double leftBorder0 = leftBorder;
    printf("\ndo while:\nx    |");
    do {
        printf(" %.3lf\t|",leftBorder);
        leftBorder += step;
    }while(leftBorder <= rightBorder);
    printf("\nf(x) |");
    do {
        if(isinf (function(leftBorder0)))
        {
            printf(" inf\t|");
        }
        if (isnan (function(leftBorder0 )))
        {
            printf(" nan\t|");
        }
        else
        {
            printf(" %.3lf\t|",function(leftBorder0));
        }
        leftBorder0 += step;
    }while(leftBorder0 <= rightBorder);
}
