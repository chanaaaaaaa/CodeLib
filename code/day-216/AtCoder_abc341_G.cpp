#pragma GCC optimize("Ofast,unroll-loops,fast-math,no-stack-protector")
#include <iostream>
#include <iomanip>
#include <vector>

#define int long long
using namespace std;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N,tmp;
    cin>>N;
    int dat[N+1];
    dat[0]=0;
    for(int i=1;i<=N;++i){
        cin>>tmp;
        dat[i]=dat[i-1]+tmp;
    }

    vector<int>hull;
    vector<double>ans(N+1);

    for(int i=N;i>=0;--i){
        while(hull.size()>=2){
            int B=hull.back();
            int C=hull[hull.size()-2];

            if((dat[B]-dat[i])*(C-B)<=(dat[C]-dat[B])*(B-i)){
                hull.pop_back();
            }else{
                break;
            }
        }

        if(i<N){
            int las=hull.back();
            ans[i+1]=(double)(dat[las]-dat[i])/(las-i);
        }
        hull.push_back(i);
    }

    for(int i=1;i<=N;++i){
        cout<<fixed<<setprecision(8)<<ans[i]<<'\n';
    }
    return 0;
}
