/*
    TASK:Space TOI14
    LANG: C++
    AUTHOR: KersaWC
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
struct A{
    int i1,j1,i2,j2;
};
char s[10100][2100];
A a[20000000];
int c[10100][2100],cnt=1,di[]={0,0,1,-1},dj[]={1,-1,0,0};
void dfs(int i,int j){
    int k,ii,jj;
    c[ii][jj]=cnt;
    for(k=0;k<4;k++){
        ii=i+di[k];
        jj=j+dj[k];
        if(s[ii][jj]=='a')dfs(ii,jj);
    }
}
int main(){
    int n,m,i,j,ans1,ans2,ans3;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++){
        scanf(" %s",s[i]+1);
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s[i][j]=='1' && c[i][j]==0)dfs(i,j),cnt++;
        }
    }
    for(i=1;i<=m;i++){
        for(j=1;j<=n;j++){
            if(s[i][j]=='1' && s[i-1][j]!='1' && s[i][j-1]!='1'){
                a[c[i][j]].i1=i;
                a[c[i][j]].j1=j;
            }
            if(s[i][j]=='1' && s[i+1][j]!='1' && s[i][j+1]!='1'){
                a[c[i][j]].i2=i;
                a[c[i][j]].j2=j;
            }
        }
    }
    cnt--;
    int ii,jj,iii,jjj;
    ans1=ans2=ans3=0;
    for(i=1;i<=cnt;i++){
        ii=a[i].i1;
        jj=a[i].j1;
        iii=a[i].i2;
        jjj=a[i].j2;
        if(s[ii+1][jj]=='1'&& s[ii][jj+1]=='1')ans1++;
        else
        if(s[ii+1][jj]=='1' && s[ii+1][jj-1]=='1' && s[ii+1][jj+1]=='1' && s[iii-1][jjj]=='1' && s[iii-1][jjj-1]=='1' && s[iii-1][jjj+1]=='1')ans2++;
    }
    printf("%d %d %d",ans1,ans2,cnt-ans1-ans2);
}
