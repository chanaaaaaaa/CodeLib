#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int N;
    string A;

    cin>>N>>A;
    if(N==1 && A.size()==1){
        cout<<"1\n";
        return 0;
    }
    vector<int>dat;
    int tmp=1;
    for(int i=1;i<A.size();i++){
        if(isupper(A[i])==isupper(A[i-1])){
            tmp++;
        }else{
            dat.push_back(tmp);
            tmp=1;
        }
    }
    if(tmp>1)dat.push_back(tmp);
    int Ans=0,now=0,head=-1;
    for(int i=0;i<dat.size();i++){
        if(dat[i]==N){
            now++;
            if(head==-1){head=i;}
        }else if(dat[i]>N){
            if(head==-1){
                now++;
                head=i;
            }else{
                now++;
                Ans=max(Ans,now);
                now=0;
                i--;
                head=-1;
            }
        }else{
            now=0;
        }
        //cout<<now<<" ";
        Ans=max(Ans,now);
    }
    cout<<Ans*N<<"\n";
    return 0;
}
