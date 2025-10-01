#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<cstdio>
#include<memory.h>

#define N 100001
using namespace std;

int bit[N]={0};

void add(int x, int v){
    for(++x;x<N; x+=x&-x){
        bit[x] += v;
    }
}

int query(int x){
    int res = 0;
    for(++x; x; x-=x&-x){
        res+=bit[x];
    }
    return res;
}

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){
    int n;
    while(n=read()){
        if(n==0){break;}
        memset(bit,0,sizeof(bit));
        int con=0;
        for(int i=0,x;i<n;i++){
            x=read();
            con+= i-query(x);
            add(x,1);
        }

        if(con%2==0){
            putchar('C');
            putchar('a');
            putchar('r');
            putchar('l');
            putchar('o');
            putchar('s');
            putchar('\n');
        }else{
            putchar('M');
            putchar('a');
            putchar('r');
            putchar('c');
            putchar('e');
            putchar('l');
            putchar('o');
            putchar('\n');
        }
    }
    return 0;
}
