#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <vector>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
        if(c=='-'){w=-1;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-block
inline int min(const int &a,const int &b){
    return a<b?a:b;
}

int N,B,H,W,prc;
signed main(){
    while(N=read()){
        B=read();H=read();W=read();

        int res=1000000000;
        for(int i=0;i<H;++i){
            prc=read();
            for(int j=0;j<W;++j){
                int tmp=read();
                if(tmp>=N){
                    res=min(res,N*prc);
                }
            }
        }

        if(res>B){
            printf("stay home\n");
        }else{
            write(res);
            putchar('\n');
        }
    }
    return 0;
}
/*
541
O O O O O
2363
O X O O O
2568
O O O O O
3070
O O O O O
4068
O O O O O
5199
O O O O O
6230
O O O O O
6092
X X O O O
6997
O X O O O
7794
O O O O O
*/
