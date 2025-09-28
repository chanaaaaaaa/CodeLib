#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
#include<iostream>
#define int long long
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

    int n,L;
    n=read();
    L=read();
    int cut[n];
    vector<int>bp;
    bp.push_back(L);
    for(int i=0;i<n;i++){
        int temp=read();
        cut[read()-1]=temp;
    }
    int cost=0;
    for(int i=0;i<n;i++){
        auto ins=lower_bound(bp.begin(),bp.end(),cut[i]);
        if(ins==bp.begin()){
            if(bp.size()==1){
                cost+=L;
            }else{
                cost+=bp[ins-bp.begin()];
            }
        }else{
            cost+=bp[ins-bp.begin()]-bp[ins-bp.begin()-1];
        }
        bp.insert(ins,cut[i]);
        /*a
        for(int i=0;i<bp.size();i++){
            write(bp[i]);
            putchar(' ');
        }
        putchar(' ');
        write(cost);
        putchar('\n');
        *///b

    }
    write(cost);
    return 0;
}
