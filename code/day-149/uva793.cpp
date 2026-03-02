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

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-block
const int MAXN=1e5;
int rk[MAXN],dat[MAXN],T,N,cor,mis,A,B;
char buf[3];

inline int fd(int x){
    return dat[x]==x ? x:dat[x]=fd(dat[x]);
}
inline void un(int a,int b){
    if(rk[a]>rk[b]){
        dat[b]=a;
    }else{
        dat[a]=b;
        if(rk[a]==rk[b]){
            ++rk[b];
        }
    }
    return;
}

signed main(){
    while(scanf("%d\n",&T)!=EOF){
        while(T--){
            cor=0;mis=0;

            scanf("%d\n",&N);
            for(int i=1;i<=N;++i){
                rk[i]=0;
                dat[i]=i;
            }
            while(buf[0]=getchar()){
                if(buf[0]=='\n' || buf[0]==EOF){break;}

                scanf("%d%d",&A,&B);getchar();
                A=fd(A);B=fd(B);

                if(buf[0]=='c'){
                    if(A!=B){un(A,B);}
                }else{
                    if(A==B){
                        ++cor;
                    }else{
                        ++mis;
                    }
                }
            }

            write(cor);
            putchar(',');
            write(mis);
            putchar('\n');

            if(T){putchar('\n');}
        }
    }
    return 0;
}
