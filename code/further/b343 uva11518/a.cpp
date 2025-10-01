#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin>>N;
    while(N--){
        int n,m,l;
        int route[10000][2];
        cin>>n>>m>>l;
        for(int i=0;i<m;i++){
            cin>>route[i][0]>>route[i][1];
        }

        set<int>ed;
        for(int i=0;i<l;i++){
            int head;
            cin>>head;
            ed.insert(head);
        }

        int cou=0;
        int check=1;
        while(check!=cou){
            check=cou;
            for(int i=0;i<m;i++){
                if((ed.count(route[i][0]))&&(!ed.count(route[i][1]))){
                    //cout<<route[i][0]<<"->"<<route[i][1]<<"\n";
                    ed.insert(route[i][1]);
                    cou++;
                    route[i][0]=-1;
                    route[i][1]=-1;
                }
            }
        }
        cout<<cou+l<<"\n";
    }
    return 0;
}
