#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<climits>
#include<vector>

#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
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
    int N=read(),x=read(),cnt,res,l=0,r=1e18,mid;
    vector<int>dat(N);
    for(int i=0;i<N;++i){
        dat[i]=read();
    }
    while(l<=r){
        cnt=0;
        mid=l+((r-l)>>1);
        for(int &s:dat){
            cnt+=mid/s;
            if(cnt>=x){break;}
        }
        if(cnt>=x){
            res=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    write(res);
    putchar('\n');
    return 0;
}
