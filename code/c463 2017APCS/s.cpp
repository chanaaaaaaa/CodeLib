#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;
int N,n,b;
long long Ans=0;
vector<vector<int>>dat;
vector<int>far;
unordered_set<int>st;

void dfs(int id,int depth){
    if(dat[id].size()==0){
        far[id]=depth;
    }
    for(int v:dat[id]){
        dfs(v,depth+1);
        far[id]=max(far[id],far[v]);
    }
    Ans+=far[id]-depth;
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>N;
    dat.assign(N+1,{});
    far.assign(N+1,0);
    for(int i=1;i<=N;i++)st.insert(i);
    for(int i=1;i<=N;i++){
        cin>>n;
        while(n--){
            cin>>b;
            st.erase(b);
            dat[i].push_back(b);
        }
    }
    dfs(*st.begin(),0);
    cout<<*st.begin()<<"\n"<<Ans;
    return 0;
}
