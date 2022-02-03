/*
    TASK:RC_WingPhlad
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
long long a[100010],ch[100010],mark[100010];
int main(){
    long long q,n,m,i,j,sum,mm;
    scanf("%lld",&q);
    while(q--){
        scanf("%lld %lld",&n,&m);
        m--;
        mm=m;
        sum=0;
        for(i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum+=a[i];
            ch[a[i]]=1;
        }
        ch[0]=1;
//        printf("%d\n",m);
        if(ch[1] || m==0){
            printf("%lld\n",mm);
        }else{
        sort(a+1,a+1+n);
        for(i=1;i<=n;i++){
            if(ch[a[i]]>1){mark[i]=1;continue;}
            if(a[i]>m)continue;
        for(j=1;j<=m;j*=a[i]){
            ch[j]++;
        }
        }
//        for(i=1;i<=m;i++){
//            printf("%d ",ch[i]);
//        }
        for(i=1;i<=n;i++){
            if(mark[i])continue;
            for(j=1;j<=m;j++){
                if(ch[j])ch[j+a[i]]++;
            }
        }
        for(i=m;i>=0;i--){
            if(ch[i]){printf("%lld\n",i);break;}
        }
        }
        memset(ch,0,sizeof ch);
        memset(mark,0,sizeof mark);
    }
}
