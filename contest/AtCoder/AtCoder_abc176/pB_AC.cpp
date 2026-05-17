#include <iostream>
#include <string>

using namespace std;


signed main(){
    string S;
    cin>>S;
    int res=0;

    for(char &c:S){
        res+=c-'0';
        res%=9;
    }
    if(res){
        cout<<"No\n";
    }else{
        cout<<"Yes\n";
    }
    return 0;
}
