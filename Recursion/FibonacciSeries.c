//Fibonacci Series 0 1 1 2 3 5 8 13 21 34......
//Each next term is obtained by summing previous two terms

int fib(int n)
{
    static Sum=0;
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    return fib(n-2)+fib(n-1);
}

int main()
{
    printf("Fibonacci");
}