#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int mic[2][2000100];
int main()
{
	int q;
	cin>>q;
	mic[0][0]=1;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2000001; j++)
		{
			mic[i][j+1]+=mic[i][j];
			mic[i][j+1]%=mod;
			mic[i][j+2]+=mic[i][j];
			mic[i][j+2]%=mod;
			if(j&&j%2==0&&!i)
			{
				mic[1][j/2]+=mic[i][j];
				mic[1][j/2]%=mod;
			}
		}
	}
	while(q--)
	{
		int a;
		scanf("%d",&a);
		printf("%d\n",(mic[0][a]+mic[1][a])%mod);
	}
	return 0;
}