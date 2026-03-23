#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
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
int N,dic[5]={50,25,10,5,1},dp[7500][7500];
inline int solve(int x,int last){
    if(dp[x][last]){return dp[x][last];}
    if(x==0 || last==4){return 1;}//

    int temp=0;
    if(x<dic[last]){
        return dp[x][last]=solve(x,last+1);
    }
    for(int i=0;x-dic[last]*i>=0;i++){
        temp+=solve(x-dic[last]*i,last+1);
    }
    return dp[x][last]=temp;
}
signed main(){
    while(true){
        N=read();
        if(N==-1){break;}
        write(solve(N,0));
        putchar('\n');
    }
    return 0;
}
