#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

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
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}


inline int fin(vector<int>&e,vector<pair<pair<int,int>,int>>&v,int x){
    return upper_bound(e.begin(),e.end(),v[x].first.first-1)-e.begin();
}

signed main(void){
    int N;
    while(N=read()){
        vector<pair<pair<int,int>,int>>dat(N);
        for(int i=0;i<N;i++){
            dat[i].first.first=read();
            dat[i].first.second=read();
            dat[i].second=read();
        }
        sort(dat.begin(),dat.end(),
             [](pair<pair<int,int>,int>&a,pair<pair<int,int>,int>&b){
                return a.first.second < b.first.second;
            });

        vector<int>bottom(N);
        vector<int>dp(N+1,0);
        for(int i=0;i<N;i++){bottom[i]=dat[i].first.second;}

        for(int i=1;i<=N;i++){
            dp[i]=max(dp[i-1],dp[fin(bottom,dat,i-1)]+dat[i-1].second);
        }
        write(dp[N]);
        putchar('\n');
    }
}
/*
4
2 4 4
3 6 6
6 8 2
5 7 3
*/
