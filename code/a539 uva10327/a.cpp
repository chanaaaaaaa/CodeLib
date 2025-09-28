#include <bits/stdc++.h>
using namespace std;

int main(){
    int a;
    while(cin>>a){
        long aa[1000];
        int cou=0;
        for(int i=0;i<a;i++){
            cin>>aa[i];
        }
        for(int i=0;i<a-1;i++){
            for(int j=0;j<a-1;j++){
                if(aa[j]>aa[j+1]){
                    swap(aa[j],aa[j+1]);
                    cou++;
                }
            }
        }
        cout<<"Minimum exchange operations : "<<cou<<"\n";
    }
    return 0;
}
