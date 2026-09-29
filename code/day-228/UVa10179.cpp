#pragma GCC optimize("Ofast,nuroll-loops,no-stack-protector,fast-math")

#include <cstdio>
#include <vector>

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
const int MAXN=50000;
vector<int>primes;
vector<bool>isprime;

vector<int>frac;
int N;
signed main(){
    isprime.assign(MAXN+5,false);
    for(int i=2;i<MAXN;++i){
        if(!isprime[i]){
            primes.emplace_back(i);
        }
        for(int &n:primes){
            if(n*i>MAXN){break;}
            isprime[n*i]=true;
            if(i%n==0){break;}
        }
    }
    while(N=read()){
        frac.clear();
        int res=N;
        for(int &n:primes){
            if(N<=1){break;}
            if(N%n==0){
                frac.emplace_back(n);
                while(N%n==0){
                    N/=n;
                }
            }
        }
        if(N>1){frac.emplace_back(N);}

        for(int &n:frac){
            res=res/n*(n-1);
        }

        write(res);
        putchar('\n');
    }
    return 0;
}
