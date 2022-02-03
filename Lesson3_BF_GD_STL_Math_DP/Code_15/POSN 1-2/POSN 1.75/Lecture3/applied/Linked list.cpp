/*
    TASK:Linked list
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: REPS
*/
#include<bits/stdc++.h>
using namespace std;
int l[500100],r[500100];
int main(){
    int n,q;
    char c;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++){
        l[i]=i-1;
        r[i]=i+1;
    }
    r[0]=1;
    int x,y;
    while(q--){
        scanf(" %c",&c);
        if(c=='A'){
            scanf("%d %d",&x,&y);
            r[l[x]]=r[x];
            l[r[x]]=l[x];
            r[l[y]]=x;
            l[x]=l[y];
            r[x]=y;
            l[y]=x;
        }else
        if(c=='B'){
            scanf("%d %d",&x,&y);
            r[l[x]]=r[x];
            l[r[x]]=l[x];
            l[r[y]]=x;
            r[x]=r[y];
            r[y]=x;
            l[x]=y;
        }
    }
    int now=r[0],cou=0;
    while(1){
        if(cou==n)return 0;
        printf("%d ",now);
        cou++;
        now=r[now];
    }
}
