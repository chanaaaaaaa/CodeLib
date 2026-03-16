/*#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-ferun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-function-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
/* Pragma GCC

#define IO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define MEM(_A, _V) memset(_A, _V, sizeof(_A))
#define ALL(_A) _A.begin(), _A.end()
#define LB(_A, _V) lower_bound(ALL(_A), _V)
#define UB(_A, _V) upper_bound(ALL(_A), _V)
#define as(_A, _V) assign(_A, _V)
#define pii pair<int, int>
#define sz size()
#define cr clear()
#define rz resize
#define pb push_back
//#define pb emplace_back
#define F first
#define S second
#define LL long long
#define ULL unsigned long long
/* Self define

const int  d[4][2] = {{1, 0}, {0, 1},  {-1, 0}, {0, -1}};
//const int     MAXN = 1e7 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const LL     LLINF = 0x7FFFFFFFFFFFFFFF;
const LL  MEMLLINF = 0x3F3F3F3F3F3F3F3F;
/* Self Define Const */
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

inline int read(){
    int x=0,w=1;
    int c;
    while((c=getchar())<'0' || c>'9'){
        if(c==-1){return 0;}
        if(c=='-'){w=-1;}
    }
    do{x=(x<<3)+(x<<1)+c-'0';}while((c=getchar())>='0' && c<='9');
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
/* I/O Optimize */
const int MAXN=1e6+5;
vector<int> v,adjL[MAXN];
bool vis[MAXN];
int v1[MAXN];
int N,M,a,b;
inline void dfs(int cur){
    if(vis[cur]){return;}
    vis[cur]=true;
    for(int &nex:adjL[cur]){
        dfs(nex);
    }
    v.push_back(cur);
}
inline bool cycle(int cur){
    v1[cur]=1;
    for(int &i:adjL[cur]){
        if(!v1[i]){
            if(cycle(i)){return true;}
        }else if(v1[i]==1){
            return true;
        }
    }
    v1[cur]=2;
    return false;
}
inline void solve(){
    N=read(),M=read();
    for(int i=0;i<M;++i){
        a=read(), b=read();
        adjL[a].push_back(b);
    }
    for(int i=1;i<N+1;++i){
        if(!v1[i] && cycle(i)){
            printf("IMPOSSIBLE\n");
            return;
        }
        if(!vis[i]){
            dfs(i);
        }
    }
    bool first=true;
    for(vector<int>::reverse_iterator it=v.rbegin();it!=v.rend();++it){
        if(!first) putchar(' ');
        first=false;
        write(*it);
    }
}

/* Programing area*/
signed main(){
    solve();
    putchar('\n');
    return 0;
}
