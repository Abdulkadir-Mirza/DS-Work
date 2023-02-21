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

void Append(struct Array *arr,int x)
{
    if(arr->length<arr->size)
        arr->A[arr->length++]=x;
}

void Insert(struct Array *arr,int index,int x)
{
    int i;
    if(index>=0 && index<arr->length)
    {
        for(i=arr->length;i>index;i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[i]=x;
        arr->length++;
    }
}

int Delete(struct Array *arr,int index)
{
    int x=0;
    int i;
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(i=index;i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
}

int LinearSearch(struct Array arr,int key)
{
    int i;
    for(i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
        {
            return i;
        }
    }
    return -1;
}

int BinarySearch(struct Array arr,int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
            return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else
            l=mid+1;
    }
    return -1;
}

void Swap(int *x,int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int Get(struct Array arr,int index)
{
    if(index<arr.length)
    {
        return arr.A[index];
    }
    return -1;
}

int Set(struct Array *arr,int index,int x)
{
    if(index<arr->length)
    {
        arr->A[index]=x;
        return 0;
    }
    return -1;
}

int Min(struct Array arr)
{
    int i,min=arr.A[0];
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]<min)
            min=arr.A[i];
    }
    return min;
}

int Max(struct Array arr)
{
    int i,max=arr.A[0];
    for(i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
            max=arr.A[i];
    }
    return max;
}


int Sum(struct Array arr)
{
    int i,sum=0;
    for(i=0;i<arr.length;i++)
    {
        sum+=arr.A[i];
    }
    return sum;
}

float Avg(struct Array arr)
{
    return (Sum(arr))/(arr.length-1);
}

void Reverse(struct Array *arr)
{
    int i,j,temp;
    for(i=0,j=arr->length-1;i<j;i++,j--)
    {
        Swap(&arr->A[i],&arr->A[j]);
    }
}

void InsertInSorted(struct Array *arr,int x)
{
    int i=arr->length-1;
    if(arr->length<arr->size)
    {
        while(i>=0 && arr->A[i]>x)
        {
            arr->A[i+1]=arr->A[i];
            i--;
        }
        arr->A[i+1]=x;
        arr->length++;
    }
}

int IsSorted(struct Array arr)
{
    for(int i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
            return 0;
    }
    return 1;
}

void ReArrange(struct Array *arr)
{
    int i,j;
    i=0;
    j=arr->length-1;
    while (i<j)
    {
        while(arr->A[i]<0){i++;}
        while(arr->A[j]>0){j--;}
        if(i<j){ Swap(&arr->A[i],&arr->A[j]);}
    }
    
}

struct Array* Merge(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length&&j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else
            arr3->A[k++]=arr2->A[j++];
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k++]=arr2->A[i];
    }
    arr3->length=arr1->length+arr2->length;
    arr3->size=20;
    return arr3;
}

struct Array* Union(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length&&j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            arr3->A[k++]=arr2->A[j++];
        else
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k++]=arr2->A[i];
    }
    arr3->length=k;
    arr3->size=20;
    return arr3;
}

struct Array* Difference(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length&&j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for(;i<arr1->length;i++)
    {
        arr3->A[k++]=arr1->A[i];
    }
    for(;j<arr2->length;j++)
    {
        arr3->A[k++]=arr2->A[i];
    }
    arr3->length=k;
    arr3->size=20;
    return arr3;
}

struct Array* Intersection(struct Array *arr1,struct Array *arr2)
{
    int i,j,k;
    i=j=k=0;
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length&&j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr2->A[j]<arr1->A[i])
            j++;
        else if(arr1->A[i]==arr2->A[j])
        {
            arr3->A[k++]=arr1->A[i++];
            j++;
        }
    }
    arr3->length=k;
    arr3->size=20;
    return arr3;
}

int main()
{
    struct Array arr={{2,-4,7,-9,1},10,5};
    Insert(&arr,2,20);
    Append(&arr,10);
    Display(arr);
    printf("\nDeleted Element: %d\n",Delete(&arr,3));
    Display(arr);
    struct Array arr1={{1,2,4,7,9,10,13,15,17,19},14,10};
    Display(arr1);
    printf("\n\nLinear Search of 7 : %d",LinearSearch(arr1,7));
    printf("\nBinary Search of 4 : %d",LinearSearch(arr1,5));
    
    printf("\n\nGetting element at index 6: %d",Get(arr1,6));
    printf("\nSetting element at index 6 to 14");
    Set(&arr1,6,14);
    Display(arr1);
    printf("\nMaximum : %d",Max(arr));
    printf("\nMinimum : %d",Min(arr));
    printf("\nAverage : %f",Avg(arr));
    //Reverse(&arr1);
    //printf("\n\nReversing the Array");
    //Display(arr1);
    InsertInSorted(&arr1,3);
    Display(arr1);
    printf("\nIs Arr Sorted: %d",IsSorted(arr));
    printf("\nIs Arr1 Sorted: %d",IsSorted(arr1));
    ReArrange(&arr);
    Display(arr);

    struct Array arr3={{1,4,9,10,13,19},10,6};
    struct Array arr4={{2,4,7,10,15,17},10,6};
    struct Array *arr5;
    //Merging arr and arr1 into arr2;
    /*
    arr5=Merge(&arr3,&arr4);
    Display(*arr5);
    */
    //arr5=Union(&arr3,&arr4);
    //arr5=Intersection(&arr3,&arr4);
    arr5=Difference(&arr3,&arr4);//A-B
    Display(*arr5);
    return 0;

}