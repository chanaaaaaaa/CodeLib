#include <cstdio>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//block
int T,A,B,MOD,res;

signed main(){
    while(T=read()){
        while(T--){
            A=read();B=read();MOD=read();

            res=1;
            while(B){
                if(B&1){
                    res=(res*A)%MOD;
                }

                A=(A*A)%MOD;
                B>>=1;
            }
            write(res);
            putchar('\n');
        }
    }
    return 0;
}
/*
2
2 3 5
2 2147483647 13
0
*/
