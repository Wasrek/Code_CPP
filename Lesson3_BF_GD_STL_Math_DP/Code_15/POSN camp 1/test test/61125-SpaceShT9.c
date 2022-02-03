#include<bits/stdc++.h>
using namespace std;
int n,s,cou,mon,get;
int x[15],y[15],z[15],m[30],k[30],c[30],o=0,mi=850000,w,ch[15],u,mu,ku,cu;
void play(int state)
{
    int i;
    if(mu<=0 && ku<=0 && cu<=0){
            printf("%d",mon);
        exit(0);
    }
    for(i=1;i<=s;i++)
    {
        if(ch[i]==1){continue;}
        w=(x[i]-x[o])*(x[i]-x[o])+(y[i]-y[o])*(y[i]-y[o])+(z[i]-z[o])*(z[i]-z[o]);
        if(w<mi){mi=w;u=i;}
    }
    mon+=mi;
    ch[u]=1;
    o=u;
    mu=n-m[u];
    ku=n-k[u];
    cu=n-c[u];
    play(state+1);
}
int main()
{
    int i;
    scanf("%d",&n);
    mu=n,ku=n,cu=n;
    scanf("%d %d %d",&x[0],&y[0],&z[0]);
    scanf("%d",&s);
    for(i=1;i<=s;i++)
    {
        scanf("%d %d %d",&x[i],&y[i],&z[i]);
        scanf("%d %d %d",&m[i],&k[i],&c[i]);
    }
    play(0);
}
