#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inilne")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
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

//#include<iostream>
#include<cstdio>
#include<vector>
#include<math.h>
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c>'9' || c<'0'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-blcok
signed main(){
    int N,M;
    while(N=read()){
        M=read();
        vector<vector<int>>grid(N,vector<int>(N,0x7fffffff));
        for(int i=0;i<M;++i){
            int s=read(),e=read(),w=read();
            grid[s][e]=grid[e][s]=min(grid[s][e],w);
        }
        for(int i=0;i<N;++i){
            grid[i][i]=0;
        }
        for(int k=0;k<N;++k){
            for(int i=0;i<N;++i){
                for(int j=0;j<N;++j){
                    grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
                }
            }
        }
        int maxx=0;
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                if(grid[i][j]!=0x7fffffff){
                    maxx=max(maxx,grid[i][j]);
                }
            }
        }
        int sp=min(read(),min(read(),read()));
        write(ceil(maxx*1.0/sp));
        putchar('\n');
    }
    return 0;
}
/*
2 1
0 1 150
60 50 75

3 2
1 0 100
1 2 80
60 80 50

4 5
0 1 200
0 2 200
0 3 200
2 1 200
2 3 200
50 100 100
*/
/*
3
4
8
*/
