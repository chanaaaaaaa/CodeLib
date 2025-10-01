#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<cstdio>
#include<algorithm>
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
	}
	while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
	}
	return x*w;
}
inline void write(long x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}



long dp[67][67][2];

signed main() {
    dp[1][1][1]=1;
    dp[1][0][0]=1;
    for(int i=2;i<=65;i++){
        dp[i][0][0]=dp[i-1][1][1]+dp[i-1][0][0];
        for(int j=1;j<=i;j++){
            dp[i][j][1]=dp[i-1][j-1][0]+dp[i-1][j-1][1];
            dp[i][j][0]=dp[i-1][j+1][1]+dp[i-1][j][0];
        }
    }


    while(true){
        int n=read(),s=read();
        if(n+s<0){break;}
        write(dp[n][s][0]+dp[n][s][1]);
        putchar('\n');
    }
    return 0;
}
