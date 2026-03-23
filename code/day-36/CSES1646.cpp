#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
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

signed main(){
    int N,M,a,b;
    while(N=read()){
        M=read();
        vector<int>dat;
        dat.push_back(0);
        while(N--){
            dat.push_back(read());
        }
        for(int i=1;i<dat.size();i++){
            dat[i]+=dat[i-1];
        }
        while(M--){
            a=read();
            b=read();
            write(dat[b]-dat[a-1]);
            putchar('\n');
        }
    }
    return 0;
}
