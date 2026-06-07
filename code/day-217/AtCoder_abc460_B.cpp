#include <iostream>
#include <cmath>

#define int long long
using namespace std;

//-block
signed main(){
    int T;
    while(cin>>T){
        while(T--){
            long double x1,y1,r1,x2,y2,r2;
            cin>>x1>>y1>>r1;
            cin>>x2>>y2>>r2;
            long double dis=sqrt(abs(x1-x2)*abs(x1-x2)+abs(y1-y2)*abs(y1-y2));

            if(dis+r1==r2 || dis+r2==r1){
                cout<<"Yes\n";
            }else if(dis+r1<r2 || dis+r2<r1){
                cout<<"No\n";
            }else if(dis>r1+r2){
                cout<<"No\n";
            }else{
                cout<<"Yes\n";
            }
        }
    }
    putchar('\n');
    return 0;
}
