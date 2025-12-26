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

// a little of optimize
// just ignore it

//#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c>'9' || c<'0'){
        c=getchar();
        if(c==-1){return -1;}
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
// use getchar to complete read and write is my habit
// it's more efficient than iostream or stdio.h

signed main(){
    int a,b; // a->the first number, b->the second number
    while(true){
        a=read();// Input
        if(a==-1){break;} // do while Input is illegal
        b=read();// Input

        vector<int>res;
        while(b){                   //輾轉相除 然後把數字推進res
            res.emplace_back(a/b);
            a%=b;

            int temp=a;             //輾轉
            a=b;
            b=temp;
        }
        putchar('[');                           // Output
        write(res[0]);                          // Output
        putchar(';');                           // Output
        for(int i=1;i<res.size();++i){          // Output
            write(res[i]);                      // Output
            if(i!=res.size()-1){putchar(',');}  // Output
        }
        putchar(']');
        putchar('\n');           // change line
    }
    return 0;
}
/*
心得:
利用 輾轉相除法找出連續分數的係數。
每次迭代，計算當前分數整數部分為連續分數的係數，
然後取餘數繼續計算下一個係數，直到為 0 。

43 19
1 2
*/
