#include <queue>
#include <cstdio>

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
}
//block
signed main(){
    int X,Q,A,B;
    while(X=read()){
        priority_queue<int>Ls;
        priority_queue<int,vector<int>,greater<int>>Rs;

        auto add=[&](int val){
            if(val<=Ls.top()){
                Ls.push(val);
            }else{
                Rs.push(val);
            }

            if(Ls.size()<Rs.size()+1){
                Ls.push(Rs.top());
                Rs.pop();
            }
            if(Ls.size()>Rs.size()+1){
                Rs.push(Ls.top());
                Ls.pop();
            }
        };

        Ls.push(X);
        Q=read();
        while(Q--){
            A=read();
            B=read();
            add(A);add(B);
            write(Ls.top());
            putchar('\n');
        }
    }
    return 0;
}
