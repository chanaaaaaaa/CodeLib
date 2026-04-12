#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N,con=1;
    while(cin>>N){
        long long maxx=0;
        int aa[N];
        for(int i=0;i<N;i++){
            cin>>aa[i];
        }
        for(int i=0;i<N;i++){
            long long temp=1;
            for(int j=i;j<N;j++){
                temp*=aa[j];
                if(temp>maxx){maxx=temp;}
            }
        }
        cout<<"Case #"<<con<<": The maximum product is "<<maxx<<"."<<"\n"<<"\n";
        con++;
    }
    return 0;
}
