#pragma GCC optimize("Ofast,unroll-loops")
#include <cstdio>
#include <vector>
#include <algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}

inline void write(int x){
    if(x>= 10){write(x/10);}
    putchar(x%10+'0');
}

signed main() {
    int N, S;
    while(N=read()){
        S=read();
        vector<int>dat(N);
        for(int i= 0;i<N;++i){dat[i]=read();}

        int Ls=0,sum=0;
        int res=N+1;

        for(int Rs=0;Rs<N;++Rs){
            sum+=dat[Rs];
            while(sum>=S){
                res=min(res,Rs-Ls+1);
                sum-=dat[Ls++];
            }
        }

        if(res>N){
            putchar('0');
        }else{
            write(res);
        }
        putchar('\n');
    }
    return 0;
}
