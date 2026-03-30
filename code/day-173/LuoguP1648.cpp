#include <cstdio>
#include <algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

const int MAXN=1e6+5;

int n,d,res,dat[MAXN][5];
signed main(){
    while(n=read()){
        d=read();

        for(int i=1;i<=n;++i){
            for(int j=0;j<d;++j){
                dat[i][j]=read();
            }
        }
        res=0;

        int mstate=1<<(d-1);
        for(int state=0;state<mstate;++state){
            int maxx=-9e18;
            int minn=9e18;

            for(int i=1;i<=n;++i){
                int val=dat[i][0];
                for(int j=1;j<d;++j){
                    if((state>>(j-1)) & 1){
                        val-=dat[i][j];
                    }else{
                        val+=dat[i][j];
                    }
                }
                maxx=max(maxx,val);
                minn=min(minn,val);
            }
            res=max(res,maxx-minn);
        }
        write(res);
        putchar('\n');
    }
}
