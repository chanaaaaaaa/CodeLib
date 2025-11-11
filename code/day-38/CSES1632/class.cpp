#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
//#include<vector>
#include<set>
#include<algorithm>
//#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
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
    int N=read(),P=read(),cnt=0,a,b;
    multiset<pair<int,int>>dat;
    multiset<int>exe;
    while(N--){
        a=read(),b=read();
        dat.insert({b,a});
        if(P){--P;exe.insert(0);}
    }
    while(P--){exe.insert(0);}

    for(auto c:dat){
        auto pos=exe.upper_bound(c.second);
        if(pos==exe.cbegin()){
            continue;
        }
        exe.erase(--pos);
        exe.insert(c.first);
        cnt++;
    }

    write(cnt);
}
