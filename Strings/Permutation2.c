#include <stdio.h>

void Swap(char *c,char *d)
{
    char temp;
    temp=*c;
    *c=*d;
    *d=temp;
}

void Perm(char s[],int l,int h)
{
    int i;
    if(l==h)
    {
        printf("%s\n",s);
    }
    else
    {
        for(i=l;i<=h;i++)
        {
            Swap(&s[l],&s[i]);
            Perm(s,l+1,h);
            Swap(&s[l],&s[i]);
        }

    }
}

int main()
{
    char S[]="ABCD";
    Perm(S,0,3);
    return 0;
}