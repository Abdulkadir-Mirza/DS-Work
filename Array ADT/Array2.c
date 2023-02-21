#include <stdio.h>
#include <stdlib.h>

struct Array
{
    int *A;
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

int main()
{
    struct Array arr;
    int n,i;
    printf("Enter the size of Array:");
    scanf("%d",&arr.size);
    arr.A=(int *)malloc(sizeof(int)*arr.size);
    arr.length=0;

    printf("Enter the number of elements:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr.A[i]);
    }
    arr.length=n;

    Display(arr);

}