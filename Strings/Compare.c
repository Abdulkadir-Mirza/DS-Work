#include <stdio.h>

int main()
{
    char A[]="Painting";
    char B[]="Painter";
    int i,j;
    for(i=0,j=0;A[i]!='\0'&&B[j]!='\0';i++,j++)
    {
        if(A[i]!=B[j])
            break;
    }
    if(A[i]==B[j])
        printf("Equal\n");
    else if(A[i]<B[j])
        printf("A is smaller than B");
    else
        printf("A is smaller than B");
}