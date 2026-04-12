#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<deque>
#include<iostream>
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

int main(void){
    int n=read(),m=read(),k=read(),Ans=0;
    vector<deque<char>>dat(n,deque<char>());
    char c;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            c=getchar();
            dat[i].push_back(c);
        }
        c=getchar();
    }
    while(k--){
        for(int i=0;i<n;i++){
            int temp=read();
            if(temp>0){
                for(;0<temp;temp--){
                    dat[i].push_front(dat[i][m-1]);
                    dat[i].pop_back();
                }
            }else if(temp<0){
                for(;temp<0;temp++){
                    dat[i].push_back(dat[i][0]);
                    dat[i].pop_front();
                }
            }
        }
        for(int i=0;i<m;i++){
            int con[26]={0},maxx=0;
            for(int j=0;j<n;j++){
                con[dat[j][i]-'a']++;
                if(con[dat[j][i]-'a']>maxx){maxx=con[dat[j][i]-'a'];}
            }
            Ans+=maxx;
        }
    }
    write(Ans);
}
