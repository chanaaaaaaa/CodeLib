#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>

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
// -block

signed main(){

    int n;
    while(n=read()){
        if(n==0){break;}
        vector<int>dat(n);
        for(int i=0;i<n;i++){
            dat[i]=read();
        }
        sort(dat.begin(),dat.end());
        for(int i=0;i<dat.size();i++){
            if(i){putchar(' ');}
            write(dat[i]);
        }
        putchar('\n');
    }
    return 0;
}
