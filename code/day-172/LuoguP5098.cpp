#include <cstdio>
#include <vector>

using namespace std;

inline int read(){
    int x=0,w=1;
    char c=0;
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
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

struct node{
    int x,y;
    node(int _x,int _y):x(_x),y(_y) {}
};
inline int abs(int x){
    return x>0 ? x:-x;
}
inline int max(int &a,int &b){
    return a>b? a:b;
}
signed main(){
    int N,A,B,res;
    vector<node>cows;
    while(N=read()){
        res=0;
        cows.clear();
        while(N--){
            A=read();B=read();
            for(node &n:cows){
                res=max(res,abs(A-n.x)+abs(B-n.y));
            }
            cows.push_back({A,B});
        }
        write(res);
        putchar('\n');
    }
    return 0;
}
