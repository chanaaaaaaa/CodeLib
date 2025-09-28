#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<iostream>
#include<cmath>
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
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=read();
    while(t--){
        int IN=read(),su=1;
        for(int i=2;i<sqrt(IN);i++){
            if(IN%i==0){
                su+=i;
                su+=IN/i;
            }
        }
        if(su==IN){cout<<"perfect\n";}
        else if(su<IN){cout<<"deficient\n";}
        else if(su>IN){cout<<"abundant\n";}
    }
    return 0;
}
