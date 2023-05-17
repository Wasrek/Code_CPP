/*
    TASK:
    LANG: CPP
    AUTHOR: WasreK
    ALGO: 
    TYPE: BATCH
    SCORE: 
*/
#include <bits/stdc++.h>
using namespace std;
const int X = 1e6 + 5;
int N[2], L, Q, cur[X], st[2][X];
bool fl[X];
void ud(bool ty, int po, int va){ for(++po; po <= L; po += -po & po) st[ty][po] += va; }
int gt(bool ty, int po, int ret = 0){ for(++po; po; po -= -po & po) ret += st[ty][po]; return ret;}
long long sum;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> N[0] >> L >> Q;
	ud(0, 0, N[0]); 
	for(int z = 0, u, v, nw; z < Q; ++z){
		string ty; cin >> ty >> u;
		if(ty[0] == 's'){
			cin >> v;
			nw = (cur[u] + L + v) % L;
			ud(fl[u], cur[u], -1);
			ud(fl[u], nw, 1);
			for(int i=0;i<=L;i++){
				cout<<gt(0,i)<<" ";
			}
			cout<<endl;
			cout<< cur[u]<< nw<<endl;
			sum += (fl[u]? -1 : 1) * (nw - cur[u]), cur[u] = nw;
		} else if(ty[0] == 'f'){
			ud(fl[u], cur[u], -1), --N[fl[u]];
			sum += (fl[u]? 2 : -2) * cur[u]; 
			fl[u] ^= 1; 
			ud(fl[u], cur[u], 1), ++N[fl[u]];
		} else{
			printf("f0: %d f1: %d sum: %d\n",gt(0, max(u - 1, 0)),gt(1,u),sum);
			for(int i=0;i<=L;i++){
				cout<<gt(0,i)<<" ";
			}
			cout<<endl;
			for(int i=0;i<=L;i++){
				cout<<gt(1,i)<<" ";
			}
			cout<<endl;
			printf("%d * ( %d - %d + %d ) + ( %d * ( %d - %d )) - %d\n",L,N[0],gt(0, max(u - 1, 0)),gt(1, u),u,N[0],N[1],sum);
			cout << 
			1ll * L * (N[0] - gt(0, max(u - 1, 0)) + gt(1, u)) + 
			(1ll * u * (N[0] - N[1]))
			- sum << '\n';
		}
	}
}