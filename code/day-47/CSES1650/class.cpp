#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
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

//-block
int N,Q,a,b,
    dat[200010],
    tre[800040];

inline void build(int l,int r,int id){
    if(l==r){
        tre[id]=dat[l];
        return;
    }
    int m=(l+r)/2;
    build(l,m,id*2);
    build(m+1,r,id*2+1);

    tre[id]=tre[id*2]^tre[id*2+1];
    return;
}

inline int query(int l,int r,int ql,int qr,int id){
    if(l>r||ql>r||qr<l){return 0;}
    if(ql<=l&&qr>=r){return tre[id];}
    int m=(l+r)/2;
    return query(l,m,ql,qr,id*2)^query(m+1,r,ql,qr,id*2+1);
}

signed main(){
    N=read();Q=read();
    for(int i=1;i<=N;++i){
        dat[i]=read();
    }
    build(1,N,1);

    while(Q--){
        a=read(),b=read();
        write(query(1,N,a,b,1));
        putchar('\n');
    }
}

/*
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
*/
