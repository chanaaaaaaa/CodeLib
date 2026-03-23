#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c>'9' || c<'0'){
        c=getchar();
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

// -block
int N;
bool flag;
inline void write_arr(vector<int>arr){
    if(flag){putchar('\n');}else{flag=true;}
    for(int i=0;i<arr.size();i++){
        if(i!=0){putchar(' ');}
        write(arr[i]);
    }
}

inline void solve(vector<int>dat,vector<int>pri,int now){
    pri.push_back(dat[now]);
    if(pri.size()==6){write_arr(pri);return;}
    for(int i=now+1;i<N;i++){
        solve(dat,pri,i);
    }
}
signed main(){
    while(N=read()){
        vector<int>dat(N);
        vector<int>pri;
        for(int i=0;i<N;i++){
            dat[i]=read();
        }
        for(int i=0;i<=N-6;i++){
            solve(dat,pri,i);
        }
        putchar('\n');
    }
    return 0;
}
