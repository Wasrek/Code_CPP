#include<bits/stdc++.h>
using namespace std;
int a[100500],ch[1000500],sum[100500];
int main()
{
    int i,n,Min=10000000,last,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]<Min)
            Min=a[i];
        ch[a[i]]=2;
        sum[i+1]=a[i]+sum[i];
        ch[sum[a[i]]]=2;
    }
    ch[0]=2;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            ch[sum[j]-sum[i]]=2;
        }
        for(k=0;k<n;k++)
        {
            ch[sum[i]-a[k]]=2;
        }
    }
    for(i=Min;i<=1000000;i++)
    {
        if(ch[i]!=2){
            printf("%d",i);
            exit(0);
        }
    }
}
