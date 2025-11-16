#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<climits>
#include<vector>

#define MAXN 10000
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='W'){return 1;}
        if(c=='E'){return -1;}
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
//-block

signed main(){
    int N;
    while(N=read()){
        vector<int>lib(N+2,0);
        vector<int>fro(N+2,0);
        vector<int>bac(N+2,0);
        for(int i=1;i<=N;++i){
            lib[i]=read();
        }
        for(int i=1;i<=N;++i){
            if(lib[i]==1){fro[i]=fro[i-1]+1;}
            else{fro[i]=fro[i-1];}
        }
        for(int i=N;i>=1;--i){
            if(lib[i]==-1){bac[i]=bac[i+1]+1;}
            else{bac[i]=bac[i+1];}
        }

        int res=INT_MAX;
        for(int i=1;i<=N;++i){
            res=min(res,fro[i]+bac[i]-1);
        }
        write(res);
        putchar('\n');
    }
    return 0;
}
