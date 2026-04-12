#include <cstdio>

#define int long long
using namespace std;

inline int read(){
    int x=0,w=1,c=0;
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
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
inline int abs(int a){
    return a>0?a:-a;
}

signed main(){
    int ax=read(),ay=read(),bx=read(),by=read();

    int dx=abs(ax-bx),dy=abs(ay-by);
    if((dx+dy)&1){
        write(-1);
        putchar('\n');
        return 0;
    }

    int du=abs((ax+ay)-(bx+by))/2;
    int dv=abs((ax-ay)-(bx-by))/2;

    if(du%2 == dv%2){
        write(du>=dv?du*2:dv*2);
    }else{
        write(du>=dv?du*2-1:dv*2+1);
    }
    putchar('\n');
    return 0;
}
