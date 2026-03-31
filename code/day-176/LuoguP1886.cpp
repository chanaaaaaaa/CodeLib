#include <cstdio>

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

const int MAXN=1e6+50;

int dat[MAXN];
int N,M;

inline void getmax(){
    int queue[MAXN],head=0,tail=-1;
    for(int i=0;i<M;++i){
        while(head<=tail && dat[queue[tail]]<=dat[i]){
            --tail;
        }
        queue[++tail]=i;
    }
    for(int i=M-1;i<N;++i){
        while(head<=tail && dat[queue[tail]]<=dat[i]){
            --tail;
        }
        queue[++tail]=i;
        while(queue[head] <= i-M){++head;}
        write(dat[queue[head]]);
        putchar(' ');
    }
}
inline void getmin(){
    int queue[MAXN],head=0,tail=-1;
    for(int i=0;i<M;++i){
        while(head<=tail && dat[queue[tail]]>=dat[i]){
            --tail;
        }
        queue[++tail]=i;
    }
    for(int i=M-1;i<N;++i){
        while(head<=tail && dat[queue[tail]]>=dat[i]){
            --tail;
        }
        queue[++tail]=i;
        while(queue[head] <= i-M){++head;}
        write(dat[queue[head]]);
        putchar(' ');
    }
}
signed main(){
    while(N=read()){
        M=read();
        for(int i=0;i<N;++i){
            dat[i]=read();
        }
        getmin();
        putchar('\n');
        getmax();
        putchar('\n');
    }
    return 0;
}
