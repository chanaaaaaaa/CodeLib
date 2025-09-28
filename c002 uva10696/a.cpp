#include <iostream>
using namespace std;

int f91(int a){
    if(a>=101){
        return a-10;
    }
    else{
        return f91(f91(a+11));
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    while(cin>>N){
        if(N==0){break;}
        cout<<"f91("<<N<<") = "<<f91(N)<<"\n";
    }
    return 0;
}
