#include <bits/stdc++.h>
using namespace std;

int main(){

    string a;
    while(cin>>a){
        if(a=="."){break;}
        int maxx,out=0;
        for(int i=1;i<=a.size();i++){
            if(a.size()%i==0){
                for(int j=0;j<a.size();j++){
                    if(a[j]!=a[j%i]){break;}
                    else if(j+1==a.size()){out=i;break;}
                }
            }
            if(out!=0){break;}
        }
        cout<<a.size()/out<<"\n";
    }
    return 0;
}
