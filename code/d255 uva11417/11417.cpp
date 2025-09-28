#include <bits/stdc++.h>
using namespace std;

int gc(int a, int b){
    while(b){
        int temp=a%b;
        a=b;
        b=temp;
    }
    return a;
}

int main(){
    while(true){
        int N;
        cin >> N;
        if(N==0){break;}
        int G=0;
        for(int i=1;i<N;i++){
            for(int j=i+1;j<=N;j++){
                G+=gc(i,j);
            }
        }
        cout << G <<"\n";
    }
    return 0;
}
