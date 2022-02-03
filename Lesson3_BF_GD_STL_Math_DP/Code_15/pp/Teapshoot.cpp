#include<bits/stdc++.h>
using namespace std;
char a[4000000];
int b[4000000],n,coun;
void play(int lev,int v,int val)
{
    if(lev==n)
    {
        b[coun++]=val;
        return ;
    }
    int l=0,r=0;
    if(a[v]=='L')
        r+=1<<lev;
    else
        l+=1<<lev;
    play(lev+1,v*2+1,val+l);
    play(lev+1,v*2+2,val+r);
}
int play2(int lev,int v)
{
    if(lev==n)
        return b[coun++];
    int l=play2(lev+1,v*2+1);
    int r=play2(lev+1,v*2+2);
    if(l<r)
        a[v]='L';
    else
        a[v]='R';
    return min(l,r);
}
int main()
{
    int q;
    scanf("%d %d",&q,&n);
    if(q==1)
    {
        scanf(" %s",a);
        play(0,0,1);
        for(int i=0;i<min(coun,555555);i++)
            printf("%d ",b[i]);
        return 0;
    }
    else
    {
        for(int i=0;i<(1<<n);i++)
            scanf("%d",&b[i]);
        play2(0,0);
        printf("%s",a);
        return 0;
    }
}
