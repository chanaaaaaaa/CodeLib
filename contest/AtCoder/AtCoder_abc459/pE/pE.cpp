#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
#include <queue>

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
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
    return;
}
//
inline int cal(int a,int b,int x,int y){
    if(a>b){swap(a,b);}
    if(x>y){swap(x,y);}

    return min(2*a*y,a*(x+y)+(b-a)*(y-x)/2);
}
signed main(){
    int N=read();
    while(N--){
        int a=read();
        int b=read();
        int x=read();
        int y=read();

        x=abs(x);y=abs(y);
        if((x+y)%2==1){
            write(min(cal(a,b,x-1,y)+a,cal(a,b,x,y-1)+b));
        }else{
            write(cal(a,b,x,y));
        }
        putchar('\n');
    }
    return 0;
}
