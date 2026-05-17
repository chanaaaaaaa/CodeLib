#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <iostream>

#define int long long
using namespace std;

//-block
const int MAXM=1010,MAXH=12;
int a[MAXH],pfs[MAXH][MAXM];
int H,W,K,res=200000;

inline bool judge(int cnt,int las,int j){
    int num;
    a[cnt+1]=H;
    for(int i=1;i<=cnt+1;++i){
        num=pfs[a[i]][j]-pfs[a[i]][las]-pfs[a[i-1]][j]+pfs[a[i-1]][las];
        if(num>K){return true;}
    }
    return false;
}

inline void dfs(int dep,int cnt){
    if(dep==H){
        int tot=cnt,las=0;
        for(int j=1;j<=W;++j){
            if(judge(cnt,las,j)){
                ++tot;las=j-1;
            }
        }
        if(!judge(cnt,W-1,W)){res=min(res,tot);}
        return;
    }

    dfs(dep+1,cnt);
    a[cnt+1]=dep;
    dfs(dep+1,cnt+1);
}

signed main(){
    cin>>H>>W>>K;
    for(int i=1;i<=H;++i){
        string S;
        cin>>S;
        for(int j=1;j<=W;++j){
            pfs[i][j]=pfs[i-1][j]+pfs[i][j-1]-pfs[i-1][j-1]+S[j-1]-'0';
        }
    }
    dfs(1,0);
    cout<<res<<'\n';

    return 0;
}
