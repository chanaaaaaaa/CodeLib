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
#include <queue>
#include <utility>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();

        if(c=='.'){return 0;}
        if(c=='#'){return 1;}
        if(c=='S'){return 2;}
        if(c=='E'){return 3;}

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
bool junc[300][300];
int vis[300][300][3];
int d[4][2]={
    {1,0},
    {0,1},
    {-1,0},
    {0,-1},
};
int N,M,sx,sy,ex,ey,dir;
inline bool check(int x,int y,int f,int step){
    int tmp=1;
    //
    //printf("x: %2d, y: %2d,f : %d, step: %2d\n",x,y,f,step);
    //
    while(tmp<=step+1){
        if(x+d[f][0]*tmp<0 || x+d[f][0]*tmp >=N){return false;}
        if(y+d[f][1]*tmp<0 || y+d[f][1]*tmp >=M){return false;}

        if(junc[x+d[f][0]*tmp][y+d[f][1]*tmp]){return false;}

        ++tmp;
    }

    if(vis[x+d[f][0]*(step+1)][y+d[f][1]*(step+1)][step]!=0){return false;}
    //
    //printf("succeed\n");
    //
    return true;
}

inline int solve(){
    queue<pair<pair<int,int>,int>>Q;
    vis[sx][sy][2]=1;
    Q.push({{sx,sy},2});

    while(!Q.empty()){
        int nx=Q.front().first.first,
            ny=Q.front().first.second,
            ns=Q.front().second;
            Q.pop();
        for(int f=0;f<4;++f){
            if(check(nx,ny,f,(ns+1)%3)){
                if(ex==nx+d[f][0]*((ns+1)%3+1) && ey==ny+d[f][1]*((ns+1)%3+1)){return vis[nx][ny][ns];}

                vis[nx+d[f][0]*((ns+1)%3+1)][ny+d[f][1]*((ns+1)%3+1)][(ns+1)%3]=vis[nx][ny][ns]+1;
                Q.push({{nx+d[f][0]*((ns+1)%3+1),ny+d[f][1]*((ns+1)%3+1)},(ns+1)%3});
            }
        }
    }
    return -1;
}
signed main(){
    int T=read();
    while(T--){
        N=read(),M=read();
        memset(vis,0,sizeof(vis));

        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                dir=read();
                if(dir==1){
                    junc[i][j]=true;
                }else{
                    junc[i][j]=false;
                    if(dir==2){
                        sx=i;sy=j;
                    }else if(dir==3){
                        ex=i;ey=j;
                    }
                }
            }
        }
        //
        int res=solve();
        if(res==-1){
            printf("NO\n");
        }else{
            write(res);
            putchar('\n');
        }
    }
    return 0;
}
