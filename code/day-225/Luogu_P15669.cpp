#include <cstdio>
#include <cmath>

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
int N,D,S,maxx;

signed main(){
    while(N=read()){
        D=read();
        S=read();

        int res=max(S*(D/S),S);
        for(int l=1,r;l<=D/S;l=r+1){
            int Q=(D/S)/l;
            r=(D/S)/Q;

            int B=min(r,(N/S)/(Q+1));
            if(B>=l){
                int A=B*(Q+1);
                res=max(res,S*A);
            }
        }

        write(res);
        putchar('\n');
    }
    return 0;
}
