/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,n;
    bool operator <(const A & o) const{
        return a<o.a;
    }
};
A a[50010];
int ma[50010];
unordered_map< int,int > mp;
int main()
{
    int q,n,cnt,l,r,now,mi;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        cnt=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].a,&a[i].n);
            if(!mp[a[i].n]) mp[a[i].n]=++cnt;
        }
        sort(a+1,a+1+n);
        // for(int i=1;i<=n;i++){
        //     printf("%d %d\n",a[i].a,mp[a[i].n]);
        // }
        mi=2e9;
        now=0;
        l=1,r=0;
        for(l=1;l<=n;l++){
            if(l!=1){
            ma[mp[a[l-1].n]]--;
            if(!ma[mp[a[l-1].n]]) now--;
            }
            while(r<n && now!=cnt){
                r++;
                if(!ma[mp[a[r].n]]) now++;
                ma[mp[a[r].n]]++;
                // printf("r %d %d %d\n",l,r,now);
            }
            if(cnt==now) mi=min(mi,a[r].a-a[l].a+1);
            else{break;}
            // printf("%d %d\n",a[l].a,a[r].a);
        }
        printf("%d\n",mi);
        memset(ma,0,sizeof ma);
        mp.clear();
    }
    return 0;
}
/*
1
6
20 1
15 9
16 1
5 1
12 5
10 1
*/