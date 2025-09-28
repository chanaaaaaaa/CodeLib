#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int dat[9][5];

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    for(int i=0;i<9;i++){
        int N;
        cin>>N;
        for(int j=0;j<N;j++){
            string IN;
            cin>>IN;
            if(IN=="1B"){dat[i][j]=1;}
            else if(IN=="2B"){dat[i][j]=2;}
            else if(IN=="3B"){dat[i][j]=3;}
            else if(IN=="HR"){dat[i][j]=4;}
            else{dat[i][j]=0;}
        }
    }
    deque<int>lay;
    int EN,Ans=0,now=0;
    cin>>EN;
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            if(dat[j][i]==0){
                now++;
                //lay.push_front(-1);
                if(now%3==0 || EN==now){
                    for(int i=3;i<lay.size();i++){
                        Ans+=lay[i];
                    }
                    lay.clear();
                }
                if(EN==now){
                    cout<<Ans<<"\n";
                    break;
                }
            }else{
                lay.push_front(1);
                if(dat[j][i]>1){
                    for(int k=1;k<dat[j][i];k++){
                        lay.push_front(0);
                    }
                }
            }
        }
        if(EN==now)break;
    }
    return 0;
}
