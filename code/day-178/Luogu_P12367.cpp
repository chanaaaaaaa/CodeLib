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
inline int abs(const int &a){
    return a>0?a:-a;
}

const int d[6][2]={
    {-2,0},
    {-1,1},
    {1,1},
    {2,0},
    {1,-1},
    {-1,-1}
};

int ad,ap,aq,bd,bp,bq;
signed main(){
    ad=read();
    ap=read();
    aq=read();
    bd=read();
    bp=read();
    bq=read();

    int ax=d[ad][0]*ap+d[(ad+2)%6][0]*aq;
    int ay=d[ad][1]*ap+d[(ad+2)%6][1]*aq;

    int bx=d[bd][0]*bp+d[(bd+2)%6][0]*bq;
    int by=d[bd][1]*bp+d[(bd+2)%6][1]*bq;

    int dx=abs(ax-bx);
    int dy=abs(ay-by);

    if(dx >= dy){
        write((dy+dx)>>1);
    }else{
        write(dy);
    }
    putchar('\n');
    return 0;
}
