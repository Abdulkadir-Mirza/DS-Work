#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int A[20];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\nElements in the array are:\n ");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d  ",arr.A[i]);
    }
}

void Sum(struct Array arr,int sum)
{
    int i,j;
    for(i=0;i<arr.length;i++)
    {
        for(j=i+1;j<arr.length;j++)
        {
            if((arr.A[i]+arr.A[j])==sum)
            {
                printf("\n%d + %d = %d",arr.A[i],arr.A[j],sum);
            }
        }
    }
}

void Sum2(struct Array arr,int sum)
{
    int i=0,j=arr.length-1;
    while (i<j)
    {
        if((arr.A[i]+arr.A[j])==sum)
        {
            printf("\n%d + %d = %d",arr.A[i],arr.A[j],sum);
            i++;
            j--;
        }
        else if((arr.A[i]+arr.A[j])<sum)
        {
            i++;
        }
        else
        {
            j--;
        }
    }
    
    
}

int main()
{
    struct Array arr={{1,2,4,5,6,7,8,9,10},10,9};
    Display(arr);
    Sum2(arr,10);
    

    return 0;
}