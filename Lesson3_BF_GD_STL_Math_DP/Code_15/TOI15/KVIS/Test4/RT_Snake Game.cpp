/*
    TASK:RT_Snake Game
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char a[1010][1010];
int rig[1010],lef[1010],cou[1010];
int main(){
    int n,m,i,j,ch,b,alljelly=0;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        ch=0;
        for(j=1;j<=m;j++){
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='J'){
                cou[i]++;
                if(!ch){
                    ch++;
                    lef[i]=j;
                    rig[i]=j;
                }
                if(ch==1){
                    rig[i]=j;
                }
            }
        }
        alljelly+=cou[i];
    }
    int s=1,ans=0,last=1;
    for(i=n;i>=0;i--){
        if(!alljelly)
        {
            printf("%d\n",ans);
            break;
        }
        alljelly-=cou[i];
        if(i==n)
        {
            if(!cou[i]) rig[i]=1,lef[i]=1,last=1;
            else        last=rig[i],ans+=rig[i]-1;
            ++s;
            s%=2;
        }
        else if(!cou[i]){
            ++ans,++s,s%=2;
        }
        else if(s%2)
        {
            ans+=abs(lef[i]-last)+rig[i]-lef[i]+1;
            ++s,s%=2;
            last=rig[i];
        }
        else
        {
            ans+=abs(rig[i]-last)+rig[i]-lef[i]+1;
            ++s,s%=2;
            last=lef[i];
        }
//        printf("%d %d\n",ans,last);
    }
    return 0;
}
/*
5 5
...J.
.....
J..J.
J....
Z....
*/
