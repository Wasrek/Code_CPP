#include "mars.h"
#include<bits/stdc++.h>
using namespace std;

std::string process(std::vector <std::vector<std::string>> a, int i, int j, int k, int n)
{
	int ii=i,jj=j,ns=1+(2*k),ni,nj;
	string out=string(100,'0');
	int cnt[11],now,sum;
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			for(int k=0;k<99;k++){
				a[i][j][k]-='0';
			}
			now=(i*3)+j+1;
			sum=0;
			for(int k=0;k<12;k++){
				sum+=(a[i][j][k]*(1<<k));
			}
			cnt[now]=sum;
			// printf("%d %d ",now,sum);
		}
	}
	// printf("\n");
	if(k==0){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				a[i][j][12]=a[i][j][55]=a[i][j][0];
			}
		}
	}
	// printf("%d %d %d\n",k,ii,jj);
	// for(int i=1;i<=9;i++){
	// 	printf("%d ",cnt[i]);
	// }
	// printf("\n");
	now=cnt[9];
	int ch=0;
	for(int j=1;j>=0;j--){
		for(int k=12+ns-1;k>=12;k--){
			if(!a[2][j][k]) continue;
			if(a[2][j][k] && a[2][j+1][k]){
				if(ch) now--; ch=0;
			}else if( k!=12+ns-1 && a[2][j][k] && a[2][j][k+1]){

			}else{
				now++;
				ch=1;
			}
		}
	}
	// printf("- %d\n",now);
	ch=0;
	for(int i=1;i>=0;i--){
		for(int k=55+ns-1;k>=55;k--){
			if(!a[i][2][k]) continue;
			if(a[i][2][k] && a[i+1][2][k]){
				if(ch) now--; ch=0;
			}else if(k!=55+ns-1 && a[i][2][k] && a[i][2][k+1]){

			}else{
				now++; ch=1;
			}
		}
	}
	// printf("%d\n",now);
	for(int i=1;i>=0;i--){
		for(int j=1;j>=0;j--){
			if(!a[i][j][12]) continue;
			if(a[i+1][j][12] || a[i][j+1][12]){
				if(a[i+1][j][12] && a[i][j+1][12] && !a[i+1][j+1][12]) now--;
			}else{
				now++;
			}
		}
	}
	// printf("%d\n",now);
	for(int i=0;i<12;i++){
		// printf("%d\n",now);
		out[i]=(now%2)+'0';
		now/=2;
	}
	// printf("\n");
	if(k==n-1){
		for(int i=12;i<100;i++){
			out[i]='0';
		}
		// for(int i=0;i<100;i++){
		// 	printf("%c",out[i]);
		// }
		return out;
	}
	out[12]=a[0][0][12]+'0';
	out[13]=a[1][0][12]+'0';
	for(int i=12;i<55;i++){
		out[i+2]=a[2][0][i]+'0';
	}
	out[55]=a[0][0][12]+'0';
	out[56]=a[0][1][12]+'0';
	for(int i=55;i<100;i++){
		out[i+2]=a[0][2][i]+'0';
	}
	// for(int i=0;i<100;i++){
	// 	printf("%c",out[i]);
	// }
	// printf("\n");
	queue<pair<int,int>>q;
	bool mk[5][5];
	pair<int,int>pr;
	int di[]={0,0,1,-1},dj[]={1,-1,0,0},mi=3;
	memset(mk,0,sizeof mk);
	if(k==0){
		if(out[12]=='1'){
			q.push({0,0});
			while(!q.empty()){
				pr=q.front();
				q.pop();
				if(pr.first==0 && pr.second!=0){
					mi=min(mi,pr.second);
				}
				for(int k=0;k<4;k++){
					ni=pr.first+di[k];
					nj=pr.second+dj[k];
					if(ni<0 || nj<0 || ni>=3 || nj>=3) continue;
					if(!a[ni][nj][12]) continue;
					q.push({ni,nj});
				}
			}
			if(mi==3) mi=0;
		}
	}
	for(int i=94;i<100;i++){
		
	}
	return out;
}
/*
2
11111
00100
00001
11000
11100
*/