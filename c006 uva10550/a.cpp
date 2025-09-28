#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a,b,c,d;
    while(cin>>a>>b>>c>>d){
        int deg=0;
        if(a+b+c+d==0){break;}
        deg+=40*3;

        if(b>=a){deg+=40-(b-a);}
        else{deg+=(a-b);}

        if(b>=c){deg+=40-(b-c);}
        else{deg+=(c-b);}

        if(d>=c){deg+=40-(d-c);}
        else{deg+=(c-d);}

        cout<<deg*9<<"\n";
    }
    return 0;
}
