#include<bits/stdc++.h>
using namespace std;
int a[110];
int main()
{
    int n,m,k,cz=0,co=0,now,ch;
    scanf("%d %d %d",&n,&m,&k);
    now=n+1;
    while(k--){
    ch=0;
    now=n+1;
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
        if(a[i])now++;
        else now--;
        if(now<1 || now>2*n+1)ch=1;
    }
    if(ch)printf("0\n");
    else printf("1\n");
    }
    return 0;
}