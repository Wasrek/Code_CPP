/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100];
priority_queue< int > h;
int main()
{
    int n,m,k,cn,sum=0;
    scanf("%d %d %d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        if(i>1){
            h.push((a[i]-a[i-1]-1)*-1);
        }
    }
    cn=m-k;
    cn=max(cn,0);
    while(cn--){
        sum+=(h.top()*-1);
        h.pop();
    }
    printf("%d\n",sum);
    return 0;
}