#include <vector>
#include <cstdio>

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
const int MAXN=3e5+1;

int N,Q,t,x,fix;
vector<int>dat;
vector<int>high;
signed main(){
    while(N=read()){
        Q=read();
        dat.assign(MAXN,0);
        high.assign(MAXN,0);
        fix=0;
        for(int i=0;i<Q;++i){
            t=read();x=read();
            if(t==1){
                ++dat[x];
                ++high[dat[x]];
                if(high[dat[x]]==N){fix=dat[x];}
            }
            if(t==2){
                if(x+fix>Q){
                    putchar('0');
                    putchar('\n');
                }else{
                    write(high[x+fix]);
                    putchar('\n');
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
