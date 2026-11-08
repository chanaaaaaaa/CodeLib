#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>cnt;
vector<vector<int>>to;
int N,M,A,B;

inline bool better(const int &x,const int &y){
    if(cnt[x]!=cnt[y]){return cnt[x]>cnt[y];}
    return x<y;
};
signed main(){
    while(cin>>N>>M){
        cnt.assign(N+1,0);
        to.assign(N+1,vector<int>());
        for(int i=0;i<M;++i){
            cin>>A>>B;
            ++cnt[A];
            to[A].push_back(B);
        }

        int top1=1,top2=2;
        for(int i=1;i<=N;++i){
            if(better(i,top1)){
                top2=top1;
                top1=i;
            }else if(i!=top1&&better(i,top2)){
                top2=i;
            }
        }

        for(int k=1;k<=N;++k){
            int base;
            if(k==top1){base=top2;}else{base=top1;}
            int best=base,bestv=cnt[base];

            auto &v=to[k];
            sort(v.begin(),v.end());
            for(int i=0;i<(int)v.size();){
                int j=i;
                while(j<v.size() && v[j]==v[i]){++j;}
                int x=v[i],tv=cnt[x]+(j-i);
                if(tv>bestv || (tv==bestv && x<best)){
                    bestv=tv;
                    best=x;
                }
                i=j;
            }
            cout<<best<<'\n';
        }
    }
    return 0;
}
