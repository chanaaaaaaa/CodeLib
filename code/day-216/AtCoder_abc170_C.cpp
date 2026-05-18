#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <iostream>
#include <string>

using namespace std;

const int MAXN=510;
char mp[MAXN][MAXN],mv[MAXN];
int H,W,M;

inline bool dfs(int y,int x,int dep){
    if(mp[y][x]=='#' || x<0 || y<0 || y>=H || x>=W){
        return false;
    }

    if(dep==M){
        return true;
    }



    if(mv[dep]=='L'){
        return dfs(y,x-1,dep+1);
    }else if(mv[dep]=='R'){
        return dfs(y,x+1,dep+1);
    }else if(mv[dep]=='U'){
        return dfs(y-1,x,dep+1);
    }else if(mv[dep]=='D'){
        return dfs(y+1,x,dep+1);
    }
}

signed main(){
    cin>>H>>W>>M;

    cin>>mv;
    for(int i=0;i<H;++i){
        cin>>mp[i];
    }

    int res=0;
    for(int i=0;i<H;++i){
        for(int j=0;j<W;++j){
            if(mp[i][j]=='.' && dfs(i,j,0)){
                ++res;
            }
        }
    }
    cout<<res<<'\n';
    return 0;
}
