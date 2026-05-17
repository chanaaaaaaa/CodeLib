#pragma GCC optimize("Ofast,fast-math,unroll-loops,no-stack-protector")
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
//-block
vector<vector<int>>dat;
signed main(){
    int N=read();
    dat.assign(N,vector<int>());
    for(int i=0;i<N;++i){
        int M=read();
        dat[i].assign(M,0);
        for(int j=0;j<M;++j){
            dat[i][j]=read();
        }
    }
    int a=read();
    int b=read();
    write(dat[a-1][b-1]);
    putchar('\n');
    return 0;
}
