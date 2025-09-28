#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    cin.ignore();
    cin.ignore();
    while(N--){

        vector<string>li;

        string A;
        while(getline(cin,A)){
            if(A.empty()){break;}
            else{li.push_back(A);}
        }
        sort(li.begin(),li.end());

        if(li.size()==1){
            cout<<li[0]<<" "<<fixed<<setprecision(4)<<(((double)1/(double)li.size())*100)<<"\n";
        }

        int same=1;
        for(int i=0;i<li.size()-1;i++){
            if(same==1){
                cout<<li[i]<<" ";
            }
            if(li[i]==li[i+1]){
                same++;
            }else{
                cout<<fixed<<setprecision(4)<<(((double)same/(double)li.size())*100)<<"\n";
                same=1;
            }
            if(i==li.size()-2){
                if(same==1){
                    cout<<li[i+1]<<" "<<fixed<<setprecision(4)<<(((double)same/(double)li.size())*100)<<"\n";
                }else{
                    cout<<fixed<<setprecision(4)<<((((double)same)/(double)li.size())*100)<<"\n";
                }
            }
        }
        cout<<"\n";
    }
    return 0;
}
