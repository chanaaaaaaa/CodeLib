#pragma GCC optimize("Ofast")
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}

inline void write(int x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){
    int N=read(),K=read();
    vector<int>dat;
    dat.reserve(N);
    for(int i=0;i<N;++i){
        dat.emplace_back(read());
    }

    multiset<int>st;
    int cnt=0,L=0;

    for(int R=0;R<N;++R){
        while(true){
            auto it=st.lower_bound(dat[R]-K+1);

            if(it!=st.end() && *it<dat[R]+K){
                st.erase(st.find(dat[L]));
                ++L;
            }else{
                break;
            }
        }

        st.insert(dat[R]);

        cnt+=(R-L+1);
    }

    write(cnt);
    putchar('\n');
    return 0;
}
