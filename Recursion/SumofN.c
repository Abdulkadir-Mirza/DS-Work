//Sum of first N natural Numbers

#include <stdio.h>

int func(int n)
{
    static int sum=0;
    if(n>0)
    {
        sum=func(n-1)+n;
    }
    return sum;
}

int main()
{
    int x=5;
    int sum=func(x);
    printf("%d",sum);
    return 0;
}