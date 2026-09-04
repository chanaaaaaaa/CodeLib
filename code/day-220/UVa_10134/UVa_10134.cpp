#include <iostream>
#include <string>

using namespace std;

int T;
signed main(){
    cin>>T;
    cin.ignore();
    cin.ignore();
    while(T--){
        int bait=0;
        int colddown=7;
        int tring=3;
        int cnt=0;
        string com;
        while(true){
            getline(cin,com);
            if(com==""){break;}

            if(com=="bait"){
                if(bait<3){
                    ++bait;
                }
                ++colddown;
            }
            if(com=="lunch"){
                ++colddown;
            }
            if(com=="fish"){
                if(bait>0 && colddown>=7 && tring>=3){
                    ++cnt;
                    colddown=0;
                    tring=0;
                    --bait;
                }else{
                    ++tring;
                    ++colddown;
                }
            }
            //cout<<"bait: "<<bait<<'\n';
            //cout<<"colddown: "<<colddown<<'\n';
            //cout<<"tring: "<<tring<<'\n';
            //cout<<"cnt: "<<cnt<<'\n';
        }
        cout<<cnt<<'\n';
        if(T){cout<<'\n';}
    }
    return 0;
}
/*
1

fish
fish
lunch
bait
fish
bait
fish
bait
bait
fish
fish
fish
fish
lunch
lunch
lunch
lunch
fish
fish
fish
*/
