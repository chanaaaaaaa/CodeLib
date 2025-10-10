#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<algorithm>
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
        x=x*10+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//--block

signed main(){
    int dat[605],N,K;
    while(N=read()){
        if(N==-1){break;}
        K=read();
        int left=0,right=0;
        for(int i=0;i<=N;i++){
            dat[i]=read();
            left=max(left,dat[i]);
            right+=dat[i];
        }
        //-input
        //do
        while(left!=right){
            int mid=(left+right)/2;
            int day=0,cnt=0;
            for(int i=0;i<=N;i++){
                if(cnt+dat[i]>mid){
                    cnt=dat[i];
                    day++;
                }else{cnt+=dat[i];}
            }
            if(cnt>0){day++;}
            if(day-1>K){left=mid+1;}
            else{right=mid;}
        }
        write(left);
        putchar('\n');
    }
    return 0;
}
