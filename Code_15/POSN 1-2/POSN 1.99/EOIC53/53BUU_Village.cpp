/*
    TASK:53BUU_Village
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int in[50100],out[50100];
int main(){
    int q,j;
    scanf("%d",&q);
    while(q--){
        int n,m;
        scanf("%d %d",&n,&m);
        int a,b;
        while(m--){
            scanf("%d %d",&a,&b);
            out[a]++;
            in[b]++;
        }
        int ch=0,couin=0,couout=0;
        for(j=1;j<=n;j++){
            if(out[j]==in[j])continue;
            if(out[j]-in[j]==1)couout++,ch=2;
            if(in[j]-out[j]==1)couin++,ch=2;
            if(couout>1 || couin>1){ch=1;break;}
        }
        if(ch==2 && couout==1 && couin==1)ch=0;
        if(ch)printf("No\n");
        else printf("Yes\n");
        memset(in,0,sizeof in);
        memset(out,0,sizeof out);
    }
}
