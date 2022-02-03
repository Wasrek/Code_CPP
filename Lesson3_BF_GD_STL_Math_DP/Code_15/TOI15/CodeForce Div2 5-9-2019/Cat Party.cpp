/*
    TASK:Cat Party
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010],cou[15];
int main(){
    int n,i,j,ma=1,ch=0,u,l1=0,l2=0,c1,c2;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cou[a[i]]++;
        ch=1,l1=0,l2=0,c1=0,c2=0;
        for(j=1;j<=10;j++){
            if(!cou[j])continue;
            if(!l1)l1=cou[j];
            if(cou[j]!=l1 && !l2){
                l2=cou[j];
            }
            if(cou[j]!=l1 && cou[j]!=l2)ch=0;
            if(cou[j]==l1)c1++;
            if(cou[j]==l2)c2++;
        }
        //printf("%d\n%d %d %d %d\n",i,l1,c1,l2,c2);
        if(ch && ((c1==1 && (l1-l2==1 || l1==1)) || (c2==1&& (l2-l1==1 || l2==1)) || (l2==0 && c1==1))){ma=max(ma,i);}
    }
    printf("%d\n",ma);
}
