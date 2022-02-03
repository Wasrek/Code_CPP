#include<bits/stdc++.h>
using namespace std;
struct A{
   int x1,y1,x2,y2;
};
A p[1010];
int main()
{
    int n,m,a,b,c,d,i,ans;
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
    scanf("%d %d %d %d",&a,&b,&c,&d);
    p[i]={a,d,c,b};
    }
    while(m--){
        scanf("%d %d %d %d",&a,&d,&c,&b);
        for(i=0,ans=0;i<n;i++){
            if(c<=p[i].x1 || p[i].x2<=a) continue;
            if(d<=p[i].y1 || p[i].y2<=b) continue;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
