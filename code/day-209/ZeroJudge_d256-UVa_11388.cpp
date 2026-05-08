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
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){
    int T=read(),G,L,A,B;
    //while(T=read()){
        while(T--){
            G=read();L=read();

            if(L%G){
                putchar('-');
                putchar('1');
            }else{
                write(G);
                putchar(' ');
                write(L);
            }
            putchar('\n');
        }
    //}
    return 0;
}
