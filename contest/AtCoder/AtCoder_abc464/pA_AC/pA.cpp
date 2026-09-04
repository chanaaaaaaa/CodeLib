#include <iostream>

using namespace std;

signed main(){
    string S;
    while(cin>>S){
        int cnt=0;
        for(char c:S){
            if(c=='E'){
                ++cnt;
            }else{
                --cnt;
            }
        }
        if(cnt>0){
            cout<<"East\n";
        }else{
            cout<<"West\n";
        }
    }
    return 0;
}
