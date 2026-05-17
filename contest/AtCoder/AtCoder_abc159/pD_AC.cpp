#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <unordered_map>

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
//at (A-1)*(A-2)/2 A^2-3A+2 //2
//no at A*(A-1)/2  A^2-A  //2
//walk to -2A+2
signed main(){
    unordered_map<int,int>mp;
    unordered_map<int,int>ans;
    int N=read();
    int dat[N],tot=0;
    for(int i=0;i<N;++i){
        dat[i]=read();
        ++mp[dat[i]];
    }

    for(unordered_map<int,int>::iterator it=mp.begin();it!=mp.end();++it){
        tot+=((it->second)*(it->second-1))>>1;
    }

    for(int i=0;i<N;++i){
        write(tot-mp[dat[i]]+1);
        putchar('\n');
    }
    return 0;
}
