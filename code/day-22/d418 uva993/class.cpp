//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return -1;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x*w;
}
inline void write(long long x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
vector<int>num;
signed main(){
    int T=read();
    while(T--){
        int N=read();
        if(N==0){
            putchar('0');
        }else if(N==1){
            putchar('1');
        }else{
            for(int i=9;i>=2;i--){
                if(N%i==0){
                    num.emplace_back(i);
                    N/=i;
                }
            }
            if(N!=1){
                write(-1);
            }else{
                sort(num.begin(),num.end());
                for(int &p:num){
                    write(p);
                }
            }
        }
        putchar('\n');
        num.clear();
    }
    return 0;
}
