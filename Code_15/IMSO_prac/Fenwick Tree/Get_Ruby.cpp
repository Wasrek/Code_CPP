/*
    TASK:Get_Ruby
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[6];
int fw[751000];
void update(int v,int a){
    for(int i=a;i<=750000;i+=(i&-i)){
        fw[i]+=v;
    }
}
int query(int a){
    int sum=0;
    for(int i=a;i>0;i-=(i&-i)){
        sum+=fw[i];
    }
    return sum;
}
int main()
{
    int n,m,a,b,ans;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf(" %s",s);
        scanf("%d %d",&a,&b);
        if(s[0]=='B'){
            update(a,b);
        }else{
            ans=query(b)-query(a-1);
            printf("%d\n",ans);
        }
    }
    return 0;
}
