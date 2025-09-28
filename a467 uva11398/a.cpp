#include <bits/stdc++.h>
using namespace std;

int main(){
    long long Ans=0;
    int flag=0;
    string a;
    while(cin>>a){
        if(a=="~"){break;}

        if(a=="#"){
            cout<<Ans<<"\n";//reset
            Ans=0;
        }else{
            if(a.size()==1){
                flag=1;
            }else if(a.size()==2){
                flag=0;
            }else{
                for(int i=0;i<a.size()-2;i++){//位元左移 取代2轉10進
                    Ans*=2;
                    Ans+=flag;
                }
            }
        }
    }
    return 0;
}
