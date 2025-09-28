#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    while(N--){
        int s,d;
        cin>>s>>d;
        if(((((s&1)==1)&&((d&1)==1))||(((s&1)==0)&&((d&1)==0)))&&(s>=d)){
            cout<<(s+d)/2<<" "<<(s-d)/2<<"\n";
        }else{
            cout<<"impossible"<<"\n";
        }
    }
    return 0;
}
