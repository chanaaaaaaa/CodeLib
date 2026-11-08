#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

vector<pair<int,int>>dat;
int N;
signed main(){
    while(cin>>N){
        dat.assign(N,pair<int,int>());
        for(int i=0;i<N;++i){
            cin>>dat[i].first>>dat[i].second;
        }
        sort(dat.begin(),dat.end());

        int maxx=0;

        int head=-1,bottom=-1,cnt=-1;

        for(int i=0;i<dat.size();++i){
            int st=dat[i].first;
            int ed=dat[i].second;

            bool flag=false;

            if(bottom<st || ed<head){
                maxx=max(maxx,cnt);
                cnt=1;
                bottom=ed;
                head=st;

                continue;
            }

            if(head<=st && st<=bottom){
                if(!flag){++cnt;}
                flag=true;

                bottom=max(bottom,ed);
                head=min(st,head);
            }

            if(head<=ed && ed<=bottom){
                if(!flag){++cnt;}
                flag=true;

                bottom=max(bottom,ed);
                head=min(st,head);
            }

        }
        maxx=max(maxx,cnt);

        cout<<maxx<<'\n';
    }
    return 0;
}
/*
8
1 4
3 6
5 8
7 10
15 18
17 21
20 24
30 33
*/
/*
7
8 13
1 5
12 17
4 9
20 25
16 21
24 30
*/
