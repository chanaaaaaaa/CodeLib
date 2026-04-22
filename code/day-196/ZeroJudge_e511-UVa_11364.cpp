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
inline int max(const int &a,const int &b){
    return a>b?a:b;
}
inline int min(const int &a,const int &b){
    return a<b?a:b;
}
//13 24 37 89 ->152
//13:76+76
//24:9+9+65+65

//7 14 30 39 41 42 ->70
int T,N,minn,maxx;
signed main(){
    T=read();
    while(T--){
        N=read();
        minn=100000000;
        maxx=-100000000;

        while(N--){
            int tmp=read();
            minn=min(minn,tmp);
            maxx=max(maxx,tmp);
        }

        write((maxx-minn)*2);
        putchar('\n');
    }
    return 0;
}
