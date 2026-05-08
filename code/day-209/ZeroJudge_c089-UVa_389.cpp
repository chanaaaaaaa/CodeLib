#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

signed main(){
    string S;
    int now,tar;
    while(cin>>S>>now>>tar){
        int val=0,tmp=1;

        for(int i=S.size()-1;i>=0;--i){
            if(S[i]>='0' && S[i]<='9'){
                val+=(S[i]-'0')*tmp;
            }else{
                val+=(S[i]-'A'+10)*tmp;
            }
            tmp*=now;
        }

        S="";
        if(val){
            while(val>0){
                int r=val%tar;
                if(r<=9){
                    S+=char('0'+r);
                }else{
                    S+=char('A'+r-10);
                }
                val/=tar;
            }
            reverse(S.begin(),S.end());
        }else{
            S="0";
        }

        if(S.size()>7){
            cout<<setw(7)<<"ERROR"<<'\n';
        }else{
            cout<<setw(7)<<S<<'\n';
        }
    }
    return 0;
}
