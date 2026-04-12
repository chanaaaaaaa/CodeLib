#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

//-block
double p,q,r,s,t,u;

static inline double f(double x){
    return p * exp(-x)
         + q * sin(x)
         + r * cos(x)
         + s * tan(x)
         + t * x * x
         + u;
}

signed main(){
    while(cin>>p>>q>>r>>s>>t>>u){
        double lo=0.0,hi=1.0;
        double flo=f(lo),fhi=f(hi);

        if(flo==0.0){
            cout<<fixed<<setprecision(4)<<0.0<<'\n';
            continue;
        }
        if(fhi==0.0){
            cout<<fixed<<setprecision(4)<<1.0<<'\n';
            continue;
        }

        if(flo*fhi>0.0){
            cout<<"No solution\n";
            continue;
        }

        for(int i=0;i<80;i++){
            double mid=(lo+hi)/2.0;
            double fmid=f(mid);
            if(flo*fmid<=0.0){
                hi=mid;
                fhi=fmid;
            }else{
                lo=mid;
                flo=fmid;
            }
        }

        cout<<fixed<<setprecision(4)<<((lo+hi)/2.0)<<'\n';
    }
    return 0;
}
