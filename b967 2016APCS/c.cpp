#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>>dic;
int N,a,b,mi=-1,md=3;

void dfs(int idx,int father,int depth){
    for(auto i : dic[idx]){
        if(i!=father){
            dfs(i,idx,depth+1);
        }
    }
    if(depth>md){
        md=depth;
        mi=idx;
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>N;
    dic.assign(N,{});
    for(int i=1;i<N;i++){
        cin>>a>>b;
        dic[a].push_back(b);
        dic[b].push_back(a);
    }
    dfs(0,-1,0);
    dfs(mi,-1,0);
    cout<<md<<"\n";
    return 0;
}
