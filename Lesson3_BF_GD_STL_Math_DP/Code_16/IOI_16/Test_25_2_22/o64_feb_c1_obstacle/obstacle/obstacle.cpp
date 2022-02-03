#include<bits/stdc++.h>
#include "obstacle.h"
#include "grader.cpp"
using namespace std;

int n,m,q;
long long dis[1010][1010],dis1[1010][1010];
vector< vector<int >> r,c;
// vector<int > a[100010];

void initialize(int N, int M, int Q,
		std::vector<std::vector<int>>& rowlen,
		std::vector<std::vector<int>>& collen)
{
	n=N;
	m=M;
	q=Q;
	r=rowlen;
	c=collen;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i!=0 && j!=0){
				dis[i][j]=min(dis[i-1][j]+c[i-1][j],dis[i][j-1]+r[i][j-1]);
			}
			else if(i==0 && j==0) dis[i][j]=0;
			else if(i==0) dis[i][j]=dis[i][j-1]+r[i][j-1];
			else if(j==0) dis[i][j]=dis[i-1][j]+c[i-1][j];
		}
	}
  for(int i=n-1;i>0;i--){
    for(int j=m;j>0;j--){
        if(i!=n && j!=m){
          dis1[i][j]=min(dis1[i+1][j]+c[i][j],dis1[i][j+1]+r[i][j]);
        }
        else if(i==n && j==m) dis1[i][j]=0;
        else if(i==n) dis1[i][j] = dis1[i][j+1]+r[i][j];
        else if(j==m) dis1[i][j]=dis[i+1][j]+c[i][j];
    }
  // }
	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<m;j++){
	// 		printf("%lld ",dis[i][j]);
	// 	}
	// 	printf("\n");
	// }
	}
}

int ask(int rr, int cc){
  long long ans=1<<18;
  for(int i=rr+1;i<n;i++){
    ans=min(dis[i][cc-1]+r[i][cc-1]+r[i][cc]+dis1[i][cc+1],ans);
  }
  return (int)(ans);
}
