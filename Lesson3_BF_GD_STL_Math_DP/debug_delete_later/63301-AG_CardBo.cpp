/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
*/

#include <bits/stdc++.h>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pc(x) putchar(x)
#define dec(x) fixed << setprecision(x)

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

const int MaxN = 1e3 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct MST {
    int u, v;
    long long w;
    bool operator < (const MST &o) const {
        return w > o.w;
    }  
};

long long r[MaxN], g[MaxN];
int parent[MaxN];
priority_queue <MST> pq;

int find_root(int u) {
    if(parent[u] == u)
        return u;
    return parent[u] = find_root(parent[u]);
}

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        parent[i] = i;
        scanf("%lld", &r[i]);
    }
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &g[i]);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            pq.push({i, j, min(r[i] ^ g[j], g[i] ^ r[j])});
        }
    }
    long long ans = 0;
    while(!pq.empty()) {
        int u = pq.top().u;
        int v = pq.top().v;
        long long w = pq.top().w;
        pq.pop();
        int ru = find_root(u);
        int rv = find_root(v);
        if(ru == rv)
            continue;
        parent[ru] = rv;
        ans += w;
    }
    printf("%lld\n", ans);
}

int main() {
    int q = 1;
    scanf("%d", &q);
    for(int i = 1; i <= q; i++) {
        solve();
    }
    return 0;
}

void setIO() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*
2
2
1 2
3 3
3
1 101 501
3 2 3
*/