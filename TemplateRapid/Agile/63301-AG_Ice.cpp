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

const int MaxN = 1e5 + 10;
const int MaxM = 2e5 + 10;

void TESTCASE() {
    
}

const long long OddEven[] = {1, -1};

long long tree[2][MaxN]; // 0 = No Multiply, 1 = Multiply

int n, q;

long long a[MaxN];

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

void solve() {
    cin >> n >> q;
    long long val;
    for(int i = 1; i <= n; i++) {
        cin >> val;
        a[i] = val;
        upd(i, OddEven[i & 1] * val, 0);
        upd(i, OddEven[i & 1] * val * i, 1);
    }
    while(q--) {
        char opr;
        cin >> opr;
        if(opr == 'U') {
            int idx;
            long long val;
            cin >> idx >> val;
            upd(idx, OddEven[idx & 1] * (val - a[idx]), 0);
            upd(idx, OddEven[idx & 1] * (val - a[idx]) * idx, 1);
            a[idx] = val;
        }
        else {
            int l, r;
            cin >> l >> r;
            long long ans = query(r, 1) - query(l - 1, 1);
            long long qsNoMultiply = query(r, 0) - query(l - 1, 0);
            ans -= (l - 1) * qsNoMultiply;
            cout << OddEven[l & 1] * ans << "\n";
        }
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
5 4
1 3 9 8 2
Q 2 4
Q 5 5
U 2 10
Q 1 2

3 3
4 5 5
U 1 2
U 1 7
Q 1 2
*/