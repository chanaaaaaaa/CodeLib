#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<queue>
#include<stdio.h>
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

signed main(){
    int cases=1;
    while(true){
        queue<int>wait;
        vector<int>lib;
        vector<int>mp(10001,0);
        int L=read(),U=read(),R=read(),flag=0;
        if(L+U+R==0){return 0;}
        for(int i=0;i<R;i++){
            lib.push_back(read());
        }
        printf("Case ");
        write(cases);
        printf(": ");

        wait.push(L);
        mp[L]=1;
        while(!wait.empty()){
            for(int i=0;i<R;i++){
                int temp=(wait.front()+lib[i])%10000;
                if(temp==U){write(mp[wait.front()]);flag=1;break;}
                if(mp[temp]==0){
                    wait.push(temp);
                    mp[temp]=mp[wait.front()]+1;
                }
            }
            if(flag){break;}
            wait.pop();
        }
        if(wait.empty()){printf("Permanently Locked");}
        putchar('\n');
        cases++;
    }
    return 0;
}
