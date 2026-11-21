#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

#define int long long
using namespace std;

vector<int>h;
int T,N,k;

inline bool check(int D){
    int N=h.size();
    int R=N/2;
    int M=2*N;
    vector<int>A(M);
    for(int i=0;i<M;++i){
        A[i]=h[i%N];
    }

    auto ApD=[&](int j){return A[j]+D*j;};
    auto AmD=[&](int j){return A[j]-D*j;};

    deque<int>dqL,dqR;
    for(int j=0;j<=R;++j){
        while(!dqL.empty() && ApD(dqL.back())<=ApD(j)){dqL.pop_back();}
        dqL.push_back(j);
    }
    for(int j=R;j<=R+R;++j){
        while(!dqR.empty() && AmD(dqR.back())<=AmD(j)){dqR.pop_back();}
        dqR.push_back(j);
    }

    int cost=0;
    for(int i=R;i<R+N;++i){
        if(i>R){
            while(!dqL.empty() && dqL.front()<i-R){dqL.pop_front();}
            while(!dqL.empty() && ApD(dqL.back())<=ApD(i)){dqL.pop_back();}
            dqL.push_back(i);

            while(!dqR.empty() && dqR.front()<i){dqR.pop_front();}
            while(!dqR.empty() && AmD(dqR.back())<=AmD(i+R)){dqR.pop_back();}
            dqR.push_back(i+R);
        }
        int L=max(ApD(dqL.front())-D*i,AmD(dqR.front())+D*i);
        cost+=L-h[i%N];
        if(cost>k){return false;}
    }
    return true;
}

signed main(){
    while(cin>>T){
        while(T--){
            cin>>N>>k;
            h.assign(N,0);
            for(int i=0;i<N;++i){
                cin>>h[i];
            }

            int Rs=0;
            for(int i=0;i<N;++i){
                Rs=max(Rs,abs(h[i]-h[(i+1)%N]));
            }

            int Ls=0,res=Rs;
            while(Ls<=Rs){
                int mid=(Ls+Rs)/2;
                if(check(mid)){
                    res=mid;
                    Rs=mid-1;
                }else{
                    Ls=mid+1;
                }
            }
            cout<<res<<'\n';
        }
    }
    return 0;
}
