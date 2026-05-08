#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

struct point{
    double x,y;
};
point p0;
vector<point>dat;

inline double disppo(point &p1,point &p2){
    return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
inline int orient(point &p,point &q,point &r){
    double val=(q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);

    if(val>0){
        return 1;
    }else if(val<0){
        return -1;
    }else{
        return 0;
    }
}
inline bool cmp(point &a,point &b){
    int o=orient(p0,a,b);
    if(o==0){
        return disppo(p0,a)<disppo(p0,b);
    }
    return o==1;
}
inline void hex(){
    int sz=dat.size();
    if(sz==1){
        printf("0.00\n");
        return;
    }
    if(sz==2){
        printf("%.2lf\n",2.0*sqrt(disppo(dat[0],dat[1])));
        return;
    }
    //get p0
    int minn=0;
    for(int i=1;i<sz;++i){
        if(dat[i].y<dat[minn].y){
            minn=i;
        }else if(dat[i].y==dat[minn].y && dat[i].x<dat[minn].x){
            minn=i;
        }
    }
    swap(dat[0],dat[minn]);
    p0=dat[0];
    sort(dat.begin()+1,dat.end(),cmp);

    int m=1;
    for(int i=1;i<sz;++i){
        while(i<sz-1 && orient(p0,dat[i],dat[i+1])==0){
            ++i;
        }
        dat[m]=dat[i];
        ++m;
    }
    //-clean bad points
    if(m==1){
        printf("0.00\n");
        return;
    }
    if(m==2){
        printf("%.2lf\n",2.0*sqrt(disppo(dat[0],dat[1])));
        return;
    }

    vector<point>spept;
    spept.push_back(dat[0]);
    spept.push_back(dat[1]);
    spept.push_back(dat[2]);
    for(int i=3;i<m;++i){
        while(spept.size()>1 && orient(spept[spept.size()-2],spept.back(),dat[i])!=1){
            spept.pop_back();
        }
        spept.push_back(dat[i]);
    }

    double res=0.0;
    for(int i=1;i<spept.size();++i){
        res+=sqrt(disppo(spept[i],spept[i-1]));
    }
    res+=sqrt(disppo(spept[0],spept.back()));
    printf("%.2lf\n",res);
    return;
}
int N;
signed main(){
    while(~scanf("%d",&N)){
        dat.assign(N,{});
        for(int i=0;i<N;++i){
            scanf("%lf %lf",&dat[i].x,&dat[i].y);
        }
        hex();
    }
    return 0;
}
