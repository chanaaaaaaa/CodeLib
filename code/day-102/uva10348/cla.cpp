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
#include <iostream>
#include <set>
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
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
bool check;
inline void solve(int dat[],int now,int res){
    if(now==5){
        if(res==23){
            check=true;
        }
        return;
    }
    for(int i=0;i<5;++i){
        if(dat[i]==-1){continue;}
        int tmp=dat[i];
        dat[i]=-1;

        solve(dat,now+1,res+tmp);
        solve(dat,now+1,res-tmp);
        solve(dat,now+1,res*tmp);

        dat[i]=tmp;
    }
    return;
}
signed main(){

    while(true){
        int dat[5];
        dat[0]=read();
        dat[1]=read();
        dat[2]=read();
        dat[3]=read();
        dat[4]=read();
        if(dat[0]+dat[1]+dat[2]+dat[3]+dat[4]==0){
            break;
        }
        check=false;

        for(int i=0;i<5;++i){
            int tmp=dat[i];
            dat[i]=-1;
            solve(dat,1,tmp);
            dat[i]=tmp;
        }


        if(check){
            putchar('P');
            putchar('o');
            putchar('s');
            putchar('s');
            putchar('i');
            putchar('b');
            putchar('l');
            putchar('e');
        }else{
            putchar('I');
            putchar('m');
            putchar('p');
            putchar('o');
            putchar('s');
            putchar('s');
            putchar('i');
            putchar('b');
            putchar('l');
            putchar('e');
        }
        putchar('\n');
    }
	return 0;
}
