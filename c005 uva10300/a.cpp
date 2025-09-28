#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    while(N--){
        int n;
        unsigned long long Ans=0;
        cin>>n;
        while(n--){
            unsigned long long a,b,c;
            cin>>a>>b>>c;
            Ans+=a*c;
        }
        cout<<Ans<<"\n";
    }
    return 0;
}
