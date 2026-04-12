#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    cin.ignore();
    for(int i=1;i<=N;i++){
        int cou=0,k;
        string K;
        cin>>k>>K;

        for(int j=0;j<k;j++){
            if(K[j]=='.'){
                j+=2;
                cou++;
            }
        }

        cout<<"Case "<<i<<": "<<cou<<"\n";
    }

    return 0;
}
