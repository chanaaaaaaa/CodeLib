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
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main() {
    int t=read();
    while(t--){
        int dis=read()/100;
        int wind[10][dis],dp[10][dis+1];
        for(int i=9;i>=0;i--){
            for(int j=0;j<dis;j++){
                wind[i][j]=read();
                dp[i][j]=1000000;
            }
        }
        for(int i=0;i<10;i++){
            dp[i][dis]=0;
        }
        dp[0][0]=0;
        /*.test
            putchar('\n');
            for(int j=0;j<10;j++){
                for(int k=0;k<dis;k++){
                    write(dp[j][k]);
                    putchar(' ');
                }
                putchar('\n');
            }
            putchar('\n');
            //test.*/
        for(int i=1;i<=dis;i++){
            dp[0][i]=dp[1][i-1]+20-wind[1][i-1];
            for(int j=1;j<9;j++){
                dp[j][i]=min(dp[j][i-1]+30-wind[j][i-1],min(dp[j-1][i-1]+60-wind[j-1][i-1],dp[j+1][i-1]+20-wind[j+1][i-1]));
            }
            dp[9][i]=min(dp[8][i-1]+60-wind[8][i-1],dp[9][i-1]+30);
            /*.test 
            putchar('\n');
            for(int j=0;j<10;j++){
                for(int k=0;k<dis;k++){
                    write(dp[j][k]);
                    putchar(' ');
                }
                putchar('\n');
            }
            putchar('\n');
            //test.*/
        }
        write(dp[0][dis]);
        putchar('\n');
        putchar('\n');
    }
    return 0;
}
