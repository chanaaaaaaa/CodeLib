#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N,K;
string S;
vector<int>dat;

inline bool check(double val){
    int Ls=0,Rs=0;
    while(Rs<=N){
        double cnt=dat[Rs]-dat[Ls];
        if(Ls==Rs){++Rs;continue;}
        if(cnt/(Rs-Ls)>=val && cnt>=K){return true;}

        if(cnt<K){
            ++Rs;
        }else{
            ++Ls;
        }
    }
    --Rs;
    while(Ls<Rs){
        double cnt=dat[Rs]-dat[Ls];
        if(cnt/(Rs-Ls)>=val && cnt>=K){return true;}

        ++Ls;
    }
    return false;
}

signed main(){
    while(cin>>N>>K>>S){
        dat.assign(N+1,0);

        for(int i=0;i<N;++i){
            dat[i+1]=dat[i]+(S[i]=='o'?1:0);
        }

        double Ls=0.0,Rs=1.0,mid;
        for(int i=0;i<80;++i){
            mid=Ls+(Rs-Ls)/2.0;

            if(check(mid)){
                Ls=mid;
            }else{
                Rs=mid;
            }
        }

        printf("%.9f\n",Ls);
    }
    return 0;
}
