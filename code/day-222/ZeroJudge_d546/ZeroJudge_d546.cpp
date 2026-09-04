#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>

#define int long long
using namespace std;

int N,A;
vector<pair<int,int>>points;

pair<int,int>operator-(const pair<int,int>&a,const pair<int,int>&b){
    return {a.first-b.first,a.second-b.second};
}

inline int cross(const pair<int,int>&a,const pair<int,int>&b){
    return a.first*b.second-a.second*b.first;
}

inline int slove(){
    int res=0;
    sort(points.begin(),points.end());

    vector<pair<int,int>>hull;
    for(int i=0;i<2;++i){
        int t=hull.size();
        for(pair<int,int>&pt:points){
            bool f=true;
            while(hull.size()-t>=2 && cross(hull.back()-hull[hull.size()-2],pt-hull[hull.size()-2])<=0){
                if(f){
                    f=false;
                }else if(cross(hull.back()-hull[hull.size()-2],pt-hull[hull.size()-2])!=0){
                    res+=(abs(cross(hull.back()-hull[hull.size()-2],pt-hull[hull.size()-2]))/(A*2))+1;
                }
                hull.pop_back();
            }
            hull.push_back(pt);
        }
        hull.pop_back();
        reverse(points.begin(),points.end());
    }
    return res;
}

signed main(){
    while(cin>>N>>A){
        points.assign(N,pair<int,int>());
        for(int i=0;i<N;++i){
            cin>>points[i].first>>points[i].second;
        }
        if(N<=3){
            cout<<"0\n";
        }else{
            cout<<slove()<<'\n';
        }
    }
    return 0;
}
