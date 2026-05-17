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

signed main(){
    
    int N=read();
    int dat[N];
    for(int i=0;i<N;++i){
        dat[i]=read();
    }
    int tall=0,res=0;
    for(int i=1;i<N;++i){
        if(dat[i]<dat[tall]){
            res+=dat[tall]-dat[i];
        }else if(dat[i]>dat[tall]){
            tall=i;
        }
    }

    write(res);
    putchar('\n');
    return 0;
}

