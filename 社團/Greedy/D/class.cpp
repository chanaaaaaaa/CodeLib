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
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(void){
    int N=read(),now=0,cnt=0;
    vector<pair<int,int>>mp;
    for(int i=0;i<N;i++){
        mp.push_back({read(),read()});
    }
    sort(mp.begin(),mp.end());
    for(auto &[t,d]:mp){
        if(now+t<=d){
            now+=t;
            cnt++;
        }
    }
    write(cnt);
}
