/*
    Author	: ~Aphrodicez
    School	: RYW
    Lang	: CPP
    Algo	: 
    Status	: 
*/

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

struct GRAPH {
    
};

const int MaxN = 2e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

long long tree[2][MaxN]; // 0 = Order, 1 = Value

int n, k;

void upd(int idx, long long val, int type) {
    while(idx <= n) {
        tree[type][idx] += val;
        idx += (idx & -idx);
    }
}

long long query(int idx, int type) {
    long long sum = 0;
    while(idx > 0) {
        sum += tree[type][idx];
        idx -= (idx & -idx);
    }
    return sum;
}

long long sum = 0;

long long a[MaxN], sorted[MaxN], realVal[MaxN];

unordered_map <long long, long long> mp;

vector <long long> median;

int low_b(int lb, int rb, long long val) {
    while(lb < rb) {
        int midb = lb + (rb - lb) / 2;
        if(query(midb, 0) < val)
            lb = midb + 1;
        else
            rb = midb;
    }
    return lb;
}

void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sorted[i] = a[i];
    }
    sort(sorted + 1, sorted + n + 1);
    int cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(sorted[i] != sorted[i - 1]) {
            mp[sorted[i]] = ++cnt;
            realVal[cnt] = sorted[i];
        }
    }
    median.push_back(k / 2 + 1);
    if(k % 2 == 0)
        median.push_back(k / 2);

    for(int i = 1; i <= k - 1; i++) {
        upd(mp[a[i]], 1, 0);
        upd(mp[a[i]], a[i], 1);
    }
    for(int i = k; i <= n; i++) {
        if(i - k > 0) {
            upd(mp[a[i - k]], -1, 0);
            upd(mp[a[i - k]], -a[i - k], 1);
        }
        upd(mp[a[i]], 1, 0);
        upd(mp[a[i]], a[i], 1);
        long long mn = 1e18;
        for(long long x : median) {
            int idx = low_b(1, n, x);
            long long lef = (realVal[idx] * query(idx - 1, 0)) - query(idx - 1, 1);
            long long rig = query(n, 1) - query(idx, 1) - (realVal[idx] * (k - query(idx, 0)));
            mn = min(mn, lef + rig);
        }
        cout << mn << " ";
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
8 3
2 4 3 5 8 1 2 1
*/