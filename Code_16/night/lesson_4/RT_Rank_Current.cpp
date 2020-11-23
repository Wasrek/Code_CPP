/*
    TASK:
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int f,a;
};
vector< A > qu;
int fw[300100];
vector<int> num;
unordered_map< int,int> mp;
void upd(int a){
    for(int i=a;i<=300000;i+=(i&-i)) fw[i]++;
}
int que(int a){
    int ans=0;
    for(int i=a;i>0;i-=(i&-i)) ans+=fw[i];
    return ans; 
}
int main()
{
    int n,f,a,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&f,&a);
        qu.push_back({f,a});
        if(f==1) num.push_back(a);
    }
    sort(num.begin(),num.end());
    for(auto x:num){
        mp[x]=++cnt;
    }
    for(auto x: qu){
        if(x.f==1){
            upd(mp[x.a]);
        }else{
            printf("%d\n",que(mp[x.a]));
        }
    }
    return 0;
}