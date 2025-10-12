#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>

#define MAXP 1000
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0'&& c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
// -block
bool isprime[MAXP+1];
vector<int>primes;
inline void form(){
    for(int i=2;i<=MAXP;i++){
        if(!isprime[i]){primes.emplace_back(i);}
        for(auto &p:primes){
            if(i*p>MAXP){break;}
            isprime[i*p]=true;
            if(i%p==0){break;}
        }
    }
    primes.insert(primes.begin(),1);//
}

int C,N;
inline void slove(int N,int C){
    write(N);
    putchar(' ');
    write(C);
    putchar(':');

    int cnt=0;
    while(primes[cnt]<=N){cnt++;}
    //write(cnt);
    //putchar(' ');
    if(C*2-1>=cnt){
        for(int i=0;i<cnt;i++){
            if(primes[i]==0){break;}
            putchar(' ');
            write(primes[i]);
        }
    }else if(cnt%2==0){
        int s=(cnt-(C*2))/2;
        for(int i=0;i<C*2;i++){
            putchar(' ');
            write(primes[s+i]);
        }
    }else{
        int s=(cnt-(C*2-1))/2;
        for(int i=0;i<C*2-1;i++){
            putchar(' ');
            write(primes[s+i]);
        }
    }
    putchar('\n');
    putchar('\n');
}
signed main(void){
    form();/*
    for(auto &i:primes){
        write(i);
        putchar(' ');
    }*/
    //input
    while(N=read()){
        if(N==-1){break;}
        C=read();
        slove(N,C);
    }
    return 0;
}
