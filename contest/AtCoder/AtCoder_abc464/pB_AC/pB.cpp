#include <iostream>

using namespace std;

int H,W;
const int MAXN=55;
char mp[MAXN][MAXN];

signed main(){
    while(cin>>H>>W){
        int h=0,w=0;
        for(int i=0;i<H;++i){
            cin>>mp[i];
        }
        bool f=true;
        for(int i=0;i<H && f;++i){
            for(int j=0;j<W && f;++j){
                if(mp[i][j]=='#'){
                    h=i;
                    f=false;
                }
            }
        }
        f=true;
        for(int i=H-1;i>=0 && f;--i){
            for(int j=0;j<W && f;++j){
                if(mp[i][j]=='#'){
                    H=i+1;
                    f=false;
                }
            }
        }
        f=true;
        for(int i=0;i<W && f;++i){
            for(int j=0;j<H && f;++j){
                if(mp[j][i]=='#'){
                    w=i;
                    f=false;
                }
            }
        }
        f=true;
        for(int i=W-1;i>=0 && f;--i){
            for(int j=0;j<H && f;++j){
                if(mp[j][i]=='#'){
                    W=i+1;
                    f=false;
                }
            }
        }
        //
        //cout<<"H:"<<H<<'\n'
        //    <<"h:"<<h<<'\n'
        //    <<"W:"<<W<<'\n'
        //    <<"w:"<<w<<'\n';
        //
        for(int i=h;i<H;++i){
            for(int j=w;j<W;++j){
                cout<<mp[i][j];
            }
            cout<<'\n';
        }
        cout<<'\n';
    }
    return 0;
}
