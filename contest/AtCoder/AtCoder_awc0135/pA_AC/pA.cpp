#include <cstdio>
#include <cmath>
#include <climits>

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
    return;
}
//
const int MAXN=2e5+50;
int dat[MAXN],N,R,minn,cnt;
signed main(){
    while(N=read()){
        R=read();
        minn=INT_MAX;
        cnt=0;
        for(int i=0;i<N;++i){
            dat[i]=read();
            minn=min(minn,dat[i]);
        }
        for(int i=0;i<N;++i){
            cnt+=dat[i]-minn;
        }

        write(cnt);
        putchar('\n');
    }
    return 0;
}
