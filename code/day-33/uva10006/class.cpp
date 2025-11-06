//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<stdio.h>
#include<vector>
#include<set>
using namespace std;

//--block
set<int>primes;
bool isprime[65001];
inline void primef(){
    for(int i=2;i<=65000;i++){
        if(!isprime[i]){primes.insert(i);}
        for(auto it=primes.cbegin();it!=primes.cend();it++){
            if(*it*i>65000){break;}
            isprime[*it*i]=true;
            if(i%*it==0){break;}
        }
    }
}
inline int solve(int a,int n,int m){
    if(n==1){return a%m;}

    long long tmp=solve(a,n/2,m);
    tmp=(tmp*tmp)%m;
    if(n%2){tmp=(tmp*a)%m;}
    return tmp;
}
set<int>res;
inline void form(){
    primef();
    for(int i=2;i<=65000;i++){
        if(primes.count(i)){continue;}
        int now;
        for(now=2;now<i;now++){
            printf("%d-%d\n",i,now);
            if(solve(now,i,i)!=now){break;}
        }

        if(now==i){res.insert(i);}
    }
}
signed main(){
    /*
    form();
    for(auto it=res.cbegin();it!=res.cend();it++){
        printf("%d,",*it);
    }*/
    //get 561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973
    set<int>ans={561,1105,1729,2465,2821,6601,8911,10585,15841,29341,41041,46657,52633,62745,63973};
    int N=0;
    while(scanf("%d",&N)&&N){
        if(ans.count(N)){
            printf("The number %d is a Carmichael number.\n",N);
        }else{
            printf("%d is normal.\n",N);
        }
    }
    return 0;
}

