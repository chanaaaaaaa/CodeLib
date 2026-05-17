#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

signed main(){
    double N,X,T;
    cin>>N>>X>>T;

    cout<<fixed<<setprecision(0)<<ceil(N/X)*T<<'\n';
    return 0;
}
