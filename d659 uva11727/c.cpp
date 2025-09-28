#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
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
signed main(){
    int N=read();
    for(int r=1;r<=N;r++){
        int dat[3];
        for(int i=0;i<3;i++){
            dat[i]=read();
            for(int j=0;j<i;j++){
                if(dat[i]<dat[j]){
                    int temp=dat[i];
                    dat[i]=dat[j];
                    dat[j]=temp;
                }
            }
        }
        cout<<"Case ";
        write(r);
        cout<<": ";
        write(dat[1]);
        putchar('\n');
    }

    return 0;
}
