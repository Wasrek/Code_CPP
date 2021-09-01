#include "rumors.h"
#include<bits/stdc++.h>
using namespace std;
vector< int > ans,l[2010],r[2010];
std::vector<int> analyze_rumors(int N, int K, int Q, std::vector<int> d, std::vector<int> x, std::vector<int> y) {
	for(int i=0;i<N;i++){
		  l[i].push_back(0);
		  for(int j=i-1;j>=0;j--){
			l[i].push_back((d[j+1]-d[j]-1)/K);
		  }
		  for(int j=1;j<l[i].size();j++){
			  l[i][j]+=l[i][j-1];
		  }
		  for(int j=i+1;j<N;j++){
			r[i].push_back((d[j]-d[j-1]-1)/K);
		  }
		  for(int j=1;j<r[i].size();j++){
			  r[i][j]+=r[i][j-1];
		  }
	}
	int le,en,qans;
	for(int q=0;q<Q;q++){
		qans=1;
		for(int i=x[q];i>=0 && l[x[q]][x[q]-i]<=y[q];i--){
			le=y[q]-l[x[q]][x[q]-i];
			en=upper_bound(r[x[q]].begin(),r[x[q]].end(),le)-r[x[q]].begin();
			qans=max(qans,x[q]-i+en+1);
		}
		ans.push_back(qans);
	}
	return ans;
}
