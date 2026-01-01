#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;


struct Edge
{
    int u,v,w;
};
vector<Edge>edge;

const int MAXN=1e5+50;
int dis[MAXN], u, v, w;
constexpr int INF = 0x3f3f3f3f;

signed main(){
    int N,K;//point,edge
    while(cin>>N>>K){
        for(int i=0;i<K;++i){
            Edge tmp;
            cin>>tmp.u>>tmp.v>>tmp.w;
            edge.push_back(tmp);
        }
        //make super source : N
        for(int i=0;i<N;++i){
            Edge tmp;
            tmp.u=N;
            tmp.v=i;
            tmp.w=0;
            edge.push_back(tmp);
        }
        //-make super source : N
        memset(dis,0x3f,sizeof(dis));
        dis[N]=0;
        bool flag=false;
        for(int i=0;i<N;++i){
            flag=false;
            for(int j=0;j<edge.size();++j){
                u=edge[j].u;
                v=edge[j].v;
                w=edge[j].w;
                if(dis[u]==INF){continue;}

                if(dis[v]>dis[u]+w){
                    dis[v]=dis[u]+w;
                    flag=true;
                }
            }
            if(!flag) {
                break;
            }
        }
        cout<<flag<<'\n';
    }
    return 0;
}
