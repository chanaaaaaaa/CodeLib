#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<climits>
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return -1;}
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
// -block

signed main(){
    int N;
    while(N=read()){
        if(N==-1){break;}
        int dat[N][N],maxx=INT_MIN;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dat[i][j]=read();
            }
        }
        //do
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                dat[i][j]=read();
            }
        }

    }
    return 0;
}
