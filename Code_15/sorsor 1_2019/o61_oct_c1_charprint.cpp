/*
    TASK:Charprint
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector<long long> a[30];
long long ar[30],cnt[30];
char s[300100],ask[100100];
long long fw[300100];
long long query(long long n){
    long long sum=0,i;
    for(i=n;i>0;i-=(i&-i)){
        sum+=fw[i];
    }
    return sum;
}
void update(long long n){
    for(int i=n;i<=300000;i+=(i&-i))fw[i]++;
}
int main(){
    long long opr,i,j,len,lena,ans=0,ch=0;
    scanf(" %lld",&opr);
    scanf(" %s",s+1);
    scanf(" %s",ask+1);
    len=strlen(s+1);
    lena=strlen(ask+1);
    for(i=1;i<=len;i++){
        a[s[i]-'a'].push_back(i);
    }
    for(i=1;i<=lena;i++){
        ar[ask[i]-'a']++;
    }
    for(i=0;i<='z'-'a';i++){
        if(ar[i]==0)continue;
        if(ar[i]>a[i].size()){ch=1;break;}
        for(j=0;j<ar[i];j++){
            ans+=a[i][j];
        }
    }
    if(ch){
        printf("-1");
        return 0;
    }
    if(opr==0){
        printf("%lld\n",ans);
        return 0;
    }
    for(i=1;i<=lena;i++){
        cnt[ask[i]-'a']++;
        ans-=query(a[ask[i]-'a'][cnt[ask[i]-'a']-1]);
        update(a[ask[i]-'a'][cnt[ask[i]-'a']-1]);
    }
    printf("%lld\n",ans);
    return 0;
}