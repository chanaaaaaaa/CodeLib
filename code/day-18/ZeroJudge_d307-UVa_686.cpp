#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<set>
#include<unordered_map>
#define MAXN 32768
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
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
bool isprimes[MAXN+1];
set<int>primes;
unordered_map<int,int>mp;
int N;
inline void form(){
    for(int i=2;i<MAXN;i++){
        if(!isprimes[i]){
            primes.insert(i);
            for(auto p = primes.cbegin(); p!=primes.cend();p++){
                if(*p+i>MAXN){break;}
                mp[i+*p]++;
            }
        }
        for(auto p = primes.cbegin(); p!=primes.cend();p++){
            if(*p*i>MAXN){break;}
            isprimes[*p*i]=true;
            if(*p%i==0){break;}
        }
    }
}

int main(){
    form();/*
    for(auto &it:mp){
        write(it.first);
        putchar(' ');
        write(it.second);
        putchar('\n');
    }*/

    while(N=read()){
        write(mp[N]);
        putchar('\n');
    }
    return 0;
}
