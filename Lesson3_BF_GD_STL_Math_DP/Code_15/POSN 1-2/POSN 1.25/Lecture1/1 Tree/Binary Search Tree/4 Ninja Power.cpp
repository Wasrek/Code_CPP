/*
    TASK:Ninja Power
    LANG: CPP
    AUTHOR: KERS
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int tree[1<<21],n,i,q,a,b;
int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&tree[i]);
    for(i=n-1;i>=0;i--){
        if(i*2+1<n)
            tree[i]+=tree[i*2+1];
        if(i*2+2<n)
            tree[i]+=tree[i*2+2];
    }
    printf("%d\n",tree[0]);
    scanf("%d",&q);
    while(q--){
        scanf("%d %d",&a,&b);
        if(tree[a]<tree[b])printf("%d<%d\n",a,b);
        if(tree[a]>tree[b])printf("%d>%d\n",a,b);
        if(tree[a]==tree[b])printf("%d=%d\n",a,b);

    }
    return 0;
}
