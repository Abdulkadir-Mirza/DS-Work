#include <stdio.h>


int main()
{
    char name[10];
    printf("Enter Name(in Block letters):");
    //scanf("%s",name);
    gets(name);
    int i;
    for(i=0;name[i]!='\0';i++)
    {}
    printf("Length of String is: %d",i);
    printf("\n%s",name);

    //Changing Case
    /*
    for(i=0;name[i]!='\0';i++)
    {
        name[i]+=32;
    }
    printf("\nString in lowercase:%s",name);
    */
    //Toggle Case
    for(i=0;name[i]!='\0';i++)
    {
        if(name[i]>='A'&&name[i]<='Z')
            name[i]+=32;
        else if(name[i]>='a'&&name[i]<='z')
            name[i]-=32;
    }
    printf("\nToggled String : %s",name);

    //reverse a String
    char Name[10]="Example";
    i=i-1;
    char ReverseName[10];
    int j=0;
    for(i;i>=0;i--)
    {
        ReverseName[j]=Name[i];
        j++;
    }
    ReverseName[j]='\0';
    printf("\nReversed String: %s",ReverseName);
    return 0;
}