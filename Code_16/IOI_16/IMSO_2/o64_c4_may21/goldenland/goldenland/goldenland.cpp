#include<bits/stdc++.h>
#include <vector>
// #include "grader.cpp"
using namespace std;
long long gr[1000100],ci[60100],cj[60100];
int si[100100],sj[100100];
void init_land(int N, int M, int P, std::vector<int> A, std::vector<int> B){
	int cnt=0;
	for(int i=1;i<=1000000;i++){
        if(gr[i]) continue;
		cnt++;
        for(int j=1;j<=1000;j++){
            if(i*j*j>1000000) break;
            gr[i*j*j]=i;
        }
    }
	for(int i=0;i<N;i++){
		ci[i+1]=gr[A[i]];
	}
	for(int i=0;i<M;i++){
		cj[i+1]=gr[B[i]];
	}
}

long long answer_query(int r1, int c1, int r2, int c2){
	r1++,c1++,r2++,c2++;
	long long ans=0;
	for(int i=r1;i<=r2;i++){
		si[ci[i]]++;
	}
	for(int i=c1;i<=c2;i++){
		sj[cj[i]]++;
	}
	for(int i=0;i<=100000;i++){
		ans+=(si[i]*sj[i]);
	}
	return ans;
}

/*
8 8 1
5 4 1 2 8 9 3 7
2 1 4 3 8 6 5 2
*/

