// /*
//     TASK:
//     LANG: CPP
//     AUTHOR: Wichada
//     SCHOOL: RYW
// */
// #include<bits/stdc++.h>
// using namespace std;
// #define N 200100
// struct A{
//     int x,y;
//     bool operator <(const A& o) const{
//         if(x!=o.x) return x<o.x;
//         return y<o.y;
//     }
// };
// A a[N];
// int le[N],ri[N];
// int main()
// {
//     freopen("moop.in","r",stdin);
// 	freopen("moop.out","w",stdout);
//     int n;
//     scanf("%d",&n);
//     for(int i=1;i<=n;i++){
//         scanf("%d %d",&a[i].x,&a[i].y);
//     }
//     sort(a+1,a+1+n);
//     le[1]=a[1].y;ri[n]=a[n].y;
//     for(int i=2;i<=n;i++){
//         le[i]=min(le[i-1],a[i].y);
//     }
//     for(int i=n-1;i>=1;i--){
//         ri[i]=max(ri[i+1],a[i].y);
//     }
//     int ans=1;
//     for(int i=1;i<n;i++){
//         if(le[i]>ri[i+1]){
//             ans++;
//         }
//     }
//     printf("%d\n",ans);
//     return 0;
// }
#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 200000
int N,Q;
int x[MAXN], y[MAXN];
int cid[MAXN];
int minl[MAXN];
int maxr[MAXN];
 
bool cmp(int a,int b)
{
	if(x[a]==x[b]) return y[a]<y[b];
	return x[a]<x[b];
}
 
 
int main()
{
    freopen("moop.in","r",stdin);
	freopen("moop.out","w",stdout);
    cin >> N;
    for(int i=0;i<N;i++)
    {
        cin >> x[i] >> y[i];
        cid[i] = i;
    }
    sort(cid,cid+N,cmp);
    minl[0] = y[cid[0]];
    for(int i=1;i<N;i++)
        minl[i] = min(minl[i-1], y[cid[i]]);
    maxr[N-1] = y[cid[N-1]];
    for(int i=N-2;i>=0;i--)
        maxr[i] = max(maxr[i+1], y[cid[i]]);
    int ans = 1;
    for(int i=0;i<N-1;i++)
        if(minl[i] > maxr[i+1])
            ans++;
    cout << ans << '\n';
}