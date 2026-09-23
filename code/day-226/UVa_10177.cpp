#include <cstdio>
#include <vector>
#include <queue>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c>='A'&&c<='Z'){return c-'A';}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x+1;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//block
inline int ksm(int a,int b){
    int res=1;
    while(b){
        if(b&1){
            res*=a;
        }
        b>>=1;
        a*=a;
    }
    return res;
}

int N;
signed main(){
    while(N=read()){
        --N;
        int s[3]={0},q[3]={0};
        int k=(N*(N+1))>>1;

        for(int i=1;i<=N;++i){
            for(int j=0;j<3;++j){
                s[j]+=ksm(i,j+2);
            }
        }
        for(int i=0;i<3;++i){
            q[i]=ksm(k,i+2)-s[i];
        }

        for(int i=0;i<2;++i){
            write(s[i]);
            putchar(' ');
            write(q[i]);
            putchar(' ');
        }
        write(s[2]);
        putchar(' ');
        write(q[2]);
        putchar('\n');
    }
    return 0;
}
