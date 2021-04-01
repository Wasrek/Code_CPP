#include "rumors.h"
#include<bits/stdc++.h>
using namespace std;
vector< int > ans;
int l[800100],r[800100],fil[10000010],fir[10000010],ansl[800100],ansr[800100];
unordered_map< int,int > mp,re;
vector< int > mid[10000010];
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
  mp.clear();
  for(int i=0;i<Q;i++){
    fil[i]=d[x[i]]-K;
    fir[i]=d[x[i]]+K;
    l[i]=0,r[i]=N-1;ansl[i]=0,ansr[i]=N-1;
	// printf("%d %d\n",fil[i],fir[i]);
  }
  int ch=1;
  //left cant -> can
  while(ch){
    ch=0;
    for(int i=0;i<Q;i++){
      if(ansl[i]==r[i]) continue;
      ch=1;
      mid[(ansl[i]+r[i])/2].push_back(i);
      mp[(ansl[i]+r[i])/2]=1;
    }
    if(!ch) break;
    for(int i=0;i<N;i++){
      if(!mp[i]) continue;
	//   printf("%d\n",i);
      for(auto x: mid[i]){
		// printf("%d %d %d ",x,fil[x],d[i]);
        if(fil[x]<=d[i]) r[x]=i;
        else ansl[x]=i+1;
		// printf("%d %d %d\n",x,l[x],r[x]);
      }
      mid[i].clear();
    }
    mp.clear();
	// printf("%d\n",ch);
    //delete mid and mp
  }
//   for(int i=0;i<Q;i++){
//     printf("- %d %d\n",l[i],r[i]);
//   }


	// right
  	ch=1;
	while(ch){
		ch=0;
		for(int i=0;i<Q;i++){
		if(l[i]==ansr[i]) continue;
		ch=1;
		mid[(l[i]+ansr[i]+1)/2].push_back(i);
		mp[(l[i]+ansr[i]+1)/2]=1;
		}
		if(!ch) break;
		for(int i=0;i<N;i++){
		if(!mp[i]) continue;
		//   printf("%d\n",i);
		for(auto x: mid[i]){
			// printf("%d %d %d ",x,fil[x],d[i]);
			if(fir[x]>=d[i]) l[x]=i;
			else ansr[x]=i-1;
			// printf("%d %d %d\n",x,l[x],r[x]);
		}
		mid[i].clear();
		}
		mp.clear();
		// printf("%d\n",ch);
		//delete mid and mp
	}
	for(int i=0;i<Q;i++){
		// printf("%d %d %d\n",i,ansl[i],ansr[i]);
		ans.push_back(ansr[i]-ansl[i]+1);
	}
	return ans;
}