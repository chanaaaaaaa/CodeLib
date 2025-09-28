#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<memory.h>
//prf do the any one or two cut between cut and cut and return the min cost
using namespace std;
int dat[27][27][352];
inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){

    memset(dat,0,sizeof(dat));
    dat[0][0][0]=1;
    int L,S,cases=0;
    for(int i=1;i<=26;i++){
        for(int j=0;j<=i;j++){
            for(int k=0;k<=351;k++){
                dat[i][j][k]=dat[i-1][j][k];
                if(j && k>=i){dat[i][j][k] += dat[i-1][j-1][k-i];}
            }
        }
    }
    while(L=read(),S=read(), L&&S){
        putchar('C');
        putchar('a');
        putchar('s');
        putchar('e');
        putchar(' ');
        write(++cases);
        putchar(':');
        putchar(' ');
        if(L<=26 && S<=351){
            write(dat[26][L][S]);
        }else{putchar('0');}
        putchar('\n');
    }


    return 0;
}
