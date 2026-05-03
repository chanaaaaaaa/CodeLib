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
    return;
}
//-block
inline int max(const int &a,const int &b){
    return a>b?a:b;
}
//-func
//-template
inline void solve(){
    int now=0,maxx=0,tot=0,cnt=0,N;
    while(N=read()){
        if(N<=now){
            now=N;
            ++cnt;
        }else{
            now=N;
            maxx=max(maxx,cnt);
            cnt=1;
            ++tot;
        }
    }
    write(maxx);
    putchar('\n');
    write(tot);
    putchar('\n');
    return;
}
signed main(){
    solve();
    return 0;
}
