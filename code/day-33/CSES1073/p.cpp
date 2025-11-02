//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
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
//-block

signed main(){
    int N=read()-1,tmp;
    vector<int>lib;
    lib.emplace_back(read());
    while(N--){
        tmp=read();
        auto it=upper_bound(lib.begin(),lib.end(),tmp);

        if(it==lib.end()){lib.emplace_back(tmp);}
        else{*it=tmp;}
    }

    write(lib.size());
    return 0;
}
