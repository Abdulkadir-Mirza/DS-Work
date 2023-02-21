//Factorial of a number

#include <stdio.h>

int power(int m,int n)
{
    if(n==0)
        return 1;
    else if(n%2==0)
        return power(m*m,n/2);
    else
        return m*power(m*m,(n-1)/2);
}

int main()
{
    printf("%d",power(3,3));
    return 0;
}