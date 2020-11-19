/*
    TASK:Parenting Partnering Returns
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int s,e,i;
    bool operator<(const A & o) const{
        if(s!=o.s) return s<o.s;
        else return e<o.e;
    }
};
A a[1010],b[1010];
char ans[1010];
int main()
{
    int Q,q,s,e,n,nowa,nowb,cnt,all,ch;
    scanf("%d",&Q);
    for(int q=1;q<=Q;q++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&a[i].s,&a[i].e);
            a[i].i=i;
        }
        sort(a+1,a+1+n);
        ans[a[1].i]='C';
        all=1;
        nowa=a[1].e;
        nowb=0;
        ch=0;
        for(int i=2;i<=n;i++){
            if(nowa>nowb){
                if(a[i].s>=nowa){
                    all++;
                    ans[a[i].i]='C';
                    nowa=a[i].e;
                }else if(a[i].s>=nowb){
                    all++;
                    ans[a[i].i]='J';
                    nowb=a[i].e;
                }else ch=1;
            }else{
                if(a[i].s>=nowb){
                    all++;
                    ans[a[i].i]='J';
                    nowb=a[i].e;
                }else if(a[i].s>=nowa){
                    all++;
                    ans[a[i].i]='C';
                    nowa=a[i].e;
                }else ch=1;
            }
        }
        printf("Case #%d: ",q);
        if(ch) printf("IMPOSSIBLE\n");
        else{
            for(int i=1;i<=n;i++) printf("%c",ans[i]);
            printf("\n");
        }
    }
    return 0;
}