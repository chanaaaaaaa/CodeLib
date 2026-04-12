#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>

#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
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
signed main(){
    int N=read();
    while(N--){
        int A=read(),B=read(),D=A-B;
        if(D>0){
            A-=D*2;
            B-=D;
        }else if(D<0){
            A+=D;
            B+=D*2;
        }
        if(A%3==0 && A>=0 && B>=0){
            putchar('Y');
            putchar('E');
            putchar('S');
            putchar('\n');
        }else{
            putchar('N');
            putchar('O');
            putchar('\n');
        }
    }
    return 0;
}
