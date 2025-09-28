#include <bits/stdc++.h>
using namespace std;

int main(){
    string a;
    while(getline(cin,a)){
        int maxx=0,cou=0;
        for(int i=0;i<a.size();i++){
            if(a[i]==' '){
                cou++;
            }else{
                if(cou>maxx){maxx=cou;}
                cou=0;
            }
        }
        int time=0;
        while(maxx>1){
            if(maxx%2==0){
                maxx/=2;
            }else{
                maxx-=1;
                maxx/=2;
                maxx+=1;
            }
            time++;
        }
        cout<<time<<"\n";
    }
    return 0;
}
