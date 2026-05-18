#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
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
//-block
inline bool cmp(pair<int,int>&a, pair<int,int>&b){
    return a.first < b.first;
}
signed main(){
    int N=read(),M=read();
    vector<vector<int>>adjL(N+1,vector<int>());
    vector<int>weight(N+1);
    vector<int>cnt(N+1);
    vector<pair<int,int>>task(N);

    for(int i=0;i<M;++i){
        int u=read(),v=read();
        adjL[u].emplace_back(v);
        adjL[v].emplace_back(u);
    }
    for(int i=0;i<N;++i){
        weight[i+1]=task[i].first=read();
        task[i].second=i+1;
    }
    for(int i=0;i<N;++i){
        cnt[i+1]=read();
    }

    sort(task.begin(),task.end(),cmp);

    vector<int>f(N+1,0);
    int res=0;
    for(pair<int,int> &p:task){
        int u=p.second;
        int w=p.first;

        vector<int>dp(w,0);
        for(int v:adjL[u]){
            int wv=weight[v];
            if(wv<w){
                for(int dw=w-1;dw>=wv;--dw){
                    if(dp[dw-wv]+f[v]>dp[dw]){
                        dp[dw]=dp[dw-wv]+f[v];
                    }
                }
            }
        }
        f[u]=dp[w-1]+1;
        res+=f[u]*cnt[u];
    }
    write(res);
    putchar('\n');
    return 0;
}

