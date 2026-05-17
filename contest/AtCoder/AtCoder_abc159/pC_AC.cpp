#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

signed main(){
    double N;
    cin>>N;
    N/=3;

    cout<<fixed<<setprecision(12)<<N*N*N<<'\n';

    return 0;
}
