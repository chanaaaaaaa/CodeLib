#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<math.h>

#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0'&& c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
// -block
inline int solve(int x,int y,int mod){
	if(y==0){return 1;}

	if(y%2){return (x*solve(x,y-1,mod))%mod;}
	else{
		int half=solve(x,y/2,mod);
		return (half*half)%mod;
	}
}

signed main(void){
    int B,P,M;
    while(true){
        B=read();
        if(B==-1){break;}
        P=read();M=read();
        write(solve(B,P,M));
        putchar('\n');
    }
    return 0;
}
