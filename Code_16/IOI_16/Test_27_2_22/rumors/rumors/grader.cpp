#include "rumors.h"
#include <cstdio>
#include <cassert>
#include <vector>
#include "rumors.h"
#include<bits/stdc++.h>
using namespace std;
int l[800100],r[800100];
vector< int > all;
unordered_map< int,int> mp,re;
std::vector<int> analyze_rumors(int N, int K, int Q, std::vector<int> d, std::vector<int> x, std::vector<int> j) {
	for(int i=0;i<N;i++){
		mp[i]=d[i];
	}
	sort(d.begin(),d.end());
	for(int i=0;i<N;i++){
		re[d[i]]=i;
		// printf("- %d %d\n",d[i],i);
	}
	for(int i=0;i<Q;i++){
		x[i]=re[mp[x[i]]];
	}
	// for(int i=0;i<N;i++){
	// 	printf("%d ",d[i]);
	// }
	// printf("\n");
	// for(int j=0;j<Q;j++){
	// 	printf("%d ",x[j]);
	// }
	// printf("\n");
  for(int i=0;i<N;i++){
	  r[i]=l[i]=i;
    for(int j=i;j<N;j++){
    	if(d[j]-d[i]<=K) r[i]=j;
		else break;
    }
    for(int j=i;j>=0;j--){
		if(d[i]-d[j]<=K) l[i]=j;
		else break;
    }
	// printf("%d %d\n",l[i],r[i]);
  }
  for(int i=0;i<N;i++){
	  all.push_back(r[x[i]]-l[x[i]]+1);
	//   printf("%d ",r[x[i]]-l[x[i]]+1);
  }
	return all;
}



int main(){
	int N, K, Q;
	std::vector<int> d;
	scanf("%d%d%d",&N,&K,&Q);
	assert(1 <= N && N <= 2000);
	assert(1 <= K && K <= 100000);
	assert(1 <= Q && Q <= 800000);
	for(int i = 0; i < N; i++){
		int x;
		scanf("%d", &x);
		d.push_back(x);
		assert(x <= 9999999);
		if(i > 0) assert(d[i-1] < d[i]);
	}
	std::vector<int> qx, qj;
	for(int i = 0; i < Q; i++){
		int x, j;
		scanf("%d%d",&x,&j);
		assert(0 <= x && x < N);
		assert(0 <= j && j <= 9999999);
		qx.push_back(x);
		qj.push_back(j);
	}
	std::vector<int> answers = analyze_rumors(N, K, Q, d, qx, qj);
	for(int ans : answers){
		printf("%d\n", ans);
	}
	return 0;
}
