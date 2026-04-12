#include<bits/stdc++.h>

using namespace std;

int a,temp;
int n[3000];


int main(){
    while(cin>>a){
        set<int>s;
        for(int i=0;i<a;i++){
            cin >> n[i];
        }

        for(int i=0;i<a-1;i++){
            temp=abs(n[i]-n[i+1]);
            if(temp<a && temp!=0){s.insert(temp);}
        }

        if(s.size()==a-1){
            cout << "Jolly" <<"\n";
        }else{
            cout << "Not jolly" <<"\n";
        }
    }

    return 0;
}
