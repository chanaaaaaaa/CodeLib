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
vector<int>dat(205,0);
vector<int>F(205,0);
inline int findroot(int x){
    if(F[x]==x){return x;}
    return F[x]=findroot(F[x]);
}
signed main(){
    int N,M;
    while(N=read()){
        M=read();
        if(N+M==0){break;}

        for(int i=0;i<205;++i){
            F[i]=i;dat[i]=0;
        }

        for(int i=0;i<M;++i){
            int a=read(),b=read();
            int fa=findroot(a),fb=findroot(b);
            if(fa!=fb){
                F[fa]=fb;
            }
            ++dat[a];++dat[b];
        }

        bool flag=true;

        if(M==0){flag=false;}

        if(flag){
            int root=-1;
            for(int i=0;i<N;++i){
                if(dat[i]>0){
                    root=findroot(i);
                    break;
                }
            }

            if(root==-1){
                flag=false;
            }else{
                for(int i=0;i<N;++i){
                    if(dat[i]>0){
                        if(dat[i]%2!=0 || findroot(i)!=root){
                            flag=false;
                            break;
                        }
                    }
                }
            }
        }
        if(!flag){
            putchar('N');
            putchar('o');
            putchar('t');
            putchar(' ');
        }
        putchar('P');
        putchar('o');
        putchar('s');
        putchar('s');
        putchar('i');
        putchar('b');
        putchar('l');
        putchar('e');
        putchar('\n');
    }
    return 0;
}
