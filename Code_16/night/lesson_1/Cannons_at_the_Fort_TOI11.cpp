/*
    TASK:Cannons at the Fort
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[1000100],b[1010];
int main()
{
    int n,m,k,l,x,y,nx,ny,ans;
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    while(k--){
        for(int i=1;i<=m;i++){
            scanf("%d",&b[i]);
        }
        sort(b+1,b+1+m);
        x=-1,y=-1;
        ans=0;
        for(int i=1;i<=m;i++){
            nx=lower_bound(a+1,a+1+n,b[i]-l)-a;
            ny=upper_bound(a+1,a+1+n,b[i]+l)-a;
            // printf("%d %d\n",nx,ny);
            if(nx>y){
                ans+=(y-x);
                x=nx,y=ny;
            }else{
                y=ny;
            }
        }
        ans+=(y-x);
        printf("%d\n",ans);
    }
    return 0;
}