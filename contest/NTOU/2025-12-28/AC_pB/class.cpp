#include<iostream>
#define int long long
using namespace std;

inline int fastPow(int base,int exp,int mod) {
    int result=1;
    base%=mod;
    while(exp){
        if(exp & 1){
            result=(result*base)%mod;
        }
        base=(base*base)%mod;
        exp>>=1;
    }
    return result;
}

int gcd(int a,int b) {
    return b==0?a:gcd(b,a%b);
}

int modInv(int a,int m) {
    int m0=m,t,q;
    int x0=0,x1=1;
    if(m==1){return 0;}
    while(a>1){
        q=a/m;
        t=m;
        m=a%m;
        a=t;
        t=x0;
        x0=x1-q*x0;
        x1=t;
    }
    if(x1<0){x1+=m0;}
    return x1;
}
int geometricSum(int A,int n,int M) {
    if(n==0){return 0;}
    if(n==1){return 1;}
    if(A==1){return n%M;}

    int A_minus_1=(A-1+M)%M;
    if(gcd(A_minus_1,M)==1){
        int numerator=(fastPow(A,n,M)-1+M)%M;
        int inv=modInv(A_minus_1,M);
        return (numerator*inv)%M;
    }

    if(n&1){
        int half=n/2;
        int sum_half=geometricSum(A,half,M);
        int A_half=fastPow(A,half,M);
        int A_n_minus_1=fastPow(A,n-1,M);
        return (sum_half*(1+A_half)%M+A_n_minus_1)%M;
    }else{
        int half=n/2;
        int sum_half=geometricSum(A,half,M);
        int A_half=fastPow(A,half,M);
        return (sum_half*(1+A_half)%M)%M;
    }
}

int cac(int A,int N,int M) {
    if(N==1){return 0;}
    return geometricSum(A,N-1,M);
}

signed main(){
    int A,M,N;
    while(cin>>A>>N>>M){
        cout<<cac(A,N,M)<<'\n';
    }
    return 0;
}
