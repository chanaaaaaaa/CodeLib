#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    while(cin>>N){
        set<int>mid;
        vector<int>data;
        while(N--){
            int temp;
            cin>>temp;
            data.push_back(temp);
        }
        sort(data.begin(),data.end());
        //Q1
        int Ans;
        if((data.size() & 1)==1){
            Ans=data[(data.size()-1)/2];
            mid.insert(Ans);
        }else{
            Ans=data[data.size()/2-1];
            mid.insert(Ans);
            mid.insert(data[data.size()/2]);
        }
        cout<<Ans<<" ";
        //Q2
        Ans=0;
        for(int i=0;i<data.size();i++){
            if(mid.count(data[i])){
                Ans++;
            }
        }
        cout<<Ans<<" ";
        //Q3
        if((data.size() & 1)==1){
            cout<<"1"<<"\n";
        }else{
            cout<<data[data.size()/2]-data[data.size()/2-1]+1<<"\n";
        }
    }
    return 0;
}
