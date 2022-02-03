/*
    TASK:PT_International
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int a,b;
    bool operator<(const A& o)const{
        if(a!=o.a)return a<o.a;
        return b<o.b;
    }
};
A p[50100];
map<int,int> mark;
int main(){
    int q,n,i,j,ans,k,ma,mi,cou,l,r;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        cou=0;
        for(i=1;i<=n;i++){
            scanf("%d %d",&p[i].a,&p[i].b);
            mark[p[i].b]++;
        }
        sort(p+1,p+1+n);
        l=1,r=n;
        while(mark[p[l].b]>1 || mark[p[r].b]>1){
            if(mark[p[l].b]>1 && mark[p[r].b]>1){
                //printf("%d %d %d %d %d %d\n",l,p[l].b,mark[p[l].b],r,p[r].b,mark[p[r].b]);
                if(p[l+1].a-p[l].a > p[r].a-p[r-1].a){
                    //printf("a %d %d %d\n",p[l].b,mark[p[l].b],l);
                    mark[p[l].b]--,l++;continue;
                }else{
                    //printf("b %d %d %d\n",p[r].b,mark[p[r].b],r);
                    mark[p[r].b]--,r--;continue;
                }
            }
            if(mark[p[l].b]>1){
                //printf("c %d %d %d\n",p[l].b,mark[p[l].b],l);
                mark[p[l].b]--,l++;continue;
            }else{
                //printf("d %d %d %d\n",p[r].b,mark[p[r].b],r);
                mark[p[r].b]--,r--;continue;
            }
        }
        printf("%d\n",p[r].a-p[l].a+1);
        mark.clear();
    }
}
