#include <cstdio>
#include <algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0,w=1;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}

int T,N,Q;
int val[1005];
int wgt[1005];
signed main(){
    while(T=read()){
        while(T--){
            int res=0;
            N=read();
            for(int i=0;i<N;++i){
                val[i]=read();
                wgt[i]=read();
            }
            Q=read();
            while(Q--){
                int w=read(),ans=0;
                int dp[w+1]={0};
                for(int i=0;i<N;++i){
                    for(int j=w;j>=wgt[i];--j){
                        dp[j]=max(dp[j],dp[j-wgt[i]]+val[i]);
                    }
                }
                for(int j=0;j<=w;++j){
                    ans=max(ans,dp[j]);
                }
                res+=ans;
            }
            write(res);
            putchar('\n');
        }
    }
    return 0;
}
