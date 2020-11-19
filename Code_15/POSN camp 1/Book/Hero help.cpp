/*
    TASK:Hero help
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int x[100100],y[100100];
int main()
{
    int n,i,Ma=0,idx,k;
    scanf("%d %d",&n,&k);
    for(i=0;i<n;i++)
        scanf("%d %d",&x[i],&y[i]);
    sort(x,x+n);
    sort(y,y+n);
    for(i=0;i<n;i++){
        idx=lower_bound(x,x+n,x[i]+k)-x;
        if(idx-i>Ma) Ma=idx-i;
    }
    for(i=0;i<n;i++){
        idx=lower_bound(y,y+n,y[i]+k)-y;
        if(idx-i>Ma) Ma = idx-i;
    }
    printf("%d\n",Ma);
    return 0;
}
