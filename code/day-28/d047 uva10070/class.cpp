#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

inline void say(string x){
    for(int i=0;i<x.size();i++){
        putchar(x[i]);
    }
    putchar('\n');
}
signed main(){
    bool fir=true;
    while(true){
        vector<int>lib;
        char c=0;
        int cnt=-1;
        int check=0;
        while(c<'0'||c>'9'){
            c=getchar();
            if(c==-1){return 0;}
        }
        while(c>='0'&&c<='9'){
            lib.emplace_back(c-'0');
            cnt++;
            c=getchar();
        }
        if(fir){fir=false;}
        else{putchar('\n');}
        //ran
        int num=((lib[cnt-3]*10+lib[cnt-2])*10+lib[cnt-1])*10+lib[cnt];
        if((num%100!=0 && num%4==0)||(num%400==0)){
            say("This is leap year.");
            check=1;
        }
        //-ran
        //huluculu
        num=0;
        for(int i=0;i<lib.size();i++){
            num+=lib[i];
        }
        if(num%3==0 && (lib[cnt]==0 || lib[cnt]==5)){
            say("This is huluculu festival year.");
            if(!check){check=2;}
        }
        //-huluculu
        //Bulukulu
        num=0;
        for(int i=0;i<lib.size();i++){
            if(i%2==0){
                num+=lib[i];
            }else{
                num-=lib[i];
            }
        }
        if(num%11==0 && (lib[cnt]==0 || lib[cnt]==5) && check==1){
            say("This is bulukulu festival year.");
        }
        //-Bulukulu
        //ordinary
        if(!check){
            say("This is an ordinary year.");
        }
    }
    return 0;
}
