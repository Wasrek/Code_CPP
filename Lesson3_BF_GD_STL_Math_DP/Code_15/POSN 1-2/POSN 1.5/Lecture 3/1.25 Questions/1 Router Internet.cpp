/*
    TASK:Router Internet
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>//no to yes
using namespace std;
int a[100100];
int main()
{
    int n,m,i,l,r,mid,sum,cou;
    scanf("%d %d",&n,&m);
    for(i=0;i<m;i++)
        scanf("%d",&a[i]),a[i]*=10;
    sort(a,a+m);
    l=0,r=2000000000;
    while(l<r){
        mid=(l+r)/2;
        cou =1,sum =a[0];
        for(i=1;i<m;i++){
            if(a[i]>sum+2*mid)
                sum=a[i],cou++;
        }
        if(cou>n) l=mid+1;
        else r=mid;
    }

    printf("%d.%d\n",l/10,l%10);

    return 0;
}
