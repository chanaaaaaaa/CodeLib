#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inilne")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-ferun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-function-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
//#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#define int long long
#define icc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


bool isenter=false;
inline int read(){
    int x=0;
    char c=0;
    while(c>'9' || c<'0'){
        c=getchar();
        if(c=='\n'){
            if(isenter){
                isenter=false;
                return 0;
            }
        }
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    isenter=true;

    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block

signed main(){
    int N=read();
    getchar();
    while(N--){
        int P=read(),T=read();
        int i,j;
        vector<set<int>>dat;
        dat.assign(P,set<int>());
        while(i=read()){
            j=read();
            dat[i-1].insert(j);
        }

        int res=0;
        for(auto &s1:dat){
            for(auto &s2:dat){
                if(s1==s2){++res;}
            }
        }
        write(res/2);
        putchar('\n');
        if(N){putchar('\n');}
    }
    return 0;
}
/*
1

3 4
1 2
3 3
1 3
2 2
3 2
2 4

*/
