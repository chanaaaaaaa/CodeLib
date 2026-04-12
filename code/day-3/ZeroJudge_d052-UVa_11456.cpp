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
    int t=read();
    while(t--){
        //input
        int n=read(),maxx=0;
        vector<int>dat(n*2);
        vector<int>res(n*2);
        for(int i=0;i<n;i++){
            dat[n+i]=dat[n-i-1]=read();
        }
        //-input

        //LIS
        for(int i=0;i<n*2;i++){
            res[i]=1;
            for(int j=0;j<i;j++){
                if(dat[i]>dat[j]){
                    res[i]=max(res[i],res[j]+1);
                }
            }
            maxx=max(maxx,res[i]);
        }
        //output
        write(maxx);
        putchar('\n');
    }
    return 0;
}
