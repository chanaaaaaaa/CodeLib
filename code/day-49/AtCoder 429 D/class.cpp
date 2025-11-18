#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<algorithm>
#include<vector>

#define MAXN 10000
#define int long long
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
//-block
int N,M,C,cnt,res,pos;
signed main(){
    while(N=read()){
        M=read();C=read();
        vector<int>dat(N);
        for(int i=0;i<N;++i){
            dat[i]=read();
        }
        sort(dat.begin(),dat.end());
        for(int i=0;i<N;++i){
            dat.emplace_back(dat[i]);
        }

        pos=0;res=0;
        for(int i=0;i<N;++i){
            while(pos-i<C || pos-i<N && dat[pos+1]==dat[pos]){
                ++pos;
            }
            cnt=dat[i+1]-dat[i];
            if(i==N-1){
                cnt=dat[0]+M-dat[N-1];
            }
            res+=cnt*(pos-i);
        }
        write(res);
        putchar('\n');
    }
    return 0;
}
