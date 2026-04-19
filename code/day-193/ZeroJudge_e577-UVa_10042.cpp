#include <cstdio>
#include <vector>

using namespace std;

inline int read(){
    int x=0,c=0,w=1;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
        if(c=='-'){w=-1;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}

const int MAXN=100005;
vector<int>primes;
bool isprime[MAXN]={false};
inline void form(){
    for(int i=2;i<MAXN;++i){
        if(!isprime[i]){primes.emplace_back(i);}
        for(int &p:primes){
            if(i*p>=MAXN){break;}
            isprime[i*p]=true;
            if(i%p==0){break;}
        }
    }
    return;
}

inline int digsum(int x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}

inline int getprimesum(int x){
    int res=0,cnt=0;
    for(int &p:primes){
        if(p*p>x){break;}
        if(x%p==0){
            int dig=digsum(p);
            while(x%p==0){
                ++cnt;
                res+=dig;
                x/=p;
            }
        }
    }
    if(x>1){res+=digsum(x);++cnt;}
    if(cnt<=1){return -1;}
    return res;
}


int T,N;
signed main(){
    form();
    while(T=read()){
        while(T--){
            N=read();
            for(int i=N+1;i<2000000000;++i){
                if(digsum(i)==getprimesum(i)){
                    write(i);
                    putchar('\n');
                    break;
                }
            }
        }
    }
    return 0;
}
