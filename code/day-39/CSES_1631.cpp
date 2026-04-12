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
    int N,maxx,sum;
    while(N=read()){
        vector<int>dat(N);
        maxx=0;sum=0;
        for(int i=0;i<N;i++){
            dat[i]=read();
            maxx=max(maxx,dat[i]);
            sum+=dat[i];
        }
        if(maxx>=sum-maxx){
            write(maxx*2);
            putchar('\n');
            continue;
        }
        sort(dat.begin(),dat.end());

        int pin_1=0, pin_2=0,
            value_1=0,value_2=0;

        while(pin_1<N && pin_2<N){
            if(value_1 < value_2){
                value_1+=dat[pin_1++];
            }else{
                value_2+=dat[pin_2++];
            }
        }
        write(max(value_1,value_2));
        putchar('\n');
    }
}
