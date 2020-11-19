/*
    TASK:Cryptopangrams
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
long long a[10100],s[10100],ans[10100];
map<long long,long long> ma;
map<long long,char>ch;
int main(){
    int q,t,n,i,j,l,f;
    scanf("%d",&t);
    for(q=1;q<=t;q++){
        scanf("%d %d",&n,&l);
        j=0;
        for(i=1;i<=l;i++){
            scanf("%d",&a[i]);
        }
        for(i=2;i<a[1];i++){
            if(a[1]%i==0){f=i;break;}
        }
        ma[f]=1;
        ma[a[1]/f]=1;
        s[++j]=f;
        s[++j]=(a[1]/f);
        if(a[2]%f==0){
            ans[1]=(a[1]/f);
            ans[2]=f;
        }else{
            ans[1]=f;
            ans[2]=(a[1]/f);
        }
        for(i=2;i<=l;i++){
            ans[i+1]=(a[i]/ans[i]);
            if(ma[ans[i+1]]!=1){
                ma[ans[i+1]]=1;
                s[++j]=ans[i+1];
            }
        }
        sort(s+1,s+j+1);
        for(i=1;i<27;i++){
            ch[s[i]]='A'+i-1;
            printf("%lld %c \n",s[i],ch[s[i]]);
        }
        printf("Case #%d: ",q);
        for(i=1;i<=l+1;i++){
            printf("%c",ch[ans[i]]);
            //printf("%d ",ans[i]);
        }
        printf("\n");
        ma.clear();
        ch.clear();
    }
    return 0;
}
