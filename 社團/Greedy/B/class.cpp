#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
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
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}


signed main(void){
    int n=read(),x=read(),cnt=0;
    vector<int>chs;
    for(int i=0;i<n;i++){chs.push_back(read());}
    sort(chs.begin(),chs.end());
    int l=0,r=n-1;

    while(l<r){
        if(chs[l]+chs[r]<=x){
            cnt++;
            l++;r--;
        }else{
            cnt++;r--;
        }
    }
    if(l==r){cnt++;}
    write(cnt);
}
