#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<set>
//#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
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

signed main(){
    int n=read(),x=read();
    vector<int>dat(n+1);
    set<int>lib;

    for(int i=0;i<n;++i){
        dat[i]=read();
        if(lib.count(x-dat[i])){
            for(int j=0;j<i;++j){
                if(dat[j]==x-dat[i]){
                    write(j+1);
                    putchar(' ');
                    write(i+1);
                    return 0;
                }
            }
        }
        lib.insert(dat[i]);
    }


    putchar('I');
    putchar('M');
    putchar('P');
    putchar('O');
    putchar('S');
    putchar('S');
    putchar('I');
    putchar('B');
    putchar('L');
    putchar('E');
    return 0;
}
