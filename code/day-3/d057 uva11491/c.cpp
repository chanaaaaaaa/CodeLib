#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<math.h>
using namespace std;

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
    int a,b,c,d;
    while(a=read(),b=read(),c=read(),d=read()){
        if(a+b+c+d==0){break;}
        if(a==c && b==d){
            putchar('0');
            putchar('\n');
        }else if(a==c || b==d || abs(a-c)==abs(b-d)){
            putchar('1');
            putchar('\n');
        }else{
            putchar('2');
            putchar('\n');
        }
    }
    return 0;
}
