#include<bits/stdc++.h>
using namespace std;
int n;
long long b,c;
struct A
{
	long long mat[10][10];
};
A x;
A pow(long long po)
{
	if(po==1)
		return x;
	A fis;
	A las;
	A tri;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n;j++)
		{
			las.mat[i][j]=0;
			tri.mat[i][j]=0;
		}
	}
	fis=pow(po/2);
	for(int i = 0;i <n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			for(int k = 0; k < n; k++)
			{
				las.mat[i][j]+=fis.mat[i][k]*fis.mat[k][j];
				las.mat[i][j]%=c;
			}
		}
	}
	if(po%2)
	{
		for(int i = 0; i< n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				for(int k = 0; k < n; k++)
				{
					tri.mat[i][j]+=x.mat[k][j]*las.mat[i][k];
					tri.mat[i][j]%=c;
				}
			}
		}
		return tri;
	}
	else
		return las;
}
int main()
{
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n;j++)
		{
			scanf("%lld",&x.mat[i][j]);
		}
	}
	cin>>b>>c;
	if(!b)
	{
		for(int i= 0; i< n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(i==j)
				{
					printf("1 ");
				}
				else 
					printf("0 ");
			}
			printf("\n");
		}
		return 0;
	}
	A ans=pow(b);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0 ; j < n; j++)
		{
			printf("%lld ",ans.mat[i][j]);
		}
		printf("\n");
	}
	return 0;
}