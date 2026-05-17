#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <cstdio>
#include <utility>
#include <vector>
#include <algorithm>

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
const int MAXM=3e5;
signed main(){
    int N=read();
    vector<pair<int,int>>dat;
    for(int i=0;i<N;++i){
        int a=read(),b=read();
        int x=a+b,y=MAXM-a+b;
        dat.push_back({x,-y});
    }
    sort(dat.begin(),dat.end());

    vector<int>dp(N,MAXM*2+5);
    int res=0;
    for(pair<int,int> &p:dat){
        int b=-p.second;
        int t=lower_bound(dp.begin(),dp.end(),b)-dp.begin();
        dp[t]=b;
        res=max(res,t+1);
    }
    write(res);
    putchar('\n');
    return 0;
}