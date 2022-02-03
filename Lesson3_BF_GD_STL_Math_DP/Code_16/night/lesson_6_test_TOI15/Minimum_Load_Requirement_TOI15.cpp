/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[15],p[15],t[15],c[15],lef[15];
vector< int >g;
long long s[10000100],qs[10000100];
int main()
{
    long long n,m,q,k,ch,cnt,ans,ub;
    long long l,r,mid,sum,all=0,mi=1e18;
    scanf("%lld %lld %lld",&n,&m,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&s[i]);
        mi=min(mi,s[i]);
        qs[i]=qs[i-1]+s[i];
    }
    qs[m+1]=qs[m];
    for(int i=1;i<=q;i++){
        scanf("%d",&t[i]);
    }
    for(int Q=1;Q<=q;Q++){
        for(int i=1;i<=n;i++){
            scanf("%d",&c[i]);
        }
        c[n+1]=m+1;
        // printf("hi\n");
        for(int i=1;i<=n;i++){
            l=mi,r=qs[c[i+1]];
            // printf("-----------------------------\n %d %lld %lld %lld %lld\n",i,c[i],c[i+1],l,r);
            while(l<r){
                mid=(l+r)/2;
                cnt=0;
                ch=0;
                // printf("%lld %lld %lld\n",mid,l,r);
                for(int j=c[i]-1;j<c[i+1];){
                    // printf("%lld %lld %lld %lld\n",mid,qs[j],ch,ub);
                    if(s[j]>mid){
                        //printf("-1- %lld %lld\n",s[j],mid);
                        ch=1;
                        break;
                    }
                    ub=upper_bound(qs+j+1,qs+c[i+1],mid+qs[j])-qs;
                    cnt++;
                    j=(ub-1);
                    // printf("%lld %lld %lld %lld %lld\n",mid,ch,ub,cnt,qs[j]);
                    if(cnt==t[Q] && j<c[i+1]-1){
                        // printf("-2- %lld %lld\n",j,c[i+1]-1);
                        ch=1;
                        break;
                    }
                    if(cnt==t[Q] && j>=c[i+1]-1){
                        // printf("-3- %lld %lld\n",j,c[i+1]-1);
                        break;
                    }
                    // printf("%lld %lld %lld %lld\n",mid,ch,ub,cnt);
                }
                // printf("%lld %lld %lld ---------------\n",mid,ch,ub);
                if(ch) l=mid+1;
                else r=mid;
            }
            // printf("%lld\n",l);
            g.push_back(l);
        }
        sort(g.begin(),g.end());
        // for(auto x: g) printf("%lld ",x);
        // printf("\n");
        do{
            for(int i=1;i<=n;i++){
                lef[i]=a[i]-p[i];
            }
            sort(lef+1,lef+1+n);
            ans=1;
            for(int i=1;i<=n;i++){
                if(g[i-1]>lef[i]) ans=0;
            }
            if(ans){
                break;
            }
        }while(next_permutation(p+1,p+1+n));
        if(ans) printf("P\n");
        else printf("F\n");
        g.clear();
    }
    return 0;
}