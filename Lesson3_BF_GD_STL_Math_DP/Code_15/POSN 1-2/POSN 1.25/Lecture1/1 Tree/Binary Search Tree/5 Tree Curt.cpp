/*
    TASK:Tree Curt
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int tree[3000];
int main()
{
    int n,i,sum=0;
    scanf("%d",&n);
    for(i=n/2+1;i<=n;i++)
        scanf("%d",&tree[i]);
    for(i=n/2;i>=1;i--){
        if(tree[2*i] < tree[2*i+1]){
            tree[i] = tree[2*i];
            tree[2*i+1] -= tree[2*i];
            tree[2*i]=0;
        }
        else{
            tree[i] = tree[2*i+1];
            tree[2*i] -= tree[2*i+1];
            tree[2*i+1] = 0;
        }
    }
    for(i=1;i<=n;i++)
        sum+=tree[i];
        printf("%d\n",sum);
    return 0;
}
