#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        int head=0,bottom=0;
        for(int j=0;j<4;j++){
            int in,hh;
            cin>>in;
            bottom+=((in-(in/1000)*1000)/100)+((in-(in/10)*10));
            hh=2*(in/1000);
            if(hh>=10){hh-=9;}
            head+=hh;
            hh=2*((in-(in/100)*100)/10);
            if(hh>=10){hh-=9;}
            head+=hh;
        }
        if((head+bottom)%10==0){
            cout<<"Valid"<<"\n";
        }else{
            cout<<"Invalid"<<"\n";
        }
    }
    return 0;
}
