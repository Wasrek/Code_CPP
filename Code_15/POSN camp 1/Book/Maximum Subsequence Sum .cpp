/*
    TASK:Maximum Subsequence Sum
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
int main()
{
    int i,n,sum=0,ansst=1,ansen,st=1,num,Max=-1000000000;
    int ch=1,ans2=-10000000,st2;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        if(num>=0) ch=0;
        if(num>ans2) ans2=num,st2=i;
        sum+=num;
        if(sum>=0){
            if(sum>Max)
                Max=sum,ansst=st,ansen=i;
        }else
        sum=0,st=i+1;
    }
    if(ch)
        printf("%d %d\n%d\n",st2,st2,ans2);
    else
        printf("%d %d\n%d\n",ansst,ansen,Max);
}
