#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inilne")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
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
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>
#include<queue>

#define MAXN 200010
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
int N,maxx,
    d[2][4]={{0,0,1,-1},
            {1,-1,0,0}}
    ;
vector<vector<int>>mp;
vector<pair<int,int>>record1;
inline int read_C(){
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    return c-'0';
}
inline int bfs(int i,int j){
    vector<vector<int>>vis(N,vector<int>(N,0));

    queue<pair<int,int>>Q;
    Q.push({i,j});
    vis[i][j]=1;
    while(!Q.empty()){
        int y=Q.front().first,
            x=Q.front().second;
        Q.pop();

        for(int i=0;i<4;++i){
            int uy=y+d[0][i],
                ux=x+d[1][i];
            if(uy>=0 && uy<N && ux>=0 && ux<N){
                if(mp[uy][ux]==3){
                    return vis[y][x];
                }
                if(!vis[uy][ux]){
                    vis[uy][ux]=vis[y][x]+1;
                    Q.push({uy,ux});
                }
            }
        }
    }
}
//
signed main(){
    while(N=read()){
        mp.clear();
        record1.clear();
        mp.assign(N,vector<int>(N,0));

        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                mp[i][j]=read_C();
                if(mp[i][j]==1){
                    record1.push_back({i,j});
                }
            }
        }
        maxx=0;
        for(auto &[x,y]:record1){
            maxx=max(maxx,bfs(x,y));
        }
        write(maxx);
        putchar('\n');
    }
    return 0;
}
