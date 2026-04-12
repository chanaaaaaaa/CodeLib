#include <bits/stdc++.h>

using namespace std;


int main(){

    int cycle;
    cin >> cycle;
    for(int i=0;i<cycle;i++){
        int ron,con=0;
        int t[51];
        cin >> ron;
        for(int j=0;j<ron;j++){
            cin >> t[j];
        }
        for(int j=0;j<ron;j++){
            for(int g=j+1;g<ron;g++){
                if(t[j]>t[g]){
                    swap(t[j],t[g]);
                    con++;
                }
            }
        }
        cout <<"Optimal train swapping takes "<< con <<" swaps."<< "\n";
    }

    return 0;
}
