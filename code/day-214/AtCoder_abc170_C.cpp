#include <cstdio>
#include <unordered_set>

using namespace std;

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

signed main(){
    unordered_set<int>st;
    int K=read();
    int N=read();
    for(int i=0;i<N;++i){
        st.insert(read());
    }

    if(!st.count(K)){
        write(K);
        putchar('\n');
    }else{
        int dis=1;
        while(true){
            if(!st.count(K-dis)){
                write(K-dis);
                putchar('\n');
                break;
            }else if(!st.count(K+dis)){
                write(K+dis);
                putchar('\n');
                break;
            }
            ++dis;
        }
    }

    return 0;
}
#
