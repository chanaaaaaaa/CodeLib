#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
inline char read_command(){
    char c=0,x=0;
    while(c<'A' || c>'Z'){
        c=getchar();
    }
    while(c>='A' && c<='Z'){
        if(!x){x=c;}
        c=getchar();
    }
    return x;
}
inline int read_judge(){
    char IN=read_command();
    if(IN=='S'){return 0;}
    if(IN=='E'){return 1;}
    if(IN=='D'){return -1;}
}
int T,N,command,Num,cases=0;
unordered_map<int,int>dat;
vector<int>sub;
int main(){
    while(T=read()){
        if(T==-1){break;}
        //-head
        for(int i=0;i<T;i++){
            N=read();
            for(int j=0;j<N;j++){
                dat[read()]=i;
            }
        }
        putchar('S');
        putchar('c');
        putchar('e');
        putchar('n');
        putchar('a');
        putchar('r');
        putchar('i');
        putchar('o');
        putchar(' ');
        putchar('#');
        write(++cases);
        putchar('\n');
        //-input&init
        while(command=read_judge()){
            if(command==1){
                Num=read();
                if(sub.size()==0){
                    sub.push_back(Num);
                }else{
                    for(int i=sub.size()-1;i>=0;i--){
                        if(dat[sub[i]]==dat[Num]){
                            sub.insert(sub.begin()+i+1,Num);
                            break;
                        }else if(i==0){sub.push_back(Num);}
                    }
                }
            }else{
                write(sub[0]);
                putchar('\n');
                sub.erase(sub.begin());
            }
        }
        vector<int>sv;swap(sub,sv);
        unordered_map<int,int>smp;swap(dat,smp);
    }
    return 0;
}
