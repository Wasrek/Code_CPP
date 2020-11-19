#include<bits/stdc++.h>
#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(),(a).end()
#define SZ(a) (int)(a).size()

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef double DD;
typedef long double LD;
typedef pair<LL,LL> PLL;
typedef pair<DD,DD> PDD;
typedef vector<int> VI;
typedef vector<LL> VL;
const int N=305, inf = 1<<30;
int table[N][N], tmp[N][N], qs[N][N];
int dp[N][N][N];

// void print(int r, int c){
// 	int i,j;
// 	printf("##########\n");
// 	for(i = 1;i<=r;i++){
// 		for(j=1;j<=c;j++){
// 			printf("%lld ",table[i][j]);
// 		}
// 		printf("\n");
// 	}
// }

void gen_qs(int r, int c){
	int i,j;
	// memset(qs, 0, sizeof qs);
	for(i=1;i<=r;i++){
		for(j=1;j<=c;j++){
			qs[i][j] = table[i][j] + qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1]; 
		}
	}
}

void rotate(int &r, int &c){
	int i,j;
	for(i=1;i<=c;i++){
		for(j=1;j<=r;j++){
			tmp[i][j] = table[r-j+1][i]; 
		}
	}
	swap(r,c);
	for(i=1;i<=r;i++){
		for(j=1;j<=c;j++){
			table[i][j] = tmp[i][j];
		}
	}
	gen_qs(r,c);
}

int play(int r, int c){
	int i,j,k;
	
	for(k=1;k<=r;k++){
		for(i=1;i<=r-k+1;i++){
			int ma = 0;
			for(j=1;j<=c;j++){
				dp[i][i+k-1][j] = max(qs[i+k-1][j]-qs[i-1][j]+ma, max(dp[i+1][i+k-1][j], dp[i][i+k-2][j]));
				dp[i][i+k-1][j] = max(dp[i][i+k-1][j], dp[i][i+k-1][j-1]);
				// if(k==2 && i==3 && j==2) printf("### %lld\n",dp[i][i+k-1][j]);
				ma = max(ma, -qs[i+k-1][j]+qs[i-1][j]);
			}
		}
	}

	int ans = -inf;

	for(k=1;k<=r;k++){
		for(i=1;i<=r-k+1;i++){
			int ma = 0;
			for(j=c;j>2;j--){
				int sum = qs[i+k-1][c]-qs[i+k-1][j-1]-qs[i-1][c]+qs[i-1][j-1];
				ans = max(ans, sum+ma+dp[i][i+k-1][j-2]);
				// if(k == 2 && i == 3 && j == 5) printf("*** %lld %lld %lld\n",sum,ma,dp[i][i+k-1][j-2]);
				ma = max(ma, -sum);
			}
		}
	}

	return ans;
}

int main(){
	int i,j,k,l,a,b,d;
	int r,c;
	scanf("%d%d",&r,&c);
	for(i=1;i<=r;i++){
		for(j=1;j<=c;j++){
			scanf("%lld",&table[i][j]);
		}
	}

	gen_qs(r,c);

	for(i=0;i<=301;i++){
		for(j=0;j<=301;j++){
			for(k=0;k<=301;k++){
				dp[i][j][k] = -inf;
			}
		}
	}

	int ans = -inf;
	for(i=0;i<4;i++){
		ans = max(ans, play(r, c));
		if(i<3) rotate(r, c);
		//printf("%lld\n",ans);
	}

	printf("%d", ans);
	return 0;
}
/*
6 6 
-1000 -1000 -1000 -1000 -1000 500 
-1000 -1000 -1000 -1000 -1000 -1000 
1 1 -1000 -1000 1 -1000 
1 1 -1000 -1000 1 -1000 
1 1 -1000 -1000 -1000 -1000 
-1000 -1000 -1000 -1000 -1000 -1000

6 6 
-1000 -1000 -1000 -1000 -1000 500 
-1000 1 1 1 -1000 -1000 
-1000 1 1 1 -1000 -1000 
-1000 -1000 -1000 -1000 -1000 -1000 
-1000 -1000 -1000 -1000 -1000 -1000
-1000 1 1 1 -1000 -1000

6 6
-1000 1 1 1 -1000 -1000
-1000 1 1 1 -1000 -1000
-1000 -1000 -1000 -1000 -1000 -1000
-1000 -1000 -1000 -1000 -1000 -1000
-1000 -1000 1 1 -1000 -1000
-1000 -1000 -1000 -1000 -1000 500
*/