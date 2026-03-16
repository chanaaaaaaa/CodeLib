#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
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

#include <cstdio>
#include <cstdlib>

using namespace std;

/* I/O Optimize */
inline int min(int a,int b){
    return a<b?a:b;
}

const int INF =1e9;
const int coin[6]={5,10,20,50,100,200};

int have[6],tot,tmp,res,prc;

inline int cus(int N){
    int rem=0;
    for(int i=5;i>=0;--i){
        tmp=min(have[i],N/coin[i]);
        rem+=tmp;
        N-=tmp*coin[i];
        if(N==0){return rem;}
    }
    return INF;
}
inline int sel(int N){
    int rem=0;
    for(int i=5;i>=0;--i){
        rem+=N/coin[i];
        N%=coin[i];
    }
    return rem;
}
inline void solve(){
    //-table
    while(true){
        tot=0;res=INF;
        for(int i=0;i<6;++i){
            scanf("%d",&have[i]);
            tot+=have[i]*coin[i];
        }
        if(tot==0){break;}
        double dprc;
        scanf("%lf",&dprc);
        prc=(int)(dprc*100+0.5);

        for(int i=0;i+prc<=tot && i<=600;++i){
            res=min(res,cus(i+prc)+sel(i));
        }
        printf("%3d\n",res);
    }
}

/* Programing area*/
signed main(){
    solve();
    system("pause");
    return 0;
}
