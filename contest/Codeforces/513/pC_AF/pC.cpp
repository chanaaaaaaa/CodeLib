#include <iostream>
#include <memory.h>
#include <algorithm>

#define int long long
using namespace std;

const int MAXN=2005;

int A[MAXN],B[MAXN],dA[MAXN],dB[MAXN];

signed main(){
    int N,M,K;

    while(cin>>N>>M){

        for(int i=1;i<=N;++i){cin>>A[i];A[i]+=A[i-1];}
        for(int i=1;i<=M;++i){cin>>B[i];B[i]+=B[i-1];}
        cin>>K;

        memset(dA,0x3f,sizeof(dA));
        memset(dB,0x3f,sizeof(dB));

        for(int i=1;i<=N;++i){
            for(int j=i;j<=N;++j){
                dA[j-i+1]=min(dA[j-i+1],A[j]-A[i-1]);
            }
        }
        for(int i=1;i<=M;++i){
            for(int j=i;j<=M;++j){
                dB[j-i+1]=min(dB[j-i+1],B[j]-B[i-1]);
            }
        }
        //
        int res=0;
        for(int i=1;i<=N;++i){
            for(int j=1;j<=M;++j){
                //cout<<i<<' '<<j<<' '<<dA[i]*dB[j]<<'\n';
                if((dA[i]*dB[j])<=K){
                    res=max(i*j,res);
                }
            }
            //cout<<'\n';
        }
        cout<<res<<'\n';
    }
    return 0;
}
