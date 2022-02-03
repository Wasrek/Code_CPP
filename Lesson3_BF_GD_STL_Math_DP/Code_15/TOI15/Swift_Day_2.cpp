#include<bits/stdc++.h>
using namespace std;
int mi=25,m,va[25],n;
void play(int state,int val,int coun)
{
    if(val==(1<<m)-1)
    {
        mi=min(mi,coun);
        return ;
    }
    if(state==n)
        return ;
    play(state+1,val,coun);
    play(state+1,val|va[state],coun+1);
}
int main()
{
    int i,j,a,b;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a);
        for(j=0;j<a;j++){
            scanf("%d",&b);
            va[i]|=(1<<(b-1));
        }
    }
    play(0,0,0);
    printf("%d",mi);
    return 0;
}
