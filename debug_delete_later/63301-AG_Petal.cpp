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

const int MaxN = 15e2 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct MEDIAN {
    priority_queue <long long> lpq;
    priority_queue <long long, vector <long long>, greater <long long>> rpq;
    long long suml = 0, sumr = 0;
    void push(long long val) {
        suml += val, lpq.push(val);
        sumr += lpq.top(), rpq.push(lpq.top());
        suml -= lpq.top(), lpq.pop();
        suml += rpq.top(), lpq.push(rpq.top());
        sumr -= rpq.top(), rpq.pop();
        if(lpq.size() - rpq.size() > 1) {
            sumr += lpq.top(), rpq.push(lpq.top());
            suml -= lpq.top(), lpq.pop();
        }
    }
    long long query() {
        return (lpq.top() * lpq.size() - suml) + (sumr - lpq.top() * rpq.size());
    }
    void clear() {
        while(!lpq.empty())
            lpq.pop();
        while(!rpq.empty())
            rpq.pop();
        suml = 0;
        sumr = 0;
    }
};

long long a[MaxN], med[MaxN][MaxN], dp[60][MaxN];

MEDIAN find_med;

void solve() {
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int l = 1; l <= n; l++) {
        find_med.clear();
        for(int r = l; r <= n; r++) {
            find_med.push(a[r]);
            med[l][r] = find_med.query();
        }
    }
    for(int k = 0; k <= 50; k++) {
        for(int r = 1; r <= n; r++) {
            dp[k][r] = 1e18;
        }
    }
    dp[0][0] = 0;
    for(int k = 1; k <= 50; k++) {
        for(int r = 1; r <= n; r++) {
            for(int l = 1; l <= r; l++) {
                dp[k][r] = min(dp[k][r], dp[k - 1][l - 1] + med[l][r]);
            }
        }
    }
    while(q--) {
        int k;
        scanf("%d", &k);
        printf("%lld\n", dp[k][n]);
    }
}

int main() {
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
7 1
6 4 6 12 13 9 7
3
*/