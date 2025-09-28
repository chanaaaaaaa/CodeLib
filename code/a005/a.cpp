#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    cin >> num;
    for(int i=0;i<num;i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if(a+c==b*2){
            cout <<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d+c-b;
        }else{
            cout <<a<<" "<<b<<" "<<c<<" "<<d<<" "<<d*c/b;
        }
        cout << "\n";
    }
    return 0;
}
