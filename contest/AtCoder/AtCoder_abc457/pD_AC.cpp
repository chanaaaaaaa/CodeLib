#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
#include <cstdio>
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
int N,K,Ls,Rs;
vector<int>dat;
inline bool check(int x){
    int ops=0;

    for(int i=0;i<N;++i){
        if(x<=dat[i]){continue;}

        ops+=(x-dat[i]+i)/(i+1);
        if(ops>K){return false;}
    }
    return true;
}

signed main(){
    N=read(),K=read();
    Ls=0,Rs=3e18;
    dat.assign(N,0);

    for(int i=0;i<N;++i){
        dat[i]=read();
    }

    while(Rs-Ls>1){
        int mid=(Ls+Rs)>>1;
        if(check(mid)){
            Ls=mid;
        }else{
            Rs=mid;
        }
    }

    write(Ls);
    putchar('\n');
    return 0;
}
