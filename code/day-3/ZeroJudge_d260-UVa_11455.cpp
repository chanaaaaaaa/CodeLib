#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<string>
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
inline void say(string x){
    for(int i=0;i<x.size();i++){
        putchar(x[i]);
    }
}
// -block

signed main(){
    int t=read();
    while(t--){
        int dat[4];
        for(int i=0;i<4;i++){
            dat[i]=read();
        }
        sort(dat,dat+4);

        if(dat[0]==dat[1] && dat[1]==dat[2] && dat[2]==dat[3]){
            say("square");
        }else if(dat[0]==dat[1] && dat[2]==dat[3]){
            say("rectangle");
        }else if(dat[0]+dat[1]+dat[2] > dat[3]){
            say("quadrangle");
        }else{
            say("banana");
        }
        putchar('\n');
    }
    return 0;
}
