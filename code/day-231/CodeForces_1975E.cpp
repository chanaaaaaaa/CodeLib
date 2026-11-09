#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("avx")
#include <cstdio>
#include <stack>
#include <utility>
#include <algorithm>
#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//block
const int MAXN=4e5+5;
const int INF=1e18+5;

int dat[MAXN],L[MAXN],R[MAXN],pfx[MAXN];
int T,N,pos,res;
stack<pair<int,int>>stkpii;

inline int cal(int x,int s){
    int tmp=x-s+1;
    return (x+tmp)*s>>1;
}
signed main(){
    while(T=read()){
        while(T--){
            N=read();
            for(int i=1;i<=N;++i){
                dat[i]=read();
                pfx[i]=pfx[i-1]+dat[i];
            }
            //L side
            while(!stkpii.empty()){stkpii.pop();}
            for(int i=1;i<=N;++i){
                while(!stkpii.empty() && stkpii.top().first > dat[i]-i){stkpii.pop();}

                if(stkpii.empty()){
                    pos=0;
                }else{
                    pos=stkpii.top().second;
                }

                if(pos!=0){
                    L[i]=L[pos]+pfx[i]-pfx[pos]-cal(dat[i],min(i-pos,dat[i]));
                }else{
                    L[i]=pfx[i]-cal(dat[i],min(i,dat[i]));
                }
                stkpii.push({dat[i]-i,i});
            }

            //R side
            reverse(dat+1,dat+1+N);

            for(int i=1;i<=N;++i){pfx[i]=pfx[i-1]+dat[i];}
            while(!stkpii.empty()){stkpii.pop();}
            for(int i=1;i<=N;++i){
                while(!stkpii.empty() && stkpii.top().first > dat[i]-i){stkpii.pop();}

                if(stkpii.empty()){
                    pos=0;
                }else{
                    pos=stkpii.top().second;
                }

                if(pos!=0){
                    R[i]=R[pos]+pfx[i]-pfx[pos]-cal(dat[i],min(i-pos,dat[i]));
                }else{
                    R[i]=pfx[i]-cal(dat[i],min(i,dat[i]));
                }
                stkpii.push({dat[i]-i,i});
            }

            //cal
            for(int l=1,r=N;l<=r;++l,--r){
                swap(R[l],R[r]);
            }
            res=INF;
            reverse(dat+1,dat+1+N);
            for(int i=1;i<=N;++i){
                res=min(res,L[i]+dat[i]+R[i]);
            }
            write(res);
            putchar('\n');
        }
    }
    return 0;
}
