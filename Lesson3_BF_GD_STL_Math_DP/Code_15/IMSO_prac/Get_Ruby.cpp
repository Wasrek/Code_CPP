/*
    TASK:Get_Ruby
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int fw[750100],n;
char s[6];
void update(int a,int v){
    for(int i=a;i<=n;i+=(i&-i)){
        fw[i]+=v;
    }
}
int query(int l,int r){
    int sum=0;
    for(int i=r;i>0;i-=(i&-i)){
        sum+=fw[i];
    }
    for(int i=l-1;i>0;i-=(i&-i)){
        sum-=fw[i];
    }
    return sum;
}
int main()
{
    int m,a,b,ans;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf(" %s",s);
        scanf("%d %d",&a,&b);
        if(s[0]=='B'){
            update(b,a);
        }else{
            ans=query(a,b);
            printf("%d\n",ans);
        }
    }
}
/*
10 5
Bury 5 5
Bury 10 7
Find 3 7
Bury 20 8
Find 6 10
*/
