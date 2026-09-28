#include <cstdio>
#include <vector>
#include <random>
#include <chrono>

using namespace std;

typedef unsigned long long ull;

inline ull read(){
    ull x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
//block
const int MAXN=2e5+5;
ull N,Q,x,L,R,l,r;
ull wgt[MAXN],pA[MAXN],pB[MAXN];
signed main(){
    mt19937_64 rndnum(0);

    N=read();Q=read();

    for(int i=1;i<=N;++i){
        wgt[i]=rndnum();
    }

    for(int i=1;i<=N;++i){
        x=read();
        pA[i]=pA[i-1]+wgt[x];
    }

    for(int i=1;i<=N;++i){
        x=read();
        pB[i]=pB[i-1]+wgt[x];
    }

    while(Q--){
        L=read();R=read();
        l=read();r=read();

        if(R-L==r-l && pA[R]-pA[L-1]==pB[r]-pB[l-1]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

    return 0;
}
