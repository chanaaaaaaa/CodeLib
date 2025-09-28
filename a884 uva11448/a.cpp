#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++){
        int check[2];
        check[0]=0;
        check[1]=0;
        string a;
        getline(cin,a);
        for(int j=0;j<a.size();j++){
            if(a[j]=='('){
                check[0]++;
            }else if(a[j]==')'){
                check[0]--;
            }else if(a[j]=='['){
                check[1]++;
            }else if(a[j]==']'){
                check[1]--;
            }
        }
        if(check[0]==0 && check[1]==0){
            cout<<"Yes"<<"\n";
        }else{
            cout<<"No"<<"\n";
        }
    }
}
