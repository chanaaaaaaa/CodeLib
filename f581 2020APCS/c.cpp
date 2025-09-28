#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){
    int n,m,t=0;
    n=read();
    m=read();
    int p[n],q;
    vector<int>pr;
    for(int i=0;i<n;i++){
        p[i]=read();
        t+=p[i];
        pr.push_back(t);
    }
    t=0;
    while(m--){
        q=read();
        if(t!=0){q+=pr[t-1];}
        if(q>pr[n-1]){q-=pr[n-1];}
        t=(int)(lower_bound(pr.begin(),pr.end(),q)-pr.begin()+1);
        t%=n;
    }
    write(t);
    return 0;
}
