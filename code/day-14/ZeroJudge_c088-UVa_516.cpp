#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<sstream>

#define MAXN 32768
using namespace std;

inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

// -block
vector<int>primes;
bool isprime[MAXN+1];
inline void form(){
    for(int i=2;i<=MAXN;i++){
        if(!isprime[i]){primes.emplace_back(i);}
        for(int &p:primes){
            if(i*p>MAXN){break;}
            isprime[i*p]=true;
            if(i%p==0){break;}
        }
    }
}

inline int power(int x,int depth){
    if(depth==1){return x;}
    return x*power(x,depth-1);
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    form();/*
    for(int &p:primes){
        write(p);
        putchar('\n');
    }*/
    string IN,P;
    while(getline(cin,IN)){
        if(IN=="0"){break;}
        //decode
        stringstream ss(IN);
        int n=0,l=0,num=1;
        while(ss>>P){
            if(n==0){
                for(int i=0;i<P.size();i++){
                    n=(n<<3)+(n<<1)+(P[i]-'0');
                }
            }else{
                for(int i=0;i<P.size();i++){
                    l=(l<<3)+(l<<1)+(P[i]-'0');
                }
                num*=power(n,l);
                n=0;l=0;
            }
        }
        //-decode
        //cal
        num-=1;
        //-cal
        int index=primes.size()-1,cnt,flag=0;
        while(num!=1){
            cnt=0;
            while(num%primes[index]==0){
                num/=primes[index];
                cnt++;
            }
            if(cnt){
                if(flag){putchar(' ');}
                else{flag=1;}
                write(primes[index]);
                putchar(' ');
                write(cnt);
            }
            index--;
        }
        putchar('\n');
    }
    return 0;
}
