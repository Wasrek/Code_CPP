/*
    TASK:TT_Gameshow
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int qs[100100],o[100100],q[100010][2],cou[100100],ans[100100];
int main(){
    int n,Q,i,l,r,now,j,cc;
    scanf("%d %d",&n,&Q);
    for(i=1;i<=n;i++){
        scanf("%d",&o[i]);
        if(o[i]>100000)o[i]=0;
        cou[o[i]]++;
    }
    for(i=1;i<=Q;i++){
        scanf("%d %d",&q[i][0],&q[i][1]);
    }
    for(i=1;i<=100000;i++){
        if(cou[i]<i)continue;
        for(j=1;j<=n;j++){
            if(o[j]==i)qs[j]=1;
            qs[j]+=qs[j-1];
        }
        for(j=1;j<=Q;j++){
            if(qs[q[j][1]]-qs[q[j][0]-1]>=i)ans[j]++;
        }
        memset(qs,0,sizeof qs);
    }
    for(i=1;i<=Q;i++)printf("%d\n",ans[i]);
    return 0;
}
