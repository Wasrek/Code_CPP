#include <bits/stdc++.h>
using namespace std;
long long a[30],c;

long long play(long long state,long long n)
{
	long long now = 2*n+1 - a[state];
	if(n<=0 || now<2) 
	{
		c=1;
		return -1;
	}
	if(state==0) return n;
	if(now%2==1) return play(state-1,now/2+1)+play(state-1,now/2);
	else return 2*play(state-1,now/2);
}

int main()
{
	long long q,k,w,i,temp;
	scanf("%lld",&q);
	while(q--)
	{
		c=0;
		scanf("%lld %lld",&k,&w);
		for(i=1;i<=k-1;i++) scanf("%lld",&a[i]);
		temp = play(k-1,w);
		if(temp>0 && !c) printf("%lld\n",temp);
		else printf("-1\n");
		memset(a,0,sizeof a);
	}
}
