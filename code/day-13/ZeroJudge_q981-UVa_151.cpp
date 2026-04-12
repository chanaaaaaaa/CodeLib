#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
// -block
inline int slove(int N,int m){
    int ans=1;
    for(int i=2;i<=N;i++){
        ans=(ans+(m-1))%i+1;
    }
    return ans;
}
signed main(void){
    int N;
    while(N=read()){
        if(N==0){break;}
        if(N==13){
            write(1);
            putchar('\n');
            continue;
        }
        int m=2;
        while(slove(N-1,m)!=12){m++;}
        write(m);
        putchar('\n');
    }
    return 0;
}
