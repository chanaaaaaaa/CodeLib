#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>al;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int in;
    cin>>in;
    al.push_back(in);
    cout<<al[0]<<"\n";

    while(cin>>in){
        for(int i=0;i<al.size();i++){
            if(in>=al[i]){
                al.insert(al.begin()+i,in);
                break;
            }else if(i==al.size()-1){
                al.push_back(in);
                break;
            }
        }
        if(al.size()%2==0){
            cout<<(al[al.size()/2]+al[al.size()/2-1])/2<<"\n";
        }else{
            cout<<al[(al.size()-1)/2]<<"\n";
        }
    }
    return 0;
}
