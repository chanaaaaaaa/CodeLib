#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
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
// -block
 signed main(void){
    int t=read();
    for(int i=1;i<=t;i++){
        int n=read(),k=read(),con=0,j=1;

        while(j<=n){
            con=(con+k)%(j++);
        }

        putchar('C');
        putchar('a');
        putchar('s');
        putchar('e');
        putchar(' ');
        write(i);
        putchar(':');
        putchar(' ');
        write(con+1);
        putchar('\n');
    }
}
