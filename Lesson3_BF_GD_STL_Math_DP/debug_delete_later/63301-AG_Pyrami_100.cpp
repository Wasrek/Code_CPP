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

const int MaxN = 1e5 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

struct MATRIX {
    long long a[2][2];
};

MATRIX a1 = {{{0, 3}, {1, 2}}};

MATRIX operator*(const MATRIX &a, const MATRIX &b) {
    MATRIX tmp;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            tmp.a[i][j] = 0;
            for(int k = 0; k < 2; k++) {
                tmp.a[i][j] += ((a.a[i][k] % MOD) * (b.a[k][j]) % MOD) % MOD;
                tmp.a[i][j] %= MOD;
            }
        }
    }
    return tmp;
}

MATRIX divide(long long b) {
    if(b == 1)
        return a1;
    MATRIX tmp = divide(b / 2);
    if(b % 2)
        return tmp * tmp * a1;
    return tmp * tmp;
}

MATRIX dp[30];

void solve() {
    dp[0] = a1;
    for(int i = 1; i < 30; i++) {
        dp[i] = dp[i - 1] * dp[i - 1];
    }
    int q;
    scanf("%d", &q);
    while (q--) {
        long long n;
        scanf("%lld", &n);
        MATRIX ans = {{{1, 0}, {0, 0}}};
        for(int j = 0; j <= 30; j++) {
            if(n & (1ll << j)) {
                ans = ans * dp[j];
            }
        }
        printf("%lld\n", ans.a[0][0]);
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
2
2
3
*/