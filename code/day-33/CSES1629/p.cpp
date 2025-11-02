//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block

signed main(){
    int N=read();
    vector<pair<int,int>>dat;
    while(N--){
        dat.push_back({read(),read()});
    }
    sort(dat.begin(),dat.end(),
         [](pair<int,int>a,pair<int,int>b){return a.second<b.second;}
         );
    int edt=0,mv=0;
    for(int i=0;i<dat.size();i++){
        if(dat[i].first>=edt){
            mv++;
            edt=dat[i].second;
        }
    }
    write(mv);
    return 0;
}
