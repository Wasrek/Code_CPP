/*
    TASK:RT_Exam Final
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100005],day[100005],mark[100005],cou;
int main()
{
    int n,k,lef,i,l,r,mid;
    scanf("%d %d",&n,&k);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=k;i++){
        scanf("%d",&day[i]);
    }
    l=1,r=n+1;
    while(l<r){
        mid=(l+r)/2;
        memset(mark,0,sizeof mark);
        for(i=mid,lef=0,cou=0;i>0;i--){
            if(a[i]!=0 && !mark[a[i]]){
                mark[a[i]]=1;
                lef+=day[a[i]];
                cou++;
            }
            else if(lef>0)
                lef--;
        }
        if(cou==k && lef==0){
            r=mid;
        }else l=mid+1;
    }
    if(l==n+1)printf("-1");
    else
    printf("%d\n",l);
    return 0;
}
/*
7 2
0 1 0 2 1 0 2
2 1
*/
