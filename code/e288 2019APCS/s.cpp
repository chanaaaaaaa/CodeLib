#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
using namespace std;

int m,n;
long long Ans=0;
string IN;
unordered_map<long long,long long>dat;

int dtm (char a){
    return a<='Z'?a-'A':a-'a'+26;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>m>>n;
    for(int i=0;i<n;i++){
        cin>>IN;
        long long temp=0;
        for(char c:IN)temp|=(long long)1<<(dtm(c));
        dat[temp]++;
    }
    auto it=dat.begin();
    while(it!=dat.end()){
        long long temp=(((long long)1<<m)-1)^(it->first);
        if(dat.find(temp)!=dat.end())Ans+=(it->second)*dat[temp];
        it++;
    }
    cout<<Ans/2<<"\n";
    return 0;
}
