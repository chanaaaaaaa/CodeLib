#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<algorithm>
#include<memory.h>

#define int long long
using namespace std;

int dat[51][51][51];

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

inline int dot(int k,int m,int n){
    if(k==1){
        if(n>=1 && m>=n){return 1;}
        else{return 0;}
    }
    if(dat[k][m][n]==-1){
        int temp=0;
        for(int i=1;i<=min(m,n);i++){
            temp+=dot(k-1,m,n-i);
        }
        dat[k][m][n]=temp;
    }
    return dat[k][m][n];
}

signed main(){

    memset(dat,-1,sizeof(dat));
    int n,k,m;
    while(n=read()){
        k=read();
        m=read();
        write(dot(k,m,n));
        putchar('\n');
    }
    return 0;
}
