#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<string>
#include<algorithm>
#define int long long
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
    }
    while(c>='0'&& c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
inline void say(string x){
    for(int i=0;i<x.size();i++){
        putchar(x[i]);
    }
}
signed main(){
    int t=read(),cases=0;
    while(t--){
        int n[3];
        for(int i=0;i<3;i++){
            n[i]=read();
        }
        sort(n,n+3);

        say("Case ");
        write(++cases);
        say(": ");
        if(n[2]>=n[1]+n[0] || n[2]<=0 || n[1]<=0 || n[0]<=0){
            say("Invalid");
        }else if(n[2]==n[1] && n[1]==n[0]){
            say("Equilateral");
        }else if(n[2]==n[1] || n[1]==n[0] || n[0]==n[2]){
            say("Isosceles");
        }else{
            say("Scalene");
        }
        putchar('\n');
    }
    return 0;
}
