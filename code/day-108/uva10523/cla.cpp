#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("fast-math")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-ferun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-function-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool stop;

int big_divide(string &n,int d) {
    string quotient;
    quotient.reserve(n.size());
    int remainder=0;

    for(char &c:n){
        int current=remainder*10+(c-'0');
        quotient+=(current/d)+'0';
        remainder=current%d;
    }

    size_t start_pos=quotient.find_first_not_of('0');
    if(start_pos!=string::npos){
        n=quotient.substr(start_pos);
    }else{
        n="0";
    }
    return remainder;
}

void solve(string n) {
    if(n=="-1"){
        stop=true;
        return;
    }
    if(n.size()==1){
        cout<<'1'<<n;
        return;
    }

    vector<int>result_digits;

    for(int i=9; i>=2;--i){
        while(n!="1"){
            string tempN=n;
            int r=big_divide(tempN,i);

            if(r==0){
                n=tempN;
                result_digits.push_back(i);
            }else{
                break;
            }
        }
    }

    if(n!="1") {
        cout << "There is no such number.";
    }else{
        for(int i=result_digits.size()-1;i>= 0;--i){
            cout<<result_digits[i];
        }
    }
    return;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    string N;
    while(cin>>N){
        solve(N);
        if(stop){break;}
        cout<<"\n";
    }
    return 0;
}
