#include <iostream>
using namespace std;

class Array
{
    private:
    int *A;
    int size;
    int length;
    
    public:
    Array()
    {
        size=10;
        length=0;
        A=new int[size];
    }
    Array(int sz)
    {
        size=sz;
        length=0;
        A=new int[size];
    }
    ~Array()
    {
        delete []A;
    }

    void Display();
    void Append(int x);
    void Insert(int index,int x);
    int Delete(int index);
    int LinearSearch(int key);
    int BinarySearch(int key);
    friend void Swap(int *x,int *y);
    int Min();
    int Max();
    int Sum();
    void Reverse();
    Array* Union(struct Array arr2);

};

void Array::Display()
{
    printf("\nElements in the array are:\n ");
    for(int i=0;i<length;i++)
    {
        printf("%d  ",A[i]);
    }
}

void Array::Append(int x)
{
    if(length<size)
        A[length++]=x;
}

void Array::Insert(int index,int x)
{
    int i;
    if(index>=0 && index<size)
    {
        for(i=length;i>index;i--)
        {
            A[i]=A[i-1];
        }
        A[i]=x;
        length++;
    }
}

int Array::Delete(int index)
{
    int x=0;
    int i;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(i=index;i<length-1;i++)
        {
            A[i]=A[i+1];
        }
        length--;
        return x;
    }
    return -1;
}

int Array::LinearSearch(int key)
{
    int i;
    for(i=0;i<length;i++)
    {
        if(key==A[i])
        {
            return i;
        }
    }
    return -1;
}

int Array::BinarySearch(int key)
{
    int l,mid,h;
    l=0;
    h=length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==A[mid])
            return mid;
        else if(key<A[mid])
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

int Array::Min()
{
    int i,min=A[0];
    for(i=0;i<length;i++)
    {
        if(A[i]<min)
            min=A[i];
    }
    return min;
}

int Array::Max()
{
    int i,max=A[0];
    for(i=0;i<length;i++)
    {
        if(A[i]>max)
            max=A[i];
    }
    return max;
}


int Array::Sum()
{
    int i,sum=0;
    for(i=0;i<length;i++)
    {
        sum+=A[i];
    }
    return sum;
}

void Array::Reverse()
{
    int i,j,temp;
    for(i=0,j=length-1;i<j;i++,j--)
    {
        Swap(&A[i],&A[j]);
    }
}

Array* Array::Union(Array arr2)
{
    int i,j,k;
    i=j=k=0;
    Array *arr3=new Array();

    while(i<length&&j<arr2.length)
    {
        if(A[i]<arr2.A[j])
            arr3->A[k++]=A[i++];
        else if(arr2.A[j]<A[i])
            arr3->A[k++]=arr2.A[j++];
        else
        {
            arr3->A[k++]=A[i++];
            j++;
        }
    }
    for(;i<length;i++)
    {
        arr3->A[k++]=A[i];
    }
    for(;j<arr2.length;j++)
    {
        arr3->A[k++]=arr2.A[i];
    }
    arr3->length=k;
    arr3->size=20;
    return arr3;
}

int main()
{
    Array arr(10);
    arr.Insert(1,10);
    arr.Append(20);
    arr.Append(30);
    arr.Display();
    cout << "\nMinimum:" <<arr.Min() << endl;
    cout << "Maximum:" <<arr.Max() << endl;
    arr.Reverse();
    arr.Display();
}