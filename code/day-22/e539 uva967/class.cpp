//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<set>

#define MAXN 1000005
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return -1;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
set<int>primes;
bool isprime[MAXN];
int ns,ne,cnt;

inline void form(){
    for(int i=2;i<=MAXN;i++){
        if(!isprime[i]){primes.insert(i);}
        for(auto it=primes.cbegin();it!=primes.cend();it++){
            if(*it*i>MAXN){break;}
            isprime[*it*i]=true;
            if(i%*it==0){break;}
        }
    }
}

inline bool solve(int x){
    int judge=1,co=x;
    while(judge<x){judge*=10;}
    judge/=10;

    do{
        int temp=co%10;
        co=co/10+temp*judge;
        if(!primes.count(co)){return false;}
    }while(co!=x);
    return true;
}

signed main(){
    form();
    while(true){
        ns=read();
        if(ns==-1){break;}
        ne=read();

        cnt=0;
        /*normal ans
        while(ns<=ne){
            if(solve(ns++)){cnt++;}
        }*/
        //stange but fast ans
        set<int>hehehe{113,131,197,199,311,337,373,719,733,919,971,991,
                    1193,1931,3119,3779,7793,7937,9311,9377,11939,19391,
                    19937,37199,39119,71993,91193,93719,93911,99371,193939,
                    199933,319993,331999,391939,393919,919393,
                    933199,939193,939391,993319,999331};
        for(auto it=hehehe.cbegin();it!=hehehe.cend();it++){
            if(*it>=ns){
                if(*it<=ne){cnt++;}
                else{break;}
            }
        }
        //
        if(cnt){
            write(cnt);
        }else{
            putchar('N');
            putchar('o');
        }
        putchar(' ');
        putchar('C');
        putchar('i');
        putchar('r');
        putchar('c');
        putchar('u');
        putchar('l');
        putchar('a');
        putchar('r');
        putchar(' ');
        putchar('P');
        putchar('r');
        putchar('i');
        putchar('m');
        putchar('e');
        if(cnt!=1){putchar('s');}
        putchar('.');
        putchar('\n');
    }
    return 0;
}
