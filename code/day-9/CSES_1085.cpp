#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
using namespace std;

inline long long read(){
    long long x=0;
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
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
// -block
long long r,p,res,step,tot=0,dat[200001];
//false->/2 true->res+=
inline bool IsValid(long long ans){
    if(ans>tot){return false;}

    long long cnt=0,op=1,idx=0;
    while(idx<r){
        if(dat[idx]>ans){return true;}
        if(cnt+dat[idx]>ans){
            cnt=dat[idx];
            op++;
        }else{
            cnt+=dat[idx];
        }
        idx++;
    }
    return op > p;
}

 signed main(){
    r=read(),p=read();

    for(int i=0;i<r;i++){
        dat[i]=read();
        tot+=dat[i];
    }

    res=0,step=1e18;
    while(step>0){
        if(IsValid(res+step)){
            res+=step;
        }else{step/=2;}
    }
    write(res+1);
    return 0;
 }
