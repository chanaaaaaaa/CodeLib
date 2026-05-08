#include <cstdio>
using namespace std;

inline int read(){
    int x=0,c=0,w=1;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
        if(c=='-'){w=-1;}
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
    return;
}

inline bool check(int k,int m){
    int pos=0;
    int n=k<<1;

    for(int i=0;i<k;++i){
        pos=(pos+m-1)%n;
        
        if(pos<k){return false;}
        --n;
    }
    return true;
}
inline void calans(){
    for(int k=1;k<14;++k){
        int m=k+1;
        
        while(!check(k,m)){
            ++m;
        }
        
        write(m);
        putchar(',');
    }
}
//2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881
const int ANS[14]={0,2,7,5,30,169,441,1872,7632,1740,93313,459901,1358657,2504881};
signed main(){
    //calans();
    int N;
    while(N=read()){
        write(ANS[N]);
        putchar('\n');
    }
    return 0;
}