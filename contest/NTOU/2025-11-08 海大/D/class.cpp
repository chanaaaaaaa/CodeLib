#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#include<cstdio>
#include<vector>
#include<algorithm>

#define MAXN 1000005
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
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}


vector<int>mu(MAXN+1);
vector<int>primes;
vector<bool>is_prime(MAXN+1,true);
vector<int>cnt(MAXN+1, 0);

void pm(){
    mu[1] = 1;
    is_prime[0]=is_prime[1]=false;
    primes.reserve(80000);

    for(int i=2;i<=MAXN;++i){
        if(is_prime[i]){
            primes.push_back(i);
            mu[i]=-1;
        }
        for(int j=0;j<primes.size() && i*primes[j]<=MAXN;++j){
            is_prime[i*primes[j]]=false;
            if(i%primes[j]==0){
                mu[i*primes[j]]=0;
                break;
            } else {
                mu[i*primes[j]]=-mu[i];
            }
        }
    }
}

void pt(const vector<int>& dat){
    for(int a:dat){

        for(int d=1;d*d<=a;++d){
            if(a%d==0){
                if(d<=MAXN){++cnt[d];}
                int d2=a/d;
                if(d2!=d && d2<=MAXN){
                    ++cnt[d2];
                }
            }
        }
    }
}

signed main(void){
    pm();

    int N,Q;
    N=read();
    Q=read();
    vector<int>dat(N);
    vector<int>use(Q);

    for(int i=0;i<N;++i){dat[i]=read();}
    for(int i=0;i<Q;++i){use[i]=read();}

    pt(dat);

    for(int i=0;i<Q;++i){
        int c=use[i];
        int ans=0;


        for(int d=1;d*d<=c;++d){
            if(c%d==0){
                if(d<=MAXN){
                    ans+=mu[d]*cnt[d];
                }
                int d2=c/d;
                if(d2!=d && d2<=MAXN){
                    ans+=mu[d2]*cnt[d2];
                }
            }
        }

        write(ans);
        putchar('\n');
    }
}
