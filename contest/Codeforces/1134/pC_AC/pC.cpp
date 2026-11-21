#include <iostream>
#include <vector>
#include <algorithm>

#define int long long
using namespace std;


signed main(){
    int T,N;
    while(cin>>T){
        while(T--){
            cin>>N;
            vector<int>dat(N),res(N+2);
            for(int i=0;i<N;++i){
                cin>>dat[i];
            }
            sort(dat.begin(),dat.end());

            int pos=dat.size()-1;
            int Ls=(res.size()-1)/2-1;
            int Rs=(res.size()-1)/2+1;

            res[(res.size()-1)/2]=dat[pos];
            --pos;
            while(pos>=0){
                res[Ls]=dat[pos];
                --pos;--Ls;
                if(pos<0){break;}
                res[Rs]=dat[pos];
                --pos;++Rs;
            }
            int cnt=0;
            int maxx=0,posa=-1,posb=-1;
            for(int i=0;i<N+2;++i){
                if(res[i]>maxx){
                    ++cnt;
                    maxx=res[i];
                    posa=i;
                    //cout<<' '<<maxx<<'\n';
                }
            }

            maxx=0;
            for(int i=res.size()-1;i>=0;--i){
                if(res[i]>maxx){
                    ++cnt;
                    maxx=res[i];
                    posb=i;
                    //cout<<' '<<maxx<<'\n';
                }
            }
            if(posa==posb){--cnt;}
            cout<<cnt<<'\n';
            for(const int &k:res){
                if(k==0){continue;}
                cout<<k<<' ';
            }
            cout<<'\n';
        }
    }
    return 0;
}
