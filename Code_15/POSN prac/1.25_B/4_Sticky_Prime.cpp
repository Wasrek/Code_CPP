/*
    Prac
    TASK:Sticky Prime
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[11000],s[10500],ch[10500],ans[25];
int main()
{
    int n,i,j,m,k,l,w,sum=1,h,r;
    scanf("%d",&n);
    a[2]=1;
    for(i=3; i<10000; i+=2)
        a[i]=1;
    m=sqrt(10000);
    s[0]=2;
    for(i=3; i<m; i+=2)
    {
        if(a[i]){
            for(j=i*i; j<10000; j+=i)
                a[j]=0;
            s[sum]=s[sum-1]+i;ch[s[sum]]=2;sum++;
        }
    }
    for(i=0;i<100;i++)
    {
        printf("%d. ",s[i]);
    }
    while(n--){
    scanf("%d",&h);
    w=0,r=0;
    for(i=0; s[i+1]-s[i]<=h ; i++)
    {
        if(ch[s[i]+h]==2)
        {
            w++;
            k=i;
            while(k++){
                if(s[k]==s[i]+h)
                {
                   // printf("%d %d. %d %d -\n",s[i],i,s[k],k);
                    ans[r]=k-i;r++;break;
                }
            }
        }
    }
    printf("%d\n",w);
    for(l=w-1;l>=0;l--)
    {
        printf("%d p\n",ans[l]);
    }
    }
}
