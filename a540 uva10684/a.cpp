#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int a;
    while(cin>>a){
        if(a==0){break;}

        int N[10000];
        for(int i=0;i<a;i++){
            cin>>N[i];
        }
        int maxx=0;
        for(int i=0;i<a;i++){
            int cou=0;
            for(int j=i;j<a;j++){
                cou+=N[j];
                if(cou>maxx){maxx=cou;}
            }
        }
        if(maxx>0){
            cout<<"The maximum winning streak is "<<maxx<<"."<<"\n";
        }else{
            cout<<"Losing streak."<<"\n";
        }
    }
    return 0;
}
