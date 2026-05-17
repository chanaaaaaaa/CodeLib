#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
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

const int MAXN=1e6+10;
int dat[MAXN],cnt[MAXN];
signed main(){
    int N=read();
    for(int i=0;i<N;++i){
        dat[i]=read();
    }
    sort(dat,dat+N);
    for(int i=0;i<N;++i){
        for(int j=dat[i];j<=dat[N-1];j+=dat[i]){
            ++cnt[j];
        }
    }
    int res=0;
    for(int i=0;i<N;++i){
        if(cnt[dat[i]]==1){++res;}
    }
    write(res);
    putchar('\n');
    return 0;
}
