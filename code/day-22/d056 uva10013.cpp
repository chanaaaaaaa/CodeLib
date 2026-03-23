//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
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
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
inline int read_o(){
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    return c-'0';
}
signed main(){
    int T=read();
    while(T--){
        int N=read();

        vector<int>res(N+2,0);
        for(int i=1;i<=N;i++){
            res[i]+=read_o();
            res[i]+=read_o();
        }
        for(int i=N;i>0;i--){
            if(res[i]>=10){
                res[i]-=10;
                res[i-1]++;
            }
        }
        if(res[0]!=0){write(res[0]);}
        for(int i=1;i<=N;i++){
            write(res[i]);
        }
        if(T){putchar('\n');}
        putchar('\n');
    }
    return 0;
}
