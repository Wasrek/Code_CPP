#include "perm.h"
#include<bits/stdc++.h>
using namespace std;
std::vector<int> find_K(long long k)
{
	vector<int> sq,ans;
	int ch=0;
	for(int i=61;i>=0;i--){
		if(k & (1ll<<i)){
			sq.push_back(i);
		}
		// printf("%d\n",i);
	}
	long long lf=sq.size()-1;
	int st;
	vector< int > nowv;
	if(lf>3){
		nowv=find_K(lf);
		st=nowv.size()+1;
		if(st>lf) ch=0,st=lf;
		else ch=1;
	}else{
		st=lf;
		ch=0;
	}
	int sum=st;
	for(auto x: sq){
		// printf("%d ",x);
		sum+=x;
	}
	// printf("\n%d - %d\n",sum,sq.size());
	int now=sum-1;
	for(int i=0;i<=sq.size()-1;i++){
		// printf("%d %d\n",sq[i],now);
		if(sq[i]<1) continue;
		for(int k=now-sq[i]+1;k<=now;k++){
			ans.push_back(k);
		}
		now-=sq[i];
	}
	if(ch==0){
		for(int i=(lf-1);i>=0;i--){
			ans.push_back(i);
		}
		return ans;
	}
	for(auto x: nowv) ans.push_back(x+1);
	ans.push_back(0);
	// for(auto x: ans){
	// 	printf("%d ",x);
	// }
	return ans;
}
std::vector<int> construct_permutation(long long k){
	vector< int > ans;
	ans=find_K(k);
	return ans;
}