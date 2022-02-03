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

const int MaxN = 3e5 + 10;
const int MaxM = 1e5 + 10;
const int MaxA = 26 + 10;

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;

int n;

struct FENWICK_TREE {
    long long tree[MaxN];
    void update(int idx, long long val) {
        for(; idx <= n; idx += idx & -idx) {
            tree[idx] += val;
        }
    }
    long long query(int idx, long long sum = 0) {
        for(; idx > 0; idx -= idx & -idx) {
            sum += tree[idx];
        }
        return sum;
    }
};

char a[MaxN], s[MaxM];
queue <int> qu[MaxA];

FENWICK_TREE fenwick;

void solve() {
    int opr;
    scanf("%d", &opr);
    scanf(" %s", a + 1);
    n = strlen(a + 1);
    for(int i = 1; i <= n; i++) {
        qu[a[i] - 'a'].push(i);
    }
    scanf(" %s", s + 1);
    int len = strlen(s + 1);
    long long ans = 0;
    for(int i = 1; i <= len; i++) {
        if(qu[s[i] - 'a'].empty()) {
            printf("-1\n");
            return ;
        }
        int idx = qu[s[i] - 'a'].front();
        ans += idx + fenwick.query(idx);
        if(opr) {
            fenwick.update(idx, -1);
        }
        qu[s[i] - 'a'].pop();
    }
    printf("%lld\n", ans);
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
0
aabceddectfghaat
catbat

1
aabceddectfghaat
catbat
*/