#include <cstdio>
#include <algorithm>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0,w=1;
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

struct point{
    int x,y;
};

inline int orient(point &p, point&q, point &r){
    long long val=(q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);

    if(val>0){
        return 1;
    }else if(val<0){
        return -1;
    }else{
        return 0;
    }
}

inline bool onSegment(point &p, point &q, point &r){
    return r.x>=min(p.x, q.x) && r.x<=max(p.x, q.x) &&
           r.y>=min(p.y, q.y) && r.y<=max(p.y, q.y);
}

int T;
signed main(){
    while(T=read()){
        while(T--){
            point A,B,C,D;
            A.x=read();A.y=read();
            B.x=read();B.y=read();
            C.x=read();C.y=read();
            D.x=read();D.y=read();

            int d1=orient(A,B,C);
            int d2=orient(A,B,D);
            int d3=orient(C,D,A);
            int d4=orient(C,D,B);

            if(d1*d2 < 0 && d3*d4 < 0){
                putchar('Y');putchar('E');putchar('S');putchar('\n');
            }else if(d1*d2 > 0 || d3*d4 > 0){
                putchar('N');putchar('O');putchar('\n');
            }else if((d1==0 && onSegment(A,B,C)) ||
                     (d2==0 && onSegment(A,B,D)) ||
                     (d3==0 && onSegment(C,D,A)) ||
                     (d4==0 && onSegment(C,D,B))){
                putchar('Y');putchar('E');putchar('S');putchar('\n');
            }else{
                putchar('N');putchar('O');putchar('\n');
            }
        }
    }
    return 0;
}
