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
        if(c==-1){return -1;}
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
inline void say(string x){
    for(int i=0;i<x.size();i++){
        putchar(x[i]);
    }
    putchar('\n');
}
// -block
signed main(void){
    int K,Q,M;
    string out="";
    while(K==read()){
        if(K==-1){break;}
        Q=read();
        M=read();
        if(K==Q){out="Illegal state";}
        else if(K/8!=Q/8 && K%8!=Q%8){
            if(M!=K+1 && M!=K-1 && M!=K+8 && M!=K-8){
                out="Continue";
            }
        }else{
            if(M==K+1 || M==K-1 || M==K+8 || M==K-8){
                out="Move not allowed";
            }
            if((Q>K && M<K) || (Q<K && M>K)){
                out="Illegal move"
            }
        }
        //(((K+1)/8==M/8 || (K+1)%8==M%8) && (K+1<64))
        //(((K-1)/8==M/8 || (K-1)%8==M%8) && (K-1>=0))
        //(((K+8)/8==M/8 || (K+8)%8==M%8) && (K+8<64))
        //(((K-8)/8==M/8 || (K-8)%8==M%8) && (K-8>=0))
        if()
    }
    return 0;
}
