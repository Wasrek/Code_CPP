/*
    TASK:sort วิธีสวะ
    LANG: CPP
    AUTHOR: PeaTT~
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A
{
    char a[110];
    int coun[26];
};
A a[1010],temp;
int main()
{
    int n,i,j,k,ch;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf(" %s",a[i].a);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;a[i].a[j];j++)
            a[i].coun[a[i].a[j]-'a']++;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n-1;j++)
        {
            ch=1;
            for(k=0;k<26;k++)
                if(a[j].coun[k]>a[j+1].coun[k])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                ch=0;
                break;
            }
            else if(a[j].coun[k]<a[j+1].coun[k])
            {
                ch=0;
                break;
            }
            if(ch)
            {
                if(strcmp(a[j].a,a[j+1].a)>0)
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                }
            }
        }
        for(i=0;i<n;i++)
            printf("%s\n",a[i].a);
    return 0;
}
