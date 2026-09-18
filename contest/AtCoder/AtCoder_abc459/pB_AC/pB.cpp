#include <iostream>
#include <vector>
using namespace std;

const int dat[26]={
    2,2,2,
    3,3,3,
    4,4,4,
    5,5,5,
    6,6,6,
    7,7,7,7,
    8,8,8,
    9,9,9,9
};

signed main(){
    int N;
    string S;
    while(cin>>N){
        while(N--){
            cin>>S;
            cout<<dat[S[0]-'a'];
        }
        cout<<'\n';
    }
    return 0;
}
