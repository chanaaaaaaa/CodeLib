#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>
#include <set>
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
}
//-block
const int MAXN=2e5+10;

signed main(){
    int N=read();
    int Q=read();
    vector<int>a(MAXN);
    vector<int>b(MAXN);
    vector<int>f(MAXN);
    vector<multiset<int,greater<int>>>s(MAXN);
    multiset<int>x;

    for(int i=1;i<=N;++i){
        a[i]=read();
        f[i]=b[i]=read();
        s[b[i]].insert(a[i]);
    }
    for(int i=1;i<MAXN;++i){
        if(!s[i].empty()){x.insert(*s[i].begin());}
    }

    while(Q--){
        int c=read();
        int d=read();
        int p=a[c];
        int zu=f[c];

        s[zu].erase(s[zu].find(p));
        f[c]=d;
        if(s[zu].empty() || p>*s[zu].begin()){
            x.erase(x.find(p));
            if(!s[zu].empty()){x.insert(*s[zu].begin());}
        }
        if(s[d].empty() || p>*s[d].begin()){
            if(!s[d].empty()){x.erase(x.find(*s[d].begin()));}
            x.insert(p);
        }
        s[d].insert(p);
        write(*x.begin());
        putchar('\n');
    }
    return 0;
}
