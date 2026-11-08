#include <iostream>

#define int long long
using namespace std;

int N,n,k;

signed main(){
    while(cin>>N){
        if(N==0){break;}
        while(N--){

            int cnt_of_up=0;
            int cnt_of_dn=0;

            int cur_up_cnt=1;
            int cur_dn_cnt=1;


            int pre,cur;
            cin>>n>>k;
            cin>>pre;
            for(int i=1;i<n;++i){
                cin>>cur;

                if(pre>cur){
                    if(cur_up_cnt>=k && cur_up_cnt>1){++cnt_of_up;}
                    ++cur_dn_cnt;
                    cur_up_cnt=1;//
                }else if(pre<cur){
                    if(cur_dn_cnt>=k && cur_dn_cnt>1){++cnt_of_dn;}

                    ++cur_up_cnt;
                    cur_dn_cnt=1;//
                }else if(pre==cur){
                    if(cur_up_cnt>=k && cur_up_cnt>1){++cnt_of_up;}
                    if(cur_dn_cnt>=k && cur_dn_cnt>1){++cnt_of_dn;}
                    cur_dn_cnt=1;//
                    cur_up_cnt=1;//
                }

                //cout<<pre<<' '<<cur<<' '<<cur_up_cnt<<' '<<cur_dn_cnt<<'\n';

                pre=cur;
            }
            if(cur_up_cnt>=k && cur_up_cnt>1){++cnt_of_up;}
            if(cur_dn_cnt>=k && cur_dn_cnt>1){++cnt_of_dn;}
            //-input
            cout<<cnt_of_up<<' '<<cnt_of_dn<<'\n';
        }
    }
    return 0;
    /*
    2
    7 5
    9 8 7 7 6 5 4

    11 1
    1 2 3 4 3 4 5 6 7 6 5

    */
}
/*
2
11 3
1 2 3 4 3 4 5 6 7 6 5

6 5
9 8 7 6 5 4

*/
