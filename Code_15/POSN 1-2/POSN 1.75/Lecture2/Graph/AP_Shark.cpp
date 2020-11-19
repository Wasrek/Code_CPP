/*
    TASK:
    LANG: CPP
    AUTHOR: SSometime
    SCHOOL: RYW
*/
#include<bits/stdc++.h>
using namespace std;
vector<int>	g[1010];
int w[1010],mark[1010],j,i;
long long sum,ma=-1e9;
void dfs(int u){
	if(mark[u]==j)	return ;
	mark[u]=j;
	sum+=w[u];
	for(i=0;i<g[u].size();i++)
		dfs(g[u][i]);
}
int main()
{
	int n,m,i,ans=1,r,s;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%d",&w[i]);
	for(i=0;i<m;i++){
		scanf("%d %d",&r,&s);
		g[r].push_back(s);
	}
	for(j=1;j<=n;j++){
		sum=0;
		dfs(j);
		if(sum>ma)
			ma=sum,ans=j;
	}
	printf("%d %lld\n",ans,ma);
    return 0;
}
