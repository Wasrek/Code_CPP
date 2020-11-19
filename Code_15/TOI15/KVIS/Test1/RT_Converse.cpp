/*
    TASK:RT_Converse
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[10],b[10];
int main(){;
    int q,n,i,j,now,cb,ca,ch,k,l;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        cb=ca=0;
        ch=1;
        for(i=1;i<=n;i++){
            scanf("%d",&now);
            a[now]++;
        }
        for(i=1;i<=n;i++){
            scanf("%d",&now);
            b[now]++;
        }
        for(i=1;i<=5;i++){
            if((a[i]+b[i])%2!=0){
                ch=0;
                break;
            }else
            if(a[i]<b[i]){
                k=b[i]-a[i];
                k/=2;
                ca+=k;
            }else
            if(b[i]<a[i]){
                k=a[i]-b[i];
                k/=2;
                cb+=k;
            }
        }
        if(!ch || ca!=cb){
            printf("-1\n");
        }else{
        printf("%d\n",ca);
        }
        //printf("%d %d %d\n",ca,cb,ch);
        memset(a,0,sizeof a);
        memset(b,0,sizeof b);
    }
}
/*
2
9
1 2 4 1 4 1 4 4 1
2 3 5 2 5 3 2 3 3
*/
