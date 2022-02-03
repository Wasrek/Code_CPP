/*
    TASK:Beam Vegetable
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
char a[10000010];
int b[1000100];
int main()
{
    int i,j,k=sqrt(10000000),cou=1,q,n,idx;
    for(i=3;i<10000000;i+=2)
        a[i]=1;
    for(i=3;i<=k;i+=2){
        if(a[i])
            for(j=i*i;j<=10000000;j+=i)
            a[j]=0;
    }
    b[0]=2;
    for(i=3;i<10000000;i+=2)
        if(a[i])
        b[cou++]=i;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        if(n<=2){
            printf("1\n"); continue;
        }
        idx = upper_bound(b,b+cou,n)-b;
        printf("%d\n",n-idx+1);
    }


    return 0;
}
