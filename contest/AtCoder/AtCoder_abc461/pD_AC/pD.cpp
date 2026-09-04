#include <iostream>
#include <vector>

using namespace std;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N,M,K;
    cin>>N>>M>>K;
    vector<vector<int>>dat(N+1,vector<int>(M+1,0));
    char A;

    for(int i=1;i<=N;++i){
        for(int j=1;j<=M;++j){
            cin>>A;
            dat[i][j]=A-'0'+dat[i-1][j]+dat[i][j-1]-dat[i-1][j-1];
        }
    }

    long long res=0;
    int maxx=N*M;
    vector<int>cnt(maxx+1,0);
    vector<int>gen(maxx+1,0);
    int cur=0;

    for(int r1=1;r1<=N;++r1){
        for(int r2=r1;r2<=N;++r2){
            cur++;
            cnt[0]=1;
            gen[0]=cur;

            for(int c2=1;c2<=M;++c2){
                int val=dat[r2][c2]-dat[r1-1][c2];

                if(val>=K && gen[val-K]==cur){
                    res+=cnt[val-K];
                }

                if(gen[val]!=cur){
                    cnt[val]=0;
                    gen[val]=cur;
                }
                ++cnt[val];
            }
        }
    }

    cout << res << '\n';
    return 0;
}
