/*
    TASK:Swift Jump
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int dpx[100005];
int dpy[100005];
struct A
{
    int x,y,v;
    bool operator<(const A&o)const
    {
        if(max(x,y)!=max(o.x,o.y))  return max(x,y)<max(o.x,o.y);
        return min(x,y)<min(o.x,o.y);
    }
};
A a[300100];
int main()
{
    int n,b,sx,sy,enx,eny,v,i,ma=0,now;
    scanf("%d %d %d %d %d",&n,&b,&sx,&sy,&v);
    dpx[sx]=dpy[sy]=v;
    for(i=1;i<=n-2;i++){
        scanf("%d %d %d",&a[i].x,&a[i].y,&a[i].v);
    }
    scanf("%d %d %d",&a[n-1].x,&a[n-1].y,&a[n-1].v);
    enx=a[n-1].x;
    eny=a[n-1].y;
    sort(a+1,a+n);
    for(i=1;i<=n-1;i++)
    {
        now=0;
        if(a[i].x<sx||a[i].y<sy)  continue;
        if(dpx[a[i].x]>=b)
        {
            now=max(now,dpx[a[i].x]-b+a[i].v);
        }
        if(dpy[a[i].y]>=b)
        {
            now=max(now,dpy[a[i].y]-b+a[i].v);
        }
        dpx[a[i].x]=max(now,dpx[a[i].x]);
        dpy[a[i].y]=max(now,dpy[a[i].y]);
        if(a[i].x==enx&&a[i].y==eny)
        {
            printf("%d\n",now);
            return 0;
        }
    }
    return 0;
}

