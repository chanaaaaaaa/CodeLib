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
//#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#include<string>

#define icc ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using ull = unsigned long long;
using namespace std;
const int MAXN=1000005;
/*
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
*/
//-block

int main(){
    icc;
    string A,B;
    while(cin>>A>>B){
        int Asz=A.size(),
            Bsz=B.size();
        vector<int>Anum(Asz);
        vector<int>Bnum(Bsz);
        for(int i=0;i<Asz;++i){
            Anum[Asz-i-1]=A[i]-'0';
        }
        for(int i=0;i<Bsz;++i){
            Bnum[Bsz-i-1]=B[i]-'0';
        }

        int Msz=Asz+Bsz+1;
        vector<int>res(Msz+1,0);
        for(int i=0;i<Asz;++i){
            for(int j=0;j<Bsz;++j){
                res[i+j]+=Anum[i]*Bnum[j];
            }
        }
        for(int i=0;i<Msz;++i){
            res[i+1]+=res[i]/10;
            res[i]%=10;
        }
        while(res[Msz]==0 && Msz>0){
            --Msz;
        }
        for(int i=Msz;i>=0;--i){
            putchar(res[i]+'0');
        }
        putchar('\n');
    }
    return 0;
}

