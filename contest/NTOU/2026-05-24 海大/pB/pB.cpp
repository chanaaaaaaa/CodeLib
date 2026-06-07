#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <bits/stdc++.h>
using namespace std;

inline long long read() {
    long long x = 0;
    int c = 0;
    while (c < '0' || c > '9') {
        c = getchar();
        if (c == -1) return 0;
    }
    while (c >= '0' && c <= '9') {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return x;
}

const int MAXN = 200005;
const int LOG = 31;

int n, q;
long long w[MAXN];
int nxt[MAXN << 1][LOG];
int pos[MAXN << 1][LOG];

inline int enc(int x, int d) {
    return (x - 1) << 1 | (d == 1 ? 0 : 1);
}

inline int move_cw(int x) {
    return (int)((x - 1 + w[x]) % n + 1);
}

inline int move_ccw(int x) {
    return (int)((x - 1 - w[x] % n + n) % n + 1);
}

void build() {
    int tot = n << 1;
    for (int x = 1; x <= n; ++x) {
        for (int d = 1; d <= 2; ++d) {
            int s = enc(x, d);
            int nx = (d == 1 ? move_cw(x) : move_ccw(x));
            nxt[s][0] = enc(nx, 3 - d);
            pos[s][0] = nx;
        }
    }
    for (int j = 1; j < LOG; ++j) {
        for (int s = 0; s < tot; ++s) {
            int mid = nxt[s][j - 1];
            nxt[s][j] = nxt[mid][j - 1];
            pos[s][j] = pos[mid][j - 1];
        }
    }
}

inline int query(int p, int dir, long long k) {
    int cur = enc(p, dir);
    int ans = p;
    for (int j = 0; j < LOG; ++j) {
        if(k>>j&1){
            ans=pos[cur][j];
            cur=nxt[cur][j];
        }
    }
    return ans;
}

signed main() {
    n=(int)read();
    q=(int)read();
    for(int i=1;i<=n;++i){w[i]=read();}

    build();

    while(q--){
        int p=(int)read();
        int dir=(int)read();
        long long k=read();
        printf("%d\n", query(p, dir, k));
    }
    return 0;
}
