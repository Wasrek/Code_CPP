/*
    TASK:RT_KillTimeGame
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,i,n,w,mi,now,a;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&a);
        w=0;
        mi=a;w++;
        for(i=2;i<=n;i++){
            scanf("%d",&now);
            if(now<mi)w++,mi=now;
        }
        w++;
        w%=8;
        if(w==1)printf("Dr.Peartt");
        else if(w==2)printf("Porn");
        else if(w==3)printf("Born");
        else if(w==4)printf("Nornt");
        else if(w==5)printf("Borss");
        else if(w==6)printf("Norn");
        else if(w==7)printf("Girg");
        else printf("Asira");
        printf("\n");
    }
    return 0;
}
