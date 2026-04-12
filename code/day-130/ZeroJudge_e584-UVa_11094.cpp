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
using namespace std;
//-block
int d[2][4]={
    {1,-1,0,0},
    {0,0,1,-1}
};
int N,M,X,Y;
char mp[20][20],target;

inline int dfs(int nowy,int nowx){
    int tmp=1;

    for(int f=0;f<4;++f){
        if(nowy+d[0][f]<0 || nowy+d[0][f]>=N){continue;}
        if(nowx+d[1][f]>=M){
            if(mp[nowy+d[0][f]][nowx+d[1][f]-M]==target){
               mp[nowy+d[0][f]][nowx+d[1][f]-M]=' ';
               tmp+=dfs(nowy+d[0][f],nowx+d[1][f]-M);
            }
        }else if(nowx+d[1][f]<0){
            if(mp[nowy+d[0][f]][nowx+d[1][f]+M]==target){
               mp[nowy+d[0][f]][nowx+d[1][f]+M]=' ';
               tmp+=dfs(nowy+d[0][f],nowx+d[1][f]+M);
            }
        }else{
            if(mp[nowy+d[0][f]][nowx+d[1][f]]==target){
               mp[nowy+d[0][f]][nowx+d[1][f]]=' ';
               tmp+=dfs(nowy+d[0][f],nowx+d[1][f]);
            }
        }
    }
    return tmp;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    while(cin>>N>>M && (N&&M)){
        for(int i=0;i<N;++i){//Y
            for(int j=0;j<M;++j){//X
                cin>>mp[i][j];
            }
        }
        cin>>Y>>X;
        target=mp[Y][X];
        mp[Y][X]=' ';
        dfs(Y,X);

        int maxx=0;
        for(int i=0;i<N;++i){//Y
            for(int j=0;j<M;++j){//X
                if(mp[i][j]==target){
                    mp[i][j]=' ';
                    maxx=max(maxx,dfs(i,j));
                }
            }
        }
        cout<<maxx<<'\n';
    }
    return 0;
}
