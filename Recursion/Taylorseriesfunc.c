//e^x Taylor series
#include <stdio.h>

double taylor(int x,int n)
{
    static double P=1,f=1;
    double r;
    if(n==0)
        return 1;
    r=taylor(x,n-1);
    P=P*x;
    f=f*n;
    return r+(P/f);
}

int main()
{
    printf("%lf ",taylor(2,10));
    return 0;
}