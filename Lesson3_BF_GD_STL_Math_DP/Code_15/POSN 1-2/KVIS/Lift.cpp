/*
    TASK:Lift
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[45100];
int main()
{
    int n,sum=0,i,j,k,Min=1e9,l1,l2;
    scanf("%d",&n);
    a[0]=1;
    while(n--){
        scanf("%d",&k);
        for(i=45000;i>=k;i--){
            if(a[i-k]==1)
                a[i]=1;
        }
        sum+=k;
    }
    for(j=1;j<=sum;j++){
        if(a[j]==1){
            if(abs(sum-(j*2)) < Min){
                Min = abs(sum-(j*2));
                l1 = j;
                l2 = sum-j;
            }
        }
    }
    if(l1<l2)   printf("%d %d",l1,l2);
    else        printf("%d %d",l2,l1);

    return 0;
}
