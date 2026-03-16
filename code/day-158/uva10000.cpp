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
Pragma GCC

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
Self define

const int  d[4][2] = {{1, 0}, {0, 1},  {-1, 0}, {0, -1}};
const int     MAXN = 1e7 + 50;
const int      Mod = 1e9 + 7;
const int      INF = 0x7FFFFFFF;
const LL     LLINF = 0x7FFFFFFFFFFFFFFF;
const LL  MEMLLINF = 0x3F3F3F3F3F3F3F3F;
Self Define Const */
#include <cstdio>
#include <cstdlib>

#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
        if(c=='-'){w=-1;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
/* I/O Optimize */
const int MAXN=500;
struct edge{
    int v,w;
};

vector<edge> e[MAXN];
int dis[MAXN], cnt[MAXN], vis[MAXN];
queue<int>Q;

inline bool spfa(int n,int s){
    memset(dis,0x3f,sizeof(dis));  // 初始化所有距離為無限大
    memset(cnt,0,sizeof(cnt));      // 初始化鬆弛次數（用於負環檢測）
    memset(vis,0,sizeof(vis));     // 初始化是否在佇列中
    dis[s]=0; vis[s]=1;
    while(!Q.empty()) Q.pop();     // 清空佇列（重要！可能有多組測資）
    Q.push(s);
    while(!Q.empty()){             // 【修正】!Q.empty() 才對！當佇列「不為空」時繼續
        int u=Q.front();
        Q.pop();
        vis[u]=0;                  // u 離開佇列，標記為不在佇列中
        for(auto &ed:e[u]){
            int v=ed.v, w=ed.w;
            if(dis[v]>dis[u]+w){   // 鬆弛：發現更短的路徑
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=n){return false;}  // 經過 n 個點還有更新 → 負環
                if(!vis[v]){Q.push(v); vis[v]=1;}  // v 不在佇列中才加入
            }
        }
    }
    return true;
}

inline void solve(){
    int N,st;
    int Case=0;
    while(true){
        N=read();
        if(N==0){break;}
        st=read();
        for(int i=1;i<=N;i++) e[i].clear();  // 清空圖！每組測資要重置

        while(true){
            int a,b;
            a=read(); b=read();
            if(a==0 && b==0){break;}
            e[a].push_back({b,-1});  // 邊權 -1：最短路 = 最長路（取負）
        }
        spfa(N,st);

        // UVA 10000：找「距離最小」的點（最負 = 路徑最長），同長取編號小
        int ans_v=st, ans_len=0;
        for(int i=1;i<=N;i++){
            if(dis[i]<(int)0x3f3f3f3f &&  // 只考慮可到達的點
               (dis[i]<dis[ans_v] || (dis[i]==dis[ans_v] && i<ans_v))){
                ans_v=i;
            }
        }
        ans_len = -dis[ans_v];  // 邊權 -1，所以路徑長 = -距離

        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n",
               ++Case, st, ans_len, ans_v);
    }
}

/* Programing area*/
signed main(){
    solve();
    //system("pause");
    return 0;
}
