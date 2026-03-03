#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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

#include <cstdio>
#include <memory.h>

#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='N'){return 0;}
        if(c=='E'){return 1;}
        if(c=='S'){return 2;}
        if(c=='W'){return 3;}

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
    return;
}
//-block

const int MAXN=35;
int mp[MAXN][MAXN];
bool junc[MAXN][MAXN][5];

signed main(){
    int T=read();
    while(T--){
        memset(mp,0,sizeof(mp));
        memset(junc,0,sizeof(junc));

        int N=read(),
            sx=read(),sy=read(),
            ex=read(),ey=read();

        int D=read();
        while(D--){
            int x=read(),y=read(),f=read();
            //0-N,1-E,2-S,3-W
            if(f==0){
                junc[x][y][1]=true;
                junc[x][y+1][3]=true;
            }else if(f==1){
                junc[x][y][4]=true;
                junc[x+1][y][2]=true;
            }else if(f==2){
                junc[x][y][3]=true;
                junc[x][y-1][1]=true;
            }else if(f==3){
                junc[x][y][2]=true;
                junc[x-1][y][4]=true;
            }
        }


        mp[sx][sy]=1;
        for(int i=sx;i<=ex;++i){
            for(int j=sy;j<=ey;++j){
                if(i==sx && j==sy){continue;}
                if(i>0 && !junc[i][j][2]){mp[i][j]+=mp[i-1][j];}
                if(j>0 && !junc[i][j][3]){mp[i][j]+=mp[i][j-1];}
            }
        }
        write(mp[ex][ey]);
        putchar('\n');
    }
    return 0;
}
