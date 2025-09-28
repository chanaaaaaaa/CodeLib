#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>f={4,1,2};

vector<vector<int>>dat;
int N,M,A,B;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        if(c=='-') w=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){

    N=read();
    M=read();
    dat.reserve(N+1);
    dat.assign(N,f);
    while(M--){
        A=read()-1;
        B=read();
        if(B==-1){
            dat[A]={dat[A][1],7-dat[A][0],dat[A][2]};
        }else if(B==-2){
            dat[A]={dat[A][0],7-dat[A][2],dat[A][1]};
        }else{
            B--;
            swap(dat[A],dat[B]);
        }
    }
    for(int i=0;i<N;i++){
        write(dat[i][1]);
        putchar(' ');
    }
    return 0;
}
