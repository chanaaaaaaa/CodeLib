#include <iostream>
#include <string>

using namespace std;

signed main(){
    int N;
    string S="";
    char c;
    bool f=false;

    cin>>N;
    for(int i=0;i<N;++i){
        cin>>c;
        if(!f && c!='o'){
            f=true;
            S+=c;
        }else if(f){
            S+=c;
        }
    }
    cout<<S<<'\n';
    return 0;
}
