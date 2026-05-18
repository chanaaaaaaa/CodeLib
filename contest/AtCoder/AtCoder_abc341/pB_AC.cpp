#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <vector>

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

signed main(){
    int N=read();
    vector<int>dat(N);

    for(int i=0;i<N;++i){
        dat[i]=read();
    }
    for(int i=0;i<N-1;++i){
        int a=read();
        int b=read();
        dat[i+1]+=(dat[i]/a)*b;
    }
    write(dat[N-1]);
    putchar('\n');
    return 0;
}

