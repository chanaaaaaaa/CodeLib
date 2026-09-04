#include <set>
#include <iostream>
#include <vector>
#include <utility>
/*
1948706013487601 48019760148910476 89014537
1948706013487601 539459753 89014537
21891997 539459753 89014537
21891997 6 89014537
0 6 89014537
0 0 89014537
*/
using namespace std;

signed main(){
    int T,res;
    long long X,Y,K;
    while(cin>>T){
        while(T--){
            res=0;
            cin>>X>>Y>>K;
            while(X!=Y){
                ++res;
                if(X>Y){
                    X/=K;
                }else{
                    Y/=K;
                }
            }
            cout<<res<<'\n';
        }
    }
    return 0;
}
