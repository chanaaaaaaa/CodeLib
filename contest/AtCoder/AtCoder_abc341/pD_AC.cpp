#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <bits/stdc++.h>

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
signed main(){
    int N=read();
    int M=read();
    int K=read();

    int G=(N/__gcd(N,M))*M;

    int Ls=1,Rs=2e18;
    while(Ls<Rs){
        int mid=(Ls+Rs)>>1;
        int cnt=(mid/N)+(mid/M)-2*(mid/G);

        if(cnt>=K){
            Rs=mid;
        }else{
            Ls=mid+1;
        }
    }
    write(Ls);
    putchar('\n');
    return 0;
}

