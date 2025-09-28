#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

string dict = "cdefgabCDEFGAB";
int fin[14][10]={
    {0,1,1,1,0,0,1,1,1,1},{0,1,1,1,0,0,1,1,1,0},
    {0,1,1,1,0,0,1,1,0,0},{0,1,1,1,0,0,1,0,0,0},
    {0,1,1,1,0,0,0,0,0,0},{0,1,1,0,0,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0},
    {1,1,1,1,0,0,1,1,1,0},{1,1,1,1,0,0,1,1,0,0},
    {1,1,1,1,0,0,1,0,0,0},{1,1,1,1,0,0,0,0,0,0},
    {1,1,1,0,0,0,0,0,0,0},{1,1,0,0,0,0,0,0,0,0}
};
int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    cin>>N;
    cin.ignore();
    while(N--){
        vector<int>dat(10,0);
        int last=-1;
        string in;
        getline(cin,in);
        for(int i=0;i<in.size();i++){
            for(int j=0;j<14;j++){
                if(in[i]==dict[j]){
                    if(last==-1){
                        for(int k=0;k<10;k++){
                            if(fin[j][k]==1){
                                dat[k]++;
                            }
                            last=j;
                        }
                    }else{
                        for(int k=0;k<10;k++){
                            if(fin[j][k]==1 && fin[last][k]==0){
                                dat[k]++;
                            }
                        }
                        last=j;
                    }
                    break;
                }
            }
        }
        for(int i=0;i<10;i++){
            cout<<dat[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
