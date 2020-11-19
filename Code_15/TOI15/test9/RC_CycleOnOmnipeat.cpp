/*
    TASK:RC_CycleOnOmnipeat
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int a[100010];
map<int,int>mp;
int main(){
    int q,n,i,j,now,ch,mi,la,cou;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        mi=1<<30;
        for(i=1;i<=n;i++){
            scanf("%d",&a[i]);
            mi=min(mi,a[i]);
        }
        sort(a+1,a+1+n);
        cou=0,la=0;
        ch=0;
        for(i=1;i<=n;i++){
            printf("i:  %d\n",i);
            printf("a:  %d %d\n",a[i],a[i+1]);
            if(i!=n && a[i+1]!=a[i] &&a[i+1]!=a[i]+1)printf("!\n"),ch=1;
            printf("ich:  %d\n",ch);
            if(ch)break;
            printf("i:  %d\n",i);
            if(a[i+1]==a[i]){
                cou++;
                continue;
            }
            printf("i:  %d\n",i);
            cou--;
            printf("cou:  %d\n",cou);
            la=a[i];
            while(cou--){
                if(a[i+1]!=la && la!=0){ch=1;break;}
                i++;
            }
            cou=0;
        }
        if(!ch){
            printf("YES\n");
        }
    }
}
