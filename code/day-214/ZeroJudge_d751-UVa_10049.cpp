#include <cstdio>
#include <algorithm>

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

const int MAXN=673365;
//only need to remind Left boundary
int dat[MAXN],N;

signed main(){
    dat[1]=1;
    dat[2]=3;
    for(int i=3;i<MAXN;++i){
        dat[i]=dat[i-1]+(lower_bound(dat+1,dat+i,i)-dat);
    }
    while(N=read()){
        write(lower_bound(dat+1,dat+MAXN,N)-dat);
        putchar('\n');
    }
    return 0;
}
