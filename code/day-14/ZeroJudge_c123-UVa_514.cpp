#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0'&& c<='9'){
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
int N,temp;
queue<int>dat;
stack<int>wait;
inline bool solve(){
    for(int i=1;i<=N;i++){
        if(dat.front()==i){
            dat.pop();
        }else{
            while(!dat.empty() && !wait.empty() && dat.front()==wait.top()){
                dat.pop();
                wait.pop();
            }
            wait.push(i);
        }
    }
    while(!dat.empty() && !wait.empty() && dat.front()==wait.top()){
        dat.pop();
        wait.pop();
    }
    return (dat.empty() && wait.empty());
}
signed main(void){
    while(true){
        N=read(),temp;
        if(N==0){break;}
        while(true){
            for(int i=0;i<N;i++){
                temp=read();
                if(temp==0){break;}
                dat.push(temp);
            }
            if(temp==0){break;}
            //do
            if(solve()){
                putchar('Y');
                putchar('e');
                putchar('s');
            }else{
                putchar('N');
                putchar('o');
            }
            queue<int>empq;swap(empq,dat);
            stack<int>emps;swap(emps,wait);
            putchar('\n');
            //-do
        }
        putchar('\n');
    }
    return 0;
}
