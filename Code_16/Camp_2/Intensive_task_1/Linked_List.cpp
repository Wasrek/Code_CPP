/*
    TASK:Linked list
    LANG: CPP
    AUTHOR: Wichada
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
int l[500010],r[500010];
int main()
{
    int n,k,a,b;
    char opr;
    scanf("%d %d",&n,&k);
    for(int i=0;i<=n;i++){
        l[i]=i-1;
        r[i]=i+1;
    }
    while(k--){
        scanf(" %c",&opr);
        scanf("%d %d",&a,&b);
        
        r[l[a]]=r[a];
        l[r[a]]=l[a];
        if(opr=='A'){
            r[l[b]]=a;
            l[a]=l[b];
            r[a]=b;
            l[b]=a;
        }else{
            l[r[b]]=a;
            r[a]=r[b];
            r[b]=a;
            l[a]=b;
        }
    }
    int st=r[0],cnt=0;
    while(cnt<n){
        printf("%d ",st);
        st=r[st];
        cnt++;
    }
    printf("\n");
    return 0;
}