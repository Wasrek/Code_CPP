/*
    TASK:Jack
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long tree[100100],l[100100],r[100100];
int main()
{
    long long n,num,i,run;
    scanf("%lld %lld",&n,&num);
    for(i=1;i<=n;i++)
        tree[i]=1e14;//e=10^18 exponential 1*10^14
    tree[1]=num;
    printf("*\n");
    for(i=2;i<=n;i++){
        scanf("%lld",&num);
        run = 1;
        while(1){
            if(tree[run]==1e14) break;
            if(num<tree[run]){
                if(l[run]==0) l[run]=i;
                run = l[run];
                printf("L");
            }
            else{
                if(r[run]==0) r[run]=i;
                run = r[run];
                printf("R");
            }
        }
        printf("*\n");
        tree[run]=num;
    }
    return 0;
}
