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
#include<cstdio>
//#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>

#define icc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int long long
using ull = unsigned long long;
using namespace std;
const int MAXN=1000005;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

//-block

signed main(){
    int N;
    while(N=read()){
        vector<int>dat(N);
        for(int i=0;i<N;++i){
            dat[i]=read();
        }
        if(N<3){
            putchar('n');
            putchar('o');
            putchar(' ');
            putchar('s');
            putchar('o');
            putchar('l');
            putchar('u');
            putchar('t');
            putchar('i');
            putchar('o');
            putchar('n');
            putchar('\n');
            continue;
        }
        sort(dat.begin(),dat.end());

        int flag=LLONG_MIN;
        for(int i=dat.size()-1;i>=2;--i){
            for(int j=i-1;j>=1;--j){
                for(int k=j-1;k>=0;--k){
                    int ans=dat[i]+dat[j]+dat[k];
                    auto pos=lower_bound(dat.begin(),dat.end(),ans);
                    if(pos==dat.end() || *pos!=ans || pos-dat.begin()==i || pos-dat.begin()==j || pos-dat.begin()==k){continue;}

                    if(ans>flag){flag=ans;}
                }
            }
        }
        if(flag==LLONG_MIN){
            putchar('n');
            putchar('o');
            putchar(' ');
            putchar('s');
            putchar('o');
            putchar('l');
            putchar('u');
            putchar('t');
            putchar('i');
            putchar('o');
            putchar('n');
            putchar('\n');
        }else{
            write(flag);
            putchar('\n');
        }
    }
    return 0;
}

