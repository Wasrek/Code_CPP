#include<bits/stdc++.h>
#include "obstacle.h"
#include "grader.cpp"
using namespace std;
vector<vector<int>> dr,ul,ans; 
void initialize(int N, int M, int Q,
		std::vector<std::vector<int>>& rowlen,
		std::vector<std::vector<int>>& collen)
{
	dr.resize(N,vector<int>(M,2e9));
	ul.resize(N,vector<int>(M,2e9));
	ans.resize(N,vector<int>(M,2e9));
	dr[0][0]=0;
	ul[N-1][M-1]=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			if(i>0) dr[i][j]=min(dr[i][j],dr[i-1][j]+collen[i-1][j]);
			if(j>0) dr[i][j]=min(dr[i][j],dr[i][j-1]+rowlen[i][j-1]);
		}
	}
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		printf("%d ",dr[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(int i=N-1;i>=0;i--){
		for(int j=M-1;j>=0;j--){
			if(i<N-1) ul[i][j]=min(ul[i][j],ul[i+1][j]+collen[i][j]);
			if(j<M-1) ul[i][j]=min(ul[i][j],ul[i][j+1]+rowlen[i][j]);
		}
	}
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		printf("%d ",ul[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(int i=N-1;i>=0;i--){
		for(int j=0;j<M;j++){
			if(j==0 || i==N-1){ans[i][j]=2e9;continue;}
			ans[i][j]=min(dr[i+1][j-1]+rowlen[i+1][j-1]+ul[i+1][j],ans[i+1][j]);
		}
	}
	// for(int i=0;i<N;i++){
	// 	for(int j=0;j<M;j++){
	// 		printf("%d ",ans[i][j]);
	// 	}
	// 	printf("\n");
	// }
}

int ask(int r, int c)
{
	if(ans[r][c]==2e9) return -1;
    return ans[r][c];
}