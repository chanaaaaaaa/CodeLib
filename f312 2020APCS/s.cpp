#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<algorithm>
using namespace std;

int a1,b1,c1,a2,b2,c2,n,maxx=0;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        if(c=='-') w=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){

    a1=read();
    b1=read();
    c1=read();
    a2=read();
    b2=read();
    c2=read();
    n=read();
    for(int x=0;x<=n;x++)maxx=max(maxx,((a1+a2)*x-a1*2*n+b2-b1)*x);
    write((a1*n+b1)*n+c1+c2+maxx);
    return 0;
}
