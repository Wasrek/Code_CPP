/*
    TASK:RC_Sharp
    LANG: CPP
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
char s[510],c[510][29];
int sh[510];
int main(){
    int a,n,m,k,i,j,kk,mo,mm,len,cnt;
    scanf("%d %d %d %d",&n,&m,&k,&a);
    a--;
    scanf(" %s",s);
    mm=m;
    for(i=1;i<=m;i++){
        scanf(" %s",c[i]);
        sort(c[i],c[i]+k);
        sh[mm--]=a%k;
        a/=k;
    }
    j=0;
    //for(i=1;i<=m;i++)printf("%s\n",c[i]);
    for(i=0;i<n;i++){
        if(s[i]=='#'){
            printf("%c",c[++j][sh[j]]);
        }
        else
            printf("%c",s[i]);
    }
}
/*
9 2 3 7
peat#hi#y
sol
nuz
*/
