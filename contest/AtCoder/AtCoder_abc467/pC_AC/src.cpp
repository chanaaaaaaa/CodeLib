#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

#define int long long
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
    return;
}

const int MAXN=2e5+10;

vector<int>A(MAXN,0);
vector<int>B(MAXN,0);
vector<int>C(MAXN,0);
vector<int>D(MAXN,0);

int N,M,cur_cost,slope;

signed main(){
    while(N=read()){
        M=read();
        for(int i=0;i<N;++i){A[i]=read();}
        for(int i=0;i<N-1;++i){B[i]=read();}

        C[0]=0;
        for(int i=1;i<N;++i){
            C[i]=B[i-1]-C[i-1];
        }

        cur_cost=0;
        slope=0;
        for(int i=0;i<N;++i){
            D[i]=((C[i]-A[i])%M+M)%M;
            cur_cost+=D[i];
            slope+=(i&1)?-1:1;
        }

        vector<pair<int,int>>events;
        for(int i=0;i<N;i+=2){
            int s=((M-1-D[i])%M+M)%M;
            events.push_back({s,-M});
        }
        for(int i=1;i<N;i+=2){
            int s=D[i]%M;
            events.push_back({s,M});
        }
        sort(events.begin(),events.end());

        int pin=0;
        for(int i=1;i<N;++i){
            if(events[i].first==events[pin].first){
                events[pin].second+=events[i].second;
            }else{
                ++pin;
                events[pin]=events[i];
            }
        }
        events.resize(pin+1);

        int cur_s=0,res=3e18;
        for(int i=0;i<events.size();++i){
            cur_cost+=(events[i].first-cur_s)*slope;
            res=min(res,cur_cost);
            cur_cost+=slope+events[i].second;
            cur_s=events[i].first+1;
            res=min(res,cur_cost);
        }
        if(cur_s<M){
            cur_cost+=(M-1-cur_s)*slope;
            res=min(res,cur_cost);
        }


        write(res);
        putchar('\n');
    }
    return 0;
}
