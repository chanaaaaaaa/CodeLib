#pragma GCC optimize("Ofast,unroll-loops")
#include<cstdio>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
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
inline int gcd(int a,int b){
    return a?gcd(b%a,a):b;
}

int T,G,L;
bool f;
signed main(){
    T=read();
    while(T--){
        G=read();L=read();
        f=false;
        for(int A=G;A<=L;A+=G){
            if((G*L)%A==0){
                if(gcd(A,G*L/A)==G){
                    f=true;
                    write(A);
                    putchar(' ');
                    write(G*L/A);
                    putchar('\n');
                    break;
                }
            }
        }
        if(!f){
            putchar('-');
            putchar('1');
            putchar('\n');
        }
    }
    return 0;
}
