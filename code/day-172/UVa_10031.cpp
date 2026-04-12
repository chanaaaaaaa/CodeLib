#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <string>
#include <math.h>

#define int long long
using namespace std;

vector<pair<int,int>>nodes;
string S;
int total_squares,max_y;
inline void addEdge(){
    int x=0,y=0;
    bool f=false;
    for(char &c:S){
        if(c==' '){f=true;}
        if(c<'0' || c>'9'){continue;}

        if(!f){
            x=(x<<3)+(x<<1)+c-'0';
        }else{
            y=(y<<3)+(y<<1)+c-'0';
        }
    }
    max_y=max(max_y,y);
    nodes.push_back({x,y});
}
inline void SweepLine(){
    for(int y=0;y<max_y;++y){
        vector<pair<double,pair<int,int>>>intersections;

        for(int i=0;i<nodes.size();++i){
            pair<int,int> st=nodes[i];
            pair<int,int> ed=nodes[(i+1)%nodes.size()];

            if(min(st.second,ed.second) <= y && max(st.second,ed.second) >= y+1){
                int dx=ed.first-st.first;
                int dy=ed.second-st.second;
                if(dy < 0){
                    dx=-dx;
                    dy=-dy;
                }

                int N_bottom=dx*(y-st.second);
                int N_top=dx*(y+1-st.second);

                int N_max=max(N_bottom,N_top);
                int N_min=min(N_bottom,N_top);

                int left_bound=st.first+(N_max>=0 ? (N_max+dy-1)/dy : N_max/dy);
                int right_bound=st.first+(N_min>=0 ? N_min/dy : (N_min-dy+1)/dy);

                double mid_x=(st.first+dx*(y*2+1-st.second*2)/(dy*2));

                intersections.push_back({mid_x,{left_bound,right_bound}});
            }
        }
        sort(intersections.begin(),intersections.end());

        for(int i=0;i<intersections.size();i+=2){
            int L_safe=intersections[i].second.first;
            int R_safe=intersections[i+1].second.second;

            if(L_safe < R_safe){
                total_squares+=(R_safe-L_safe);
            }
        }
    }
}
inline void solve(){
    nodes.clear();
    total_squares=0;
    max_y=0;
    while(getline(cin,S)){
        if(S==""){break;}
        addEdge();
    }
    SweepLine();
    cout<<total_squares<<'\n';
    return;
}
signed main(){
    int T;
    while(cin>>T){
        cin.ignore();
        cin.ignore();
        while(T--){
            solve();
            if(T){cout<<'\n';}
        }
    }
    return 0;
}
