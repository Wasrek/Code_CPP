#include "mars.h"
#include<bits/stdc++.h>
using namespace std;

std::string process(std::vector <std::vector<std::string>> a, int i, int j, int k, int n)
{
	int ii=i,jj=j,ns=1+(2*k),ni,nj;
	string out=string(100,'0');
	int cnt[11],now,sum;
	char d[15][15];
	memset(d,'0',sizeof d);
	if(k==0){
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				d[ii+i][jj+j]=a[i][j][0];
			}
		}	
	}else{
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				for(int ki=0;ki<10;ki++){
					for(int kj=0;kj<10;kj++){
						d[ki][kj]=max((int)d[ki][kj],(int)a[i][j][ki*10+kj]);
						// printf("%c",a[i][j][ki*10+kj]);
					}
				}
			}
		}
	}
	if(k==n-1){
		// for(int i=0;i<10;i++){
		// 	for(int j=0;j<10;j++){
		// 		printf("%c",d[i][j]);
		// 	}
		// 	printf("\n");
		// }
		queue<pair<int,int>>q;
		bool mk[101][101];
		pair<int,int>pr;
		int di[]={0,0,1,-1},dj[]={1,-1,0,0},mi=3;
		memset(mk,0,sizeof mk);
		now=0;
		for(int i=0;i<10;i++){
			for(int j=0;j<10;j++){
				if(d[i][j]=='0' || mk[i][j]) continue;
				q.push({i,j});
				mk[i][j]=1;
				now++;
				while(!q.empty()){
					pr=q.front();
					q.pop();
					for(int k=0;k<4;k++){
						ni=pr.first+di[k];
						nj=pr.second+dj[k];
						if(ni<0 || nj<0 || ni>=10 || nj>=10) continue;
						if(d[ni][nj]=='0') continue;
						if(mk[ni][nj]) continue;
						mk[ni][nj]=1;
						q.push({ni,nj});
					}
				}
			}
		}
		int i=0;
		// printf("- %d\n",now);
		while(now>0){
			// printf("%d\n",now);
			out[i]=(now%2)+'0';
			now/=2;
			i++;
		}

		return out;
	}
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			out[i*10+j]=d[i][j];
		}
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