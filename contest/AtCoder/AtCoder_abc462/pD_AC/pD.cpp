#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define int long long
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
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//
signed main(){
    vector<int>dat(1e6+1,0);
    int N,D,s,t;
    N=read();D=read();
    for(int i=0;i<N;++i){
        s=read();t=read();
        if(t-s>=D){
            ++dat[s];
            --dat[t-D+1];
        }
    }

    int c=0,res=0;
    for(int i=0;i<1e6+1;++i){
        c+=dat[i];
        res+=c*(c-1)/2;
    }
    write(res);
    putchar('\n');
    return 0;
}
/*

*/
