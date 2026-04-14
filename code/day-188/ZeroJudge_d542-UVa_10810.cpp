#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <cstdio>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//-block
const int MAXN=5e6;

int num[MAXN];

inline void mergesort(int Ls,int Rs,int &sp){
    static int StArr[MAXN];
    if(Ls==Rs){return;}

    int mid=(Ls+Rs)>>1;
    int st1=Ls,ed1=mid;
    int st2=mid+1,ed2=Rs;
    mergesort(st1,ed1,sp);
    mergesort(st2,ed2,sp);

    int idx=Ls;
    while(st1<=ed1 && st2<=ed2){
        if(num[st1]<=num[st2]){
            StArr[idx++]=num[st1++];
        }else{
            StArr[idx++]=num[st2++];
            sp+=ed1-st1+1;
        }
    }
    while(st1<=ed1){
        StArr[idx++]=num[st1++];
    }
    while(st2<=ed2){
        StArr[idx++]=num[st2++];
    }
    for(int i=Ls;i<=Rs;++i){
        num[i]=StArr[i];
    }
    return;
}

signed main(){
    int N,res;
    while(N=read()){
        for(int i=0;i<N;++i){
            num[i]=read();
        }

        res=0;
        mergesort(0,N-1,res);
        
        write(res);
        putchar('\n');
    }
    return 0;
}