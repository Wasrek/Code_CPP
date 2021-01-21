/*
    TASK:Yoyo
    LANG: CPP
    AUTHOR: KersW
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int n;
char s[8];
int fw[500010];
void update(int l,int r,int v){
    for(int i=l;i<=n;i+=(i&-i))fw[i]+=v;
    for(int i=r+1;i<=n;i+=(i&-i))fw[i]-=v;
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
    int m,a,b,c,ans;
    scanf("%d %d",&n,&m);
    while(m--){
        scanf(" %s",s);
        if(s[0]=='Y'){
            scanf("%d %d %d",&a,&b,&c);
            if(c<b)swap(c,b);
            update(b,c,a);
        }else{
            scanf("%d",&a);
            ans=query(a);
            printf("%d\n",ans);
        }
    }
}
/*
7 6
Yoyo 10 4 7
Yoyo 15 1 5
Ask 4
Yoyo 5 3 6
Ask 5
Ask 7
*/
