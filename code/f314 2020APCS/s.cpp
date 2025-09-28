#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

int M,N,Ans=-2147483648;
int mp[10000][3];//0->PreAns;1->LeftToRight;2->RightToLeft
int ar[10000];//NowInput

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        if(c=='-') w=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){

    M=read();
    N=read();

    while(M--){
        for(int j=0;j<N;j++){
            ar[j]=read();
        }
        mp[0][1]=ar[0]+mp[0][0];
        mp[N-1][2]=ar[N-1]+mp[N-1][0];
        mp[N-2][2]=max(mp[N-1][2],mp[N-2][0])+ar[N-2];
        for(int j=1;j<N-1;j++){
            mp[j][1]=max(mp[j-1][1],mp[j][0])+ar[j];
            mp[N-j-2][2]=max(mp[N-j-1][2],mp[N-j-2][0])+ar[N-j-2];
        }
        mp[N-1][1]=max(mp[N-2][1],mp[N-1][0])+ar[N-1];

        if(M==0){
            for(int j=0;j<N;j++){
                Ans=max(Ans,max(mp[j][1],mp[j][2]));
            }
        }else{
            for(int j=0;j<N;j++){
                mp[j][0]=max(mp[j][1],mp[j][2]);
            }
        }
    }
    write(Ans);
    return 0;
}
