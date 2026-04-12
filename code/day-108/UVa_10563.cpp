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
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<string>grid;
inline char minC(int m,int i,int j){
    for(char c='A';c<='Z';++c){
        bool v=true;
        if(i>0 && grid[i-1][j]==c){v=false;}
        if(j>0 && grid[i][j-1]==c){v=false;}
        if(j+1<m && grid[i][j+1]==c){v=false;}

        if(v){return c;}
    }
    return 'A';
}
inline bool moreSquare(int n,int m,int i,int j,int sz,char c){
    if(i+sz>=n || j+sz>=m){return false;}

    for(int ii=i;ii<=i+sz;++ii){
        if(grid[ii][j+sz]!='?'){return false;}
    }
    for(int jj=j;jj<=j+sz;++jj){
        if(grid[i+sz][jj]!='?'){return false;}
    }

    if(j+sz+1<m){
        for(int ii=i;ii<=i+sz;++ii){
            if(grid[ii][j+sz+1]==c){return false;}
        }
    }
    if(i>0){
        for(int jj=j;jj<=j+sz;++jj){
            if(grid[i-1][jj]==c){return false;}
        }
    }
    return true;
}
inline void editSquare(int i,int j,int sz,char c){
    for(int ii=i;ii<=i+sz;++ii){
        grid[ii][j+sz]=c;
    }
    for(int jj=j;jj<=j+sz;++jj){
        grid[i+sz][jj]=c;
    }
    return;
}
inline void solve(int n,int m){
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(grid[i][j]=='?'){
                char baseC=minC(m,i,j);
                grid[i][j]=baseC;

                int nowsz=0;
                while(true){
                    if(j+nowsz+1>m || grid[i][j+nowsz+1]=='.'){
                        break;
                    }

                    char extC=minC(m,i,j+nowsz+1);
                    if(extC<baseC){
                        break;
                    }

                    if(moreSquare(n,m,i,j,nowsz+1,baseC)){
                        ++nowsz;
                        editSquare(i,j,nowsz,baseC);
                    }else{
                        break;
                    }
                }
            }
        }
    }
    return;
}

signed main(){
    int n,m;
    bool f=false;
    while(cin>>n>>m && n+m){
        grid.assign(n,"");
        for(int i=0;i<n;++i){
            cin>>grid[i];
        }
        //alg
        solve(n,m);

        if(f){
            cout<<'\n';
        }else{f=true;}
        for(int i=0;i<n;++i){
            cout<<grid[i]<<'\n';
        }
    }
    return 0;
}
