/*
    TASK:Maximum Subsequence Sum
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
int main()
{
    int i,n,sum=0,anss=1,anse,st=1,num,Max=-1e9;
    int ch=1,ans2=-1e9,stm;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&num);
        if(num>=0) ch=0;
        if(num>ans2) ans2=num,stm=i;
        sum+=num;
        if(sum>=0){
            if(sum>Max)
                Max=sum,anss=st,anse=i;
        }else
        sum=0,st=i+1;
    }
    if(ch)
        printf("%d %d\n%d\n",stm,stm,ans2);
    else
        printf("%d %d\n%d\n",anss,anse,Max);
}
