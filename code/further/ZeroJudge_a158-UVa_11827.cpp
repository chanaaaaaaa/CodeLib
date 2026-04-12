#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int myGCD(int x,int y){
    while((x%=y)&&(y%=x));
    return x+y;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N,x,mx;
    string s;
    cin>>N;
    cin.ignore();
    while(N--){
        getline(cin,s);
        stringstream ss(s);
        vector<int>v;

        mx=0;
        while(ss>>x){
            v.push_back(x);
            for(int i=0;i<v.size()-1;i++){
                mx=max(mx,myGCD(x,v[i]));
            }
        }
        cout<<mx<<"\n";
    }
    return 0;
}
