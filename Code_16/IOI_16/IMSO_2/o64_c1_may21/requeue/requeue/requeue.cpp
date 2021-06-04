#include<bits/stdc++.h>
//#include "grader.cpp"
using namespace std;
#include <vector>
#define N 2500010
int lis[N];
int requeue(std::vector<int> Q, int k){
	int cnt=0,lb;
	for(int i=0;i<Q.size();i++){
		lb=lower_bound(lis,lis+cnt,Q[i])-lis;
		if(lb==cnt) cnt++;
		lis[lb]=Q[i];
	}
	int ans=0;
	while(cnt>1){
	  cnt=ceil((double)cnt/k);
	  ans++;
	}
	return ans;
}
/*
8 2
8 5 6 1 4 2 7 3
*/