#include <cstdio>
#include <vector>

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
    return;
}
//-block
inline int max(int &a,int &b){
    return a>b?a:b;
}

int N,M,Ls,Rs;
vector<int>dat;

inline bool check(int x){
    int cnt=1,now=0;
    for(int &n:dat){
        now+=n;
        if(now>x){
            now=n;
            ++cnt;
            if(cnt>M){return false;}
        }
    }
    return true;
}

signed main(){
    while(N=read()){
        M=read();
        dat.assign(N,0);
        Ls=0;Rs=0;

        for(int i=0;i<N;++i){
            dat[i]=read();
            Rs+=dat[i];
            Ls=max(Ls,dat[i]);
        }

        while(Ls<Rs){
            int mid=(Ls+Rs)>>1;

            if(check(mid)){
                Rs=mid;
            }else{
                Ls=mid+1;
            }
        }
        write(Ls);
        putchar('\n');
    }
    return 0;
}
