#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

signed main(){
    int X,Y,L,R,A,B,res;
    while(cin>>X>>Y>>L>>R>>A>>B){
        res=0;
        for(int i=A;i<=B-1;++i){
            if(L<=i && i<=R-1){
                res+=X;
            }else{
                res+=Y;
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
