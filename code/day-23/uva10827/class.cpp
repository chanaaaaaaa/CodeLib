//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<climits>
#include<memory.h>
using namespace std;

inline int read(){
    bool check=false;
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(long long x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
int T,N,num[160][160],sum[160],he,Max;

inline void solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            memset(sum,0,sizeof(sum));
            for(int k=i;k<N+i;k++){
                he=0;
                for(int l=j;l<N+j;l++){
                    sum[l]+=num[k][l];
                    he+=sum[l];
                    if(Max<he){
                        Max=he;
                    }
                }
            }
        }
    }
}

signed main(){
    T=read();
    while(T--){
        N=read();
        Max=-INT_MAX;
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                num[i][j]=num[i+N][j]=num[i][j+N]=num[i+N][j+N]=read();
                if(num[i][j]>Max){Max=num[i][j];}
            }
        }
        //-init
        solve();
        write(Max);
        if(T)putchar('\n');
    }

    return 0;
}
