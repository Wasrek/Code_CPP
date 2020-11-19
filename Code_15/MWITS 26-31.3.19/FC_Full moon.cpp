/*
    TASK:FC_Full moon
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int a[100100],b[100100],gs[100100],gh[100100],bs[100100],bh[100100];
int main(){
    int n,i,ans=0,cou1=0,cou2=0,cou3=0,cou4=0,Mi,x,y;
    scanf("%d",&n);
    for(i=0;i<n;i++){
            scanf("%d",&a[i]);
            if(a[i]<0)gs[++cou1]=a[i]*-1;
            else gh[++cou2]=a[i];
    }
    for(i=0;i<n;i++){
            scanf("%d",&b[i]);
            if(b[i]<0)bs[++cou3]=b[i]*-1;
            else bh[++cou4]=b[i];
    }
    sort(gs+1,gs+cou1+1);
    sort(gh+1,gh+cou2+1);
    sort(bs+1,bs+cou3+1);
    sort(bh+1,bh+cou4+1);
    x=y=1;
    while(x<=cou1 && y<=cou4){
        if(gs[x]>bh[y])ans++,y++,x++;
        else{
            x++;
        }
    }
    x=y=1;
    while(x<=cou3 && y<=cou2){
        if(bs[x]>gh[y])ans++,y++,x++;
        else{
            x++;
        }
    }
    printf("%d\n",ans);
}
