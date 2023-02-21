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

void SingleMissingElement(struct Array arr)
{
    int diff=arr.A[0]-0;
    for(int i=0;i<arr.length;i++)
    {
        if(diff!=(arr.A[i]-i))
        {
            printf("\nMissing Element is: %d",diff+i);
            break;
        }
    }
}

void MultipleMissingElement(struct Array arr)
{
    int diff=arr.A[0]-0;
    for(int i=0;i<arr.length;i++)
    {
        if(diff!=(arr.A[i]-i))
        {
            while ((diff)<(arr.A[i]-i))
            {
                printf("\nMissing Element is: %d",diff+i);
                diff++;
            }
            
        }
    }
}

int main()
{
    struct Array arr={{2,4,5,6,8,9,10,11},10,8};
    Display(arr);
    //SingleMissingElement(arr);
    //MultipleMissingElement(arr);
    //Another method to find multiple missing elements in a sorted array- using basic hashing\bitset
    //We should know low(l),high(h) and no. of elemnets(n)
    int l=2,h=12,n=8,i;
    int H[13]={0};
    for(i=0;i<n;i++)
    {
        H[(arr.A[i])]++;
    }
    for(i=l;i<=h;i++)
    {
        if(H[i]==0)
            printf("\nMissing element: %d",i);
    }
}