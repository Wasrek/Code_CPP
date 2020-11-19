#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
int dpx[100005];
int dpy[100005];
struct A
{
    int x,y,val;
    bool operator<(const A&o)const
    {
        if(max(x,y)!=max(o.x,o.y))  return max(x,y)<max(o.x,o.y);
        return min(x,y)<min(o.x,o.y);
    }
};
A arr[N];
int main()
{
    int n,b,stx,sty,enx,eny,val,ma=0;
    scanf("%d %d %d %d %d",&n,&b,&stx,&sty,&val);
    dpx[stx]=dpy[sty]=val;
    for(int i=1;i<=n-2;i++) scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].val);
    scanf("%d %d %d",&arr[n-1].x,&arr[n-1].y,&arr[n-1].val);
    enx=arr[n-1].x;
    eny=arr[n-1].y;
    sort(arr+1,arr+n);
    for(int i=1;i<=n-1;i++)
    {
        int nowma=0;
        if(arr[i].x<stx||arr[i].y<sty)  continue;
        if(dpx[arr[i].x]>=b)
        {
            nowma=max(nowma,dpx[arr[i].x]-b+arr[i].val);
        }
        if(dpy[arr[i].y]>=b)
        {
            nowma=max(nowma,dpy[arr[i].y]-b+arr[i].val);
        }
        dpx[arr[i].x]=max(nowma,dpx[arr[i].x]);
        dpy[arr[i].y]=max(nowma,dpy[arr[i].y]);
        if(arr[i].x==enx&&arr[i].y==eny)
        {
            printf("%d\n",nowma);
            return 0;
        }
    }
    return 0;
}
