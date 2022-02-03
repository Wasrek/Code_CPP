#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define SZ(a) (int)(a).size()
#define pc(x) putchar(x)
#define MP make_pair
#define dec(x) fixed << setprecision(x)
#define v(a) vector <a>
#define p(a, b) pair <a, b>
#define heap(a) priority_queue <a>

using i64 = long long;

void setIO();

const int d4i[] = {-1, 0, 1, 0};
const int d4j[] = {0, 1, 0, -1};
const int d8i[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int d8j[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct EVENT {
    int i, jl, jr, idx, type;
    bool operator < (const EVENT &o) const {
        if(i != o.i)
            return i < o.i;
        return type < o.type;
    }
};

const int MaxN = 1e5;
const int MaxM = 1e4;

int tree[MaxN + 10];

void upd(int idx, int val) {
    while(idx <= MaxN) {
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

int query(int idx) {
    int sum = 0;
    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }
    return sum;
}

void TESTCASE() {
    
}

vector <EVENT> sweepLine;

int ans[MaxN];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int il, ir, jl, jr;
    for(int it = 1; it <= n; it++) {
        cin >> il >> jl >> ir >> jr;
        il++, ir++, jl++, jr++;
        sweepLine.push_back({il, jl, jr, 0, 1});
        sweepLine.push_back({ir + 1, jl, jr, 0, -1});
    }
    for(int it = 1; it <= m; it++) {
        cin >> il >> jl;
        il++, jl++;
        sweepLine.push_back({il, jl, 0, it, 3});
    }
    sort(sweepLine.begin(), sweepLine.end());
    for(auto x : sweepLine) {
        if(x.type == 3) {
            ans[x.idx] = query(x.jl);
            continue;
        }
        upd(x.jl, x.type);
        upd(x.jr + 1, -1 * x.type);
    }
    for(int it = 1; it <= m; it++) {
        cout << ans[it] << "\n";
    }
}

int main() {
    setIO();
    int q = 1;
    
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
10 3 3
3 0 8 2
1 7 8 9
1 0 8 2
5 2 6 4
5 1 5 4
7 3 7 9
0 0 0 3
6 2 6 4
8 3 9 8
4 4 8 6
7 9
8 5
6 4
*/