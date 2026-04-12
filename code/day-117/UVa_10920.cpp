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
#include <math.h>
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
    return x+1;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
inline int power(int n,int k){
    if(k==1){return n;}
    return n*power(n,k-1);
}
signed main(){
    int N,M;
    while(N=read()){
        M=read();
        --N;--M;
        if(N+M==0){break;}

        int p=(int)(sqrt(M-0.1)+1)/2,
            c=(N+1)/2,
            l=M-(2*p-1)*(2*p-1);

        if(l<=p*2){
            putchar('L');putchar('i');putchar('n');putchar('e');putchar(' ');putchar('=');putchar(' ');
            write(c+p);
            putchar(',');putchar(' ');putchar('c');putchar('o');putchar('l');putchar('u');putchar('m');putchar('n');putchar(' ');putchar('=');putchar(' ');
            write(c+p-l);
        }else if(l<=p*4){
            l-=p*2;
            putchar('L');putchar('i');putchar('n');putchar('e');putchar(' ');putchar('=');putchar(' ');
            write(c+p-l);
            putchar(',');putchar(' ');putchar('c');putchar('o');putchar('l');putchar('u');putchar('m');putchar('n');putchar(' ');putchar('=');putchar(' ');
            write(c-p);
        }else if(l<=p*6){
            l-=p*4;
            putchar('L');putchar('i');putchar('n');putchar('e');putchar(' ');putchar('=');putchar(' ');
            write(c-p);
            putchar(',');putchar(' ');putchar('c');putchar('o');putchar('l');putchar('u');putchar('m');putchar('n');putchar(' ');putchar('=');putchar(' ');
            write(c-p+l);
        }else{
            l-=p*6;
            putchar('L');putchar('i');putchar('n');putchar('e');putchar(' ');putchar('=');putchar(' ');
            write(c-p+l);
            putchar(',');putchar(' ');putchar('c');putchar('o');putchar('l');putchar('u');putchar('m');putchar('n');putchar(' ');putchar('=');putchar(' ');
            write(c+p);
        }
        putchar('.');
        putchar('\n');
    }
    return 0;
}
