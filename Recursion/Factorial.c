//Factorial of a number

#include <stdio.h>

int func(int n)
{
    if(n==0)
        return 1;
    else
        return n*func(n-1);
}

int main()
{
    int x=5;
    int fact=func(x);
    printf("%d",fact);
    return 0;
}