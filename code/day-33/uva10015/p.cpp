//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>

#define MAXN 32610
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
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
int N;
bool isprime[MAXN];
vector<int>primes;
inline void form(){
    for(int i=2;i<MAXN;i++){
        if(!isprime[i]){primes.emplace_back(i);}
        for(auto& p:primes){
            if(p*i>MAXN){break;}
            isprime[p*i]=true;
            if(i%p==0){break;}
        }
    }
}
inline int solve(int x){
    vector<int>vec(x);
    for(int i=0;i<x;i++){
        vec[i]=i;
    }
    int tot=x,now=0,idx=0;
    while(tot!=1){
        now=(now+primes[idx++]-1)%(tot--);
        vec.erase(vec.begin()+now);
    }
    return vec[0]+1;
}
signed main(){
    form();
    while(N=read()){
        write(solve(N));
        putchar('\n');
    }
    return 0;
}
