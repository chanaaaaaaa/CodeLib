#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    for(int i=0;i<N;i++){
        int pre,get,sol,drunk=0;
        cin>>pre>>get>>sol;
        get+=pre;
        while(get>=sol){
            int temp=floor(get/sol);
            get-=sol*temp;
            drunk+=temp;
            get+=temp;
        }
        cout<<drunk<<"\n";
    }
}
