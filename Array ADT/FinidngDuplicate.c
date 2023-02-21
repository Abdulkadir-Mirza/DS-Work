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

void FindingDuplicate(struct Array arr)
{
    int lastDuplicate=0;
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]==arr.A[i+1]&&arr.A[i]!=lastDuplicate)
        {
            printf("\nDuplicate Found : %d",arr.A[i]);
            lastDuplicate=arr.A[i];
        }
    }
}

void FindingDuplicate2(struct Array arr)
{
    int j;
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]==arr.A[i+1])
        {
            j=i+1;
            while (arr.A[j]==arr.A[i])
            {
                j++;
            }
            printf("\nDuplicate element %d, %d times",arr.A[i],j-i);
            i=j-1;

        }
    }
}

int main()
{
    struct Array arr={{4,6,10,8,8,2,10,10},10,8};
    Display(arr);
    //FindingDuplicate2(arr);

    int l=2,h=10,n=8,i;
    int H[13]={0};
    for(i=0;i<n;i++)
    {
        H[(arr.A[i])]++;
    }
    for(i=l;i<=h;i++)
    {
        if(H[i]>1)
            printf("\nDuplicate element: %d, %d times",i,H[i]);
    }

    return 0;
    
}