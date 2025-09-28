#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int ron;
    cin >> ron;
    for(int i=1;i<=ron;i++){
        char rss[10][101];
        int point[10];
        for(int j=0;j<10;j++){
            string in;
            cin >> in >> point[j];
            int g;
            for(g=0;g<in.size();g++){
                rss[j][g]=in[g];
            }
            rss[j][g]='\0';
        }
        int maxx=0;
        for(int j=0;j<10;j++){
            if(maxx<point[j]){maxx=point[j];}
        }
        cout <<"Case #"<<i<<":"<<"\n";
        for(int j=0;j<10;j++){
            if(point[j]==maxx){
                cout << rss[j] <<"\n";
            }
        }
    }
    return 0;
}
