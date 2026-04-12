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
#include <utility>
#include <algorithm>
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
struct Edge{
    int u,v,w;
    Edge(int _u,int _v,int _w):u(_u),v(_v),w(_w){}
    Edge(){}
};
struct Node{
    int rk,fa;
};
vector<Edge>EdgeList;
vector<Node>NodeList;
vector<Edge>ResList;
int T,N,tmp;
inline bool cmp(Edge &a,Edge &b){
    if(a.w==b.w){
        if(a.u==b.u){
            return a.v < b.v;
        }else{
            return a.u < b.u;
        }
    }else{
        return a.w < b.w;
    }
}
inline int fd(int x){
    if(NodeList[x].fa==x){return x;}
    return NodeList[x].fa=fd(NodeList[x].fa);
}
inline void kruskal(){
    for(int i=0;i<N;++i){
        NodeList[i].rk=0;
        NodeList[i].fa=i;
    }

    for(Edge &e:EdgeList){
        int a=fd(e.u);
        int b=fd(e.v);
        if(a!=b){
            ResList.push_back({min(e.u,e.v),max(e.u,e.v),e.w});
        
            if(NodeList[a].rk > NodeList[b].rk){
                NodeList[b].fa=a;
            }else{
                NodeList[a].fa=b;
                if(NodeList[a].rk==NodeList[b].rk){
                    ++NodeList[b].rk;
                }
            }
        }
    }
    //sort(ResList.begin(),ResList.end(),cmp);
    for(Edge &e:ResList){
        putchar(e.u+'A');
        putchar('-');
        putchar(e.v+'A');
        putchar(' ');
        write(e.w);
        putchar('\n');
    }
}
inline void solve(){
    T=read();
    for(int cases=1;cases<=T;++cases){
        N=read();
        EdgeList.clear();
        NodeList.assign(N,Node());
        ResList.clear();

        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(tmp=read()){
                    EdgeList.push_back({i,j,tmp});
                }
            }
        }
        sort(EdgeList.begin(),EdgeList.end(),cmp);
        printf("Case %d:\n",cases);
        kruskal();
    }
    return;
}

/* Programing area*/
signed main(){
    solve();
    //system("pause");
    return 0;
}
