#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<climits>
#include<vector>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
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
    int N=read(),maxx;
    vector<int>dat(N);

    maxx=dat[0]=read();
    for(int i=1;i<N;++i){
        int tmp=read();

        if(dat[i-1]<=0){
            dat[i]=tmp;
        }else{dat[i]+=dat[i-1]+tmp;}

        maxx=max(maxx,dat[i]);
    }
    write(maxx);
    putchar('\n');
    return 0;
}
