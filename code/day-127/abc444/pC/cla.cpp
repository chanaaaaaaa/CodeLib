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
#include <algorithm>
#include <vector>
#include <map>
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
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
signed main(){
    int N=read();
    map<int,int>cnt;
    int sumA=0,maxA=0;

    for(int i=0;i<N;++i){
        int tmp=read();
        ++cnt[tmp];
        sumA+=tmp;
        if(tmp>maxA){maxA=tmp;}
    }

    int minK=(N+1)/2,maxK=N;

    vector<int>ans;

    auto check=[&](int L){
        if(L<maxA){return;}

        for(auto const &[val,tm]:cnt){
            if(val==L){continue;}
            if(val>L){return;}

            int target=L-val;
            if(val>target){
                if(cnt.find(target)==cnt.end()){return;}
                continue;
            }

            if(val==target){
                if(tm%2!=0){return;}
            }else{
                auto it=cnt.find(target);
                if(it==cnt.end() || it->second!=tm){return;}
            }
        }
        ans.emplace_back(L);
    };

    for(int k=1;k*k<=sumA;++k){
        if(sumA%k==0){
            int d1=k,d2=sumA/k;

            if(d1>=minK && d1<=maxK){check(sumA/d1);}

            if(d1!=d2 && d2>=minK && d2<=maxK){check(sumA/d2);}
        }
    }

    sort(ans.begin(),ans.end());

    for(int i=0;i<ans.size();++i){
        write(ans[i]);
        if(i==ans.size()-1){
            putchar('\n');
        }else{
            putchar(' ');
        }
    }

    return 0;
}
