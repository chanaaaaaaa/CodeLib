#include<bits/stdc++.h>

using namespace std;

int t,n,temp,mid,dis=0;


int main(){

    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>t;
    while(t--){

        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++){
            cin>>vec[i];
        }
        sort(vec.begin(),vec.end());
        mid= vec[(n-1)/2];

        for(int locate : vec){
            dis+=abs(locate-mid);
        }
        cout << dis;
    }

    return 0;
}
