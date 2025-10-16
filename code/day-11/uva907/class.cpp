#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<iostream>
#include<vector>
#include<string>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0'&& c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline int read_command(){
    string IN;
    cin>>IN;
    if(IN=="ENQUEUE"){return 1;}
    if(IN=="DEQUEUE"){return -1;}
    if(IN=="STOP"){return 0;}
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//--block

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,cases=0;
    vector<vector<int>>dat(1000,vector<int>());
    while(N=read()){
        putchar('S');
        putchar('c');
        putchar('e');
        putchar('n');
        putchar('a');
        putchar('r');
        putchar('i');
        putchar('o');
        putchar(' ');
        putchar('#');
        write(++cases);
        putchar('\n');

        for(int i=0;i<N;i++){
            int T=read();
            for(int j=0;j<T;j++){
                dat[i].emplace_back(read());
            }
        }
        //-init&input
        //command
        int check=1;
        while(check=read_command()){
            if(check==1){
                int num=read();
            }else if(check==-1){

            }
        }
        putchar('\n');
    }
    return 0;
}
