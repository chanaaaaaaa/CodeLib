#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#pragma GCC target("avx,popcnt")

#include <cstdio>
#include <vector>

using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//block
const int MAXN=2e5+10;

int fa[MAXN],dep[MAXN],to[MAXN],go[MAXN];
int N,cnt,u,v;
long long res,odd,sz;
vector<vector<int>>grid(MAXN,vector<int>());

//dfs
inline void dfs(int cur){
    to[cur]=++cnt;
    for(int nxt:grid[cur]){
        if(nxt==fa[cur]){continue;}
        fa[nxt]=cur;
        dep[nxt]=dep[cur]+1;
        dfs(nxt);
    }
    go[cur]=cnt;
    return;
}

signed main(){
    while(N=read()){
        cnt=0;res=0;odd=0;
        for(int i=1;i<=N;++i){grid[i].clear();}
        for(int i=1;i<N;++i){
            u=read();v=read();
            grid[u].emplace_back(v);
            grid[v].emplace_back(u);
        }
        fa[1]=0;dep[1]=0;
        dfs(1);

        for(int i=1;i<=N;++i){
            if(dep[i]&1){++odd;}
            if(i==1){continue;}
            sz=go[i]-to[i]+1;
            res+=sz*(N-sz);
        }
        res+=odd*(N-odd);
        write(res>>1);
        putchar('\n');
    }
    return 0;
}
