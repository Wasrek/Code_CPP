/*
    TASK:
    LANG: CPP
    AUTHOR: Pun~
    SCHOOL: CRU
*/
#include<bits/stdc++.h>
using namespace std;
char a[2100][2100];
int n,m,i,j,w,l;
int ans[5000];
struct A
{
    int i,j,w,last;
};
queue< A > q;
int mark[2005][2005];
int main()
{
    scanf("%d %d",&n,&m);
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf(" %c",&a[i][j]);
        }
    }
    memset(ans,127,sizeof ans);
    q.push({0,0,0,a[0][0]-'a'});
    ans[0]=a[0][0]-'a';
    mark[0][0]=1;
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        w=q.front().w;
        l=q.front().last;
        q.pop();
        if(l!=ans[w])   continue;
        if(j+1<m && !mark[i][j+1])   mark[i][j+1]=1,ans[w+1]=min(ans[w+1],a[i][j+1]-'a'),q.push({i,j+1,w+1,a[i][j+1]-'a'});
        if(i+1<n && !mark[i+1][j])   mark[i+1][j]=1,ans[w+1]=min(ans[w+1],a[i+1][j]-'a'),q.push({i+1,j,w+1,a[i+1][j]-'a'});
    }
    for(i=0;i<n+m-1;i++)
        printf("%c",ans[i]+'a');
    return 0;
}
/*
2 3
abc
dcf

2 3
abe
bff
*/
