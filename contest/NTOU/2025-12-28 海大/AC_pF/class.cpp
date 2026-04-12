#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<iostream>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>

#define int long long
using namespace std;

int getCost(int from,int to){
    int diff=from-to;
    if(diff<0){diff=-diff;}
    return min(diff,10-diff);
}

int getCost3(int from,int to){
    return getCost(from/100,to/100)
          +getCost((from/10)%10,(to/10)%10)
          +getCost(from%10,to%10);
}

signed main(){
    string s;
    while(getline(cin,s) && s!=""){
        int start=0;
        while(start<s.length() && (s[start]<'0' || s[start]>'9')){++start;}
        if(start+8>=s.length()){continue;}

        int num1=(s[start+0]-'0')*100+(s[start+1]-'0')*10+(s[start+2]-'0'),
            num2=(s[start+4]-'0')*100+(s[start+5]-'0')*10+(s[start+6]-'0'),
            ans=(s[start+8]-'0');

        int res=INT_MAX;
        for(int abc=0;abc<=999;++abc){
            for(int def=1;def<=999;++def){
                int g=abc/def;
                if(g>9){continue;}
                res=min(res,getCost3(num1,abc)+getCost3(num2,def)+getCost(ans,g));
            }
        }
        cout<<res<<'\n';
    }
    return 0;
}
