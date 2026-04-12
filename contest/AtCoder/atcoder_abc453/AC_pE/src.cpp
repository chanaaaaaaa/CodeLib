#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
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
//-block
const int MOD=998244353;

inline long long power(long long base,long long exp) {
    long long res=1;
    base%=MOD;
    while(exp>0){
        if(exp&1){res=(res*base)%MOD;}
        base=(base*base)%MOD;
        exp/=2;
    }
    return res;
}

inline long long modInverse(long long n) {
    return power(n,MOD-2);
}

vector<long long>fact,invFact;

inline void precompute(int n){
    fact.assign(n+1,1);
    invFact.assign(n+1,1);
    for (int i=1;i<=n;i++){
        fact[i]=(fact[i-1]*i)% MOD;
    }
    invFact[n]=modInverse(fact[n]);
    for(int i=n-1;i>=0;i--){
        invFact[i]=(invFact[i+1]*(i+1))%MOD;
    }
}

inline long long nCr(int n,int r){
    if(r<0 || r>n){return 0;}
    return fact[n]*invFact[r]%MOD *invFact[n - r]%MOD;
}

signed main(){
    int N=read();

    vector<int>diff_A(N+2,0);
    vector<int>diff_B(N+2,0);
    vector<int>diff_Both(N+2,0);

    for(int i=0;i<N;++i){
        int L=read(),R=read();

        ++diff_A[L];
        --diff_A[R+1];

        int bL=N-R;
        int bR=N-L;
        if(bL<=bR){
            ++diff_B[bL];
            --diff_B[bR+1];
        }

        int intL=max(L,bL);
        int intR=min(R,bR);
        if(intL<=intR){
            ++diff_Both[intL];
            --diff_Both[intR+1];
        }
    }

    precompute(N);

    long long total_ways=0;
    int A_count=0,B_count=0,Both_count=0;

    for(int k=1;k<N;++k){
        A_count+=diff_A[k];
        B_count+=diff_B[k];
        Both_count+=diff_Both[k];

        int c_both=Both_count;
        int c_A=A_count-Both_count;
        int c_B=B_count-Both_count;


        int c_none=N-(c_A+c_B+c_both);

        if(c_none==0){
            int target=k-c_A;
            if(target>=0 && target<=c_both){
                total_ways=(total_ways+nCr(c_both,target))%MOD;
            }
        }
    }

    write(total_ways);
    putchar('\n');
    return 0;
}
