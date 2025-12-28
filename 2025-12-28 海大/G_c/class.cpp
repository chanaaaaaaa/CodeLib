#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
#include<cstring>

#define int long long
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block

int n,m,q;
vector<vector<vector<int>>>h;
int d[3][6]={
            {1,-1,0,0,0,0},
            {0,0,1,-1,0,0},
            {0,0,0,0,1,-1}
};

bool canReach(int maxCost) {
    vector<vector<vector<bool>>> visited(q,vector<vector<bool>>(m,vector<bool>(n,false)));
    queue<pair<pair<int,int>,int>> Q;

    Q.push({{0,0},0});//(0, 0, 0)->(1, 1, 1)
    visited[0][0][0]=true;

    while(!Q.empty()){
        auto [pos,k]=Q.front();
        int i=pos.first,j=pos.second;
        Q.pop();

        if(i==n-1 && j==m-1 && k==q-1){
            return true;//fin
        }

        for(int f=0;f<6;++f){
            int ni=i+d[0][f],
                nj=j+d[1][f],
                nk=k+d[2][f];

            if(ni<0 || ni>=n || nj<0 || nj>=m || nk<0 || nk>=q || visited[nk][nj][ni]) {
                continue;
            }

            if(abs(h[k][j][i]-h[nk][nj][ni])+2*abs(k-nk)<=maxCost){
                visited[nk][nj][ni]=true;
                Q.push({{ni,nj},nk});
            }
        }
    }

    return false;
}

signed main(){
    while(n=read()){

        m=read();q=read();
        h.clear();
        h.assign(q,vector<vector<int>>(m,vector<int>(n,0)));
        for(int k=0;k<q;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<m;++j){
                    h[k][j][i]=read();
                }
            }
        }

        int left=0,right=2e9+10;
        int ans=right;

        while(left<=right) {
            int mid=left+(right-left)/2;
            if(canReach(mid)) {
                ans=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }

        write(ans);
        putchar('\n');
    }
    return 0;
}
