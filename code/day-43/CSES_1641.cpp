#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
#include<limits>

#define MAXN 500
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
    int N=read(),x=read();
    vector<pair<int,int>> a;
    a.reserve(N);
    for(int i=1;i<=N;++i){
        a.push_back({read(),i});
    }

    sort(a.begin(),a.end());

    for(int i=0;i<N;++i){
        int target=x-a[i].first;
        int l=i+1,r=N-1;
        while(l<r){
            if(a[l].first+a[r].first==target){
                int idx1=a[i].second,idx2=a[l].second,idx3=a[r].second;
                if(idx1>idx2) swap(idx1,idx2);
                if(idx2>idx3) swap(idx2,idx3);
                if(idx1>idx2) swap(idx1,idx2);
                write(idx1);
                putchar(' ');
                write(idx2);
                putchar(' ');
                write(idx3);
                putchar('\n');
                return 0;
            }
            if(a[l].first+a[r].first<target){
                ++l;
            }else{
                --r;
            }
        }
    }
    putchar('I');putchar('M');putchar('P');putchar('O');putchar('S');putchar('S');putchar('I');putchar('B');putchar('L');putchar('E');putchar('\n');
    return 0;
}
