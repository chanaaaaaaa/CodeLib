#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("avx")
#include <cstdio>
#include <vector>
#include <climits>
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
int N,M,fow,bck;
vector<int>dat,cnt;

signed main(){
    while(N=read()){
        M=read();
        dat.assign(M,0);
        cnt.assign(N+1,0);
        for(int &i:dat){i=read()-1;}

        for(int i=0;i<M-1;i++){
            fow=(dat[i]-dat[i+1]+N)%N;
            bck=(dat[i+1]-dat[i]+N)%N;

            cnt[dat[i]]  +=(fow-bck)%N;
            cnt[dat[i+1]]+=(bck-fow)%N;
            if(dat[i]>dat[i+1]){
                cnt[N]-=fow;
                cnt[0]+=fow;
            }else if(dat[i]<dat[i+1]){
                cnt[N]-=bck;
                cnt[0]+=bck;
            }
        }

        int res=LLONG_MAX;
        for(int i=0;i<N;++i){
            cnt[i+1]+=cnt[i];
            res=min(res,cnt[i]);
        }
        write(res);
        putchar('\n');
    }
    return 0;
}
