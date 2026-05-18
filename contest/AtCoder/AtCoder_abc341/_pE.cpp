#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <cstdio>

#define int long long
using namespace std;
//seg tree
inline int read(){
    int x=0,w=1,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
const int MAXN=5e5+10;
struct node{
    int L,R;
    bool val;
}seg[MAXN<<2];

bool arr[MAXN];
inline void build(int n,int L,int R){
    if(L==seg[n].L && R==seg[n].R){
        seg[n].val
    }
}
signed main(){

    return 0;
}

