#include <cstdio>
#include <vector>
#include <map>
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
//==

const int MAXN=1<<16;
vector<int>primes;
bool isprime[MAXN+1];

inline void build(){
    for(int i=2;i<MAXN;++i){
        if(!isprime[i]){primes.push_back(i);}
        for(int p:primes){
            if(i*p>MAXN){break;}
            isprime[i*p]=true;
            if(i%p==0){break;}
        }
    }
}

signed main(){
    build();
    int A,B;
    while(true){
        A=read();if(A==-1){break;}
        B=read();

        if(B==1 || B==0){
            printf("%d divides %d!\n",B,A);
            continue;
        }

        map<int,int>mp;
        for(int i=2,num;i<=A;++i){
            num=i;
            for(int pos=0,cnt;pos<primes.size() && num!=1;++pos){
                cnt=0;
                while(num%primes[pos]==0){
                    num/=primes[pos];
                    ++cnt;
                }
                //printf("%d %d %d\n",i,primes[pos],cnt);
                mp[primes[pos]]+=cnt;
            }
        }
        //
        //for(auto p:mp){
        //    printf("%d %d\n",p.first,p.second);
        //}
        //
        bool f=true;
        int num=B;
        for(int pos=0,cnt;pos<primes.size();++pos){
            cnt=0;
            while(num%primes[pos]==0){
                num/=primes[pos];
                ++cnt;
            }
            if(mp[primes[pos]]>=cnt){
                mp[primes[pos]]-=cnt;
            }else{
                f=false;
                break;
            }
        }

        if(f && num==1){
            printf("%d divides %d!\n",B,A);
        }else{
            printf("%d does not divide %d!\n",B,A);
        }
    }
    return 0;
}
