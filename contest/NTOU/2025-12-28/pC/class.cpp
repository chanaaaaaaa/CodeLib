#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

#define int long long
using namespace std;

signed main(){
    int n,x,y,t,x_f=-1,y_f=1,res;
    while(cin>>n>>x>>y>>t){
        res=0;
        while(t>0){
            int d=abs(x-1)+abs(y-n)+n/2;
            t-=d;
            x=d-abs(x-1);
            y=d-abs(y-n);
            ++res;
        }
        if(t<0){--res;}
        cout<<res<<'\n';
    }
    return 0;
}
//A - 2,1,2,3,2,1,2,3
//B - 5,6,5,4,5,6,5,4
//cnt-0,0,0,0,1,1,1,1
//t - 0,1,2,3,4,5,6,7

//A - 3,2,1,2,3,4 ,5,6,6
//B - 5,6,7,8,9,10,9,8,8
//cnt-0,0,0,0,0,0 ,0,0,1
//t - 0,1,2,3,4,5 ,6,7,8,9,10
