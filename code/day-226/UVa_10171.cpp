#include <cstdio>
#include <vector>
#include <queue>

#define int long long
using namespace std;

inline int read(){
    int x=0,c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c>='A'&&c<='Z'){return c-'A';}
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
const int MAXN=1e16;

int N,a,f,u,v,w;
vector<vector<pair<int,int>>>yng;
vector<vector<pair<int,int>>>old;
vector<pair<int,int>>node;
signed main(){
    while(N=read()){
        yng.assign(26,{});
        old.assign(26,{});
        node.assign(26,{MAXN,MAXN});
        for(int i=0;i<N;++i){
            a=read();f=read();u=read();v=read();w=read();

            if(a=='Y'-'A'){
                if(f=='U'-'A'){
                    yng[u].push_back({v,w});
                }else{
                    yng[u].push_back({v,w});
                    yng[v].push_back({u,w});
                }
            }else{
                if(f=='U'-'A'){
                    old[u].push_back({v,w});
                }else{
                    old[u].push_back({v,w});
                    old[v].push_back({u,w});
                }
            }
        }
        int yng_st=read();
        int old_st=read();

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>PQ;
        PQ.push({0,yng_st});
        node[yng_st].first=0;
        while(!PQ.empty()){
            int cur=PQ.top().second;
            int wgt=PQ.top().first;
            PQ.pop();
            if(node[cur].first!=wgt){continue;}

            for(auto &nxt:yng[cur]){
                if(nxt.second+node[cur].first<node[nxt.first].first){
                    node[nxt.first].first=nxt.second+node[cur].first;
                    PQ.push({node[nxt.first].first,nxt.first});
                }
            }
        }

        PQ.push({0,old_st});
        node[old_st].second=0;
        while(!PQ.empty()){
            int cur=PQ.top().second;
            int wgt=PQ.top().first;
            PQ.pop();
            if(node[cur].second!=wgt){continue;}

            for(auto &nxt:old[cur]){
                if(nxt.second+node[cur].second<node[nxt.first].second){
                    node[nxt.first].second=nxt.second+node[cur].second;
                    PQ.push({node[nxt.first].second,nxt.first});
                }
            }
        }
//
        int maxx=0;
        for(int i=0;i<26;++i){
            //write(node[i].first);
            //putchar(' ');
            //write(node[i].second);
            //putchar('\n');
            if(node[i].first+node[i].second < node[maxx].first+node[maxx].second){
                maxx=i;
            }
        }
//
        if(node[maxx].first==MAXN || node[maxx].second==MAXN){
            putchar('Y');putchar('o');putchar('u');
            putchar(' ');
            putchar('w');putchar('i');putchar('l');putchar('l');
            putchar(' ');
            putchar('n');putchar('e');putchar('v');putchar('e');putchar('r');
            putchar(' ');
            putchar('m');putchar('e');putchar('e');putchar('t');
            putchar('.');
            putchar('\n');
        }else{
            write(node[maxx].first+node[maxx].second);
            for(int i=0;i<26;++i){
                if(node[i].first+node[i].second==node[maxx].first+node[maxx].second){
                    putchar(' ');
                    putchar(char('A'+i));
                }
            }
            putchar('\n');
        }

    }
    return 0;
}
