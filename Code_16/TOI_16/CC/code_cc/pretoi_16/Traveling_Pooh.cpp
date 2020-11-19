/*
    TASK:Traveling Pooh
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[200010],p[200010],cou[200010],num[200010];
int fin(int i){
    if(p[i]==i) return i;
    return p[i]=fin(p[i]);
}
void dfs(int i,int now,int pa){
    if(num[i]) return ;
    cou[pa]++;
    num[i]=now;
    dfs(a[i],now+1,pa);
}
int ch(int ss,int ee,int k){
    ss=num[ss];
    ee=num[ee];
    k=num[k];
    // printf("%d %d %d\n",ss,ee,k);
    if(ss<=ee){
        if(k>=ss && k<=ee) return 1;
        return 2;
    }else{
        if(k>=ss || k<=ee) return 1;
        return 2;
    }
}
int main()
{
    int n,q,x,y,s,e,px,py,pi,pa,ns,ne;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++) p[i]=i;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        pi=fin(i);
        pa=fin(a[i]);
        p[pi]=fin(pa);
    }
    for(int i=1;i<=n;i++){
        if(num[i]) continue;
        pi=fin(i);
        cou[pi]=0;
        dfs(i,1,pi);
    }
    // for(int i=1;i<=n;i++) printf("%d ",num[i]);
    while(q--){
        scanf("%d %d %d %d",&x,&y,&ns,&ne);
        px=fin(x);
        py=fin(y);
        s=fin(a[ns]);
        e=fin(a[ne]);
        if(s!=e){//diff
            if(px==py || (px==s && py==e) || (px==e && py==s)){
                printf("DEAD\n");
            }else{
                printf("SURVIVE\n");
            }
        }else{//same
            if(px!=s || py!=s){
                if(px==py) printf("DEAD\n");
                else printf("SURVIVE\n");
            }else{
                //a[ns] to ne
                // printf("here\n");
                // printf("%d %d %d %d\n",a[ns],ne,num[a[ns]],num[ne]);
                // printf("%d\n",ch(a[ns],ne,x));
                // printf("%d\n",ch(a[ns],ne,y));
                if(ch(a[ns],ne,x) == ch(a[ns],ne,y)){
                    printf("DEAD\n");
                }else printf("SURVIVE\n");
            }
        }
    }
    return 0;
}