#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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
#include <cstdio>
#include <vector>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
vector<int>res;
vector<int>A;
inline void multi(vector<int>&a,vector<int>&b){
    vector<int>tmp(a.size()+b.size(),0);

    for(int i=0;i<a.size();++i){
        for(int j=0;j<b.size();++j){
            tmp[i+j]+=a[i]*b[j];
        }
    }

    for(int i=0;i<tmp.size();++i){
        if(tmp[i]>=10){
            if(i==tmp.size()-1){
                tmp.emplace_back(tmp[i]/10);
            }else{
                tmp[i+1]+=tmp[i]/10;
            }
            tmp[i]%=10;
        }
    }

    while(tmp.size()>1 && tmp.back()==0){
        tmp.pop_back();
    }
    a=tmp;
}
inline void add(vector<int>&a,vector<int>&b,int d){
    while(a.size()<b.size()){a.emplace_back(0);}

    int carry=0;
    for(int i=0;i<a.size();++i){

        if(i<b.size()){
            a[i]+=b[i]*d;
        }
        a[i]+=carry;
        carry=a[i]/10;
        a[i]%=10;
    }

    while(carry){
        a.emplace_back(carry%10);
        carry/=10;
    }
}
signed main(){
    int N,a;
    while(N=read()){

        a=read();
        res.clear();
        res.emplace_back(0);
        A.clear();

        while(a){
            A.emplace_back(a%10);
            a/=10;
        }

        vector<int>tmp(1,1);
        for(int i=1;i<=N;++i){
            multi(tmp,A);
            add(res,tmp,i);

        }

        for(int i=res.size()-1;i>=0;--i){
            write(res[i]);
        }
        putchar('\n');
    }
	return 0;
}
