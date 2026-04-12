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
    int x=0,w=1;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
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
int dat[9][9];
signed main(){
    int N=read();
    while(N--){
        dat[8][0]=read();

        dat[6][0]=read();
        dat[6][2]=read();
        dat[6][1]=(dat[8][0]-dat[6][0]-dat[6][2])/2;

        dat[4][0]=read();
        dat[4][2]=read();
        dat[4][4]=read();
        dat[4][1]=(dat[6][0]-dat[4][0]-dat[4][2])/2;
        dat[4][3]=(dat[6][2]-dat[4][2]-dat[4][4])/2;

        dat[2][0]=read();
        dat[2][2]=read();
        dat[2][4]=read();
        dat[2][6]=read();
        dat[2][1]=(dat[4][0]-dat[2][0]-dat[2][2])/2;
        dat[2][3]=(dat[4][2]-dat[2][2]-dat[2][4])/2;
        dat[2][5]=(dat[4][4]-dat[2][4]-dat[2][6])/2;

        dat[0][0]=read();
        dat[0][2]=read();
        dat[0][4]=read();
        dat[0][6]=read();
        dat[0][8]=read();
        dat[0][1]=(dat[2][0]-dat[0][0]-dat[0][2])/2;
        dat[0][3]=(dat[2][2]-dat[0][2]-dat[0][4])/2;
        dat[0][5]=(dat[2][4]-dat[0][4]-dat[0][6])/2;
        dat[0][7]=(dat[2][6]-dat[0][6]-dat[0][8])/2;

        dat[7][0]=dat[6][0]+dat[6][1];
        dat[7][1]=dat[6][1]+dat[6][2];

        dat[5][0]=dat[4][0]+dat[4][1];
        dat[5][1]=dat[4][1]+dat[4][2];
        dat[5][2]=dat[4][2]+dat[4][3];
        dat[5][3]=dat[4][3]+dat[4][4];

        dat[3][0]=dat[2][0]+dat[2][1];
        dat[3][1]=dat[2][1]+dat[2][2];
        dat[3][2]=dat[2][2]+dat[2][3];
        dat[3][3]=dat[2][3]+dat[2][4];
        dat[3][4]=dat[2][4]+dat[2][5];
        dat[3][5]=dat[2][5]+dat[2][6];

        dat[1][0]=dat[0][0]+dat[0][1];
        dat[1][1]=dat[0][1]+dat[0][2];
        dat[1][2]=dat[0][2]+dat[0][3];
        dat[1][3]=dat[0][3]+dat[0][4];
        dat[1][4]=dat[0][4]+dat[0][5];
        dat[1][5]=dat[0][5]+dat[0][6];
        dat[1][6]=dat[0][6]+dat[0][7];
        dat[1][7]=dat[0][7]+dat[0][8];

        for(int i=8;i>=0;--i){
            for(int j=0;j<9-i;++j){
                if(j!=0){putchar(' ');}
                write(dat[i][j]);
            }
            putchar('\n');
        }
    }
    return 0;
}
