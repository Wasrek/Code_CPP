/*
    TASK:AP_Value
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100];
int main()
{
    int q,n,i,sum,Ma,s;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(i=1,sum=0;i<=n;i++){
            scanf("%d",&a[i]);
            if(i%2==1) a[i]*=-1;
            sum+=a[i];
        }
        for(i=1,s=0,Ma=-1000000000;i<=n;i++){
            s+=a[i];
            if(s<0) s=0;
            if(s>Ma) Ma=s;
        }
        printf("%d\n",sum-2*Ma);
    }
}
