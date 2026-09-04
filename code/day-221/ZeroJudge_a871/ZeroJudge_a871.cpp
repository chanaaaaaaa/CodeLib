#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>
#include <cmath>

using namespace std;

int N;
vector<pair<float,float>>points;

pair<float,float> operator-(const pair<float,float>&a,const pair<float,float>&b){
    return {a.first-b.first,a.second-b.second};
}
float cross(const pair<float,float>&a,const pair<float,float>&b){
    return a.first*b.second-a.second*b.first;
}
inline float slove(){
    sort(points.begin(),points.end());

    vector<pair<float,float>>hull;

    for(int i=0;i<2;++i){
        int t=hull.size();
        for(pair<float,float> &pt:points){
            while(hull.size()-t>=2 && cross(hull.back()-hull[hull.size()-2],pt-hull[hull.size()-2])<=0){
                hull.pop_back();
            }
            hull.push_back(pt);
        }
        hull.pop_back();
        reverse(points.begin(),points.end());
    }
    points.assign(hull.begin(),hull.end());

    float res=0.0;
    N=points.size();
    points.push_back(points[0]);


    for(int i=0;i<N;++i){
        //printf("%f %f ",points[i].first,points[i].second);
        res+=points[i].first*points[i+1].second-points[i+1].first*points[i].second;
        //printf("%f\n",res);
    }
    return res*0.5;
}

signed main(){
    int N;
    while(cin>>N){
        points.clear();
        for(int i=0;i<N;++i){
            float x,y;
            cin>>x>>y;
            points.push_back({x,y});
        }
        cout<<fixed<<setprecision(2)<<slove()<<'\n';
    }
    return 0;
}
