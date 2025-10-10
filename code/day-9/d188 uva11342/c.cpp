#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<math.h>
using namespace std;

inline long long read(){
    long long x=0;
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
inline void write(long long x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

// -block

signed main(){
    int t=read();
    while(t--){
        int num=read(),flag=0,a,b,i,j;

        for(i=0;i*i<num;i++){
            a=num-i*i;
            for(j=0;j*j<num;j++){
                b=a-j*j;
                if(b<0){break;}
                if(ceil(sqrt(b))==sqrt(b)){
                    flag=1;
                    break;
                }
            }
            if(flag){break;}
        }

        if(i*i+j*j+b==num){
            write(i);
            putchar(' ');
            write(j);
            putchar(' ');
            write(sqrt(b));
        }else{write(-1);}
        putchar('\n');
    }
    return 0;
 }
