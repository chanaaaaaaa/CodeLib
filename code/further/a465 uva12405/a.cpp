#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    cin.ignore();
    for(int i=0;i<N;i++){
        int cou=0,k;
        string K;
        cin>>k>>K;

        for(int j=0;j<K.size();j++){
            if(K[j]=='.'){//直接在沃土右側插旗並跳過旗左右之檢查
                j+=2;
                cou++;
            }
        }

        cout<<"Case "<<i+1<<": "<<cou<<"\n";
    }

    return 0;
}
