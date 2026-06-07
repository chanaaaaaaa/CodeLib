#include <bits/stdc++.h>
using namespace std;
using ll = long long;

set<pair<ll,ll>>se;
ll mex=0;

void add_interval(ll L,ll R){
    set<pair<ll,ll>>::iterator it=se.lower_bound({L,0});
    if(it!=se.begin()){
        --it;
        if (it->second+1<L){++it;}
    }

    ll nl=L,nr=R;
    vector<pair<ll,ll>>del;
    while(it!=se.end() && it->first<=R+1){
        nl=min(nl,it->first);
        nr=max(nr,it->second);
        del.push_back(*it);
        ++it;
    }
    for(const auto& p:del){se.erase(p);}
    se.insert({nl,nr});
}

void update_mex(){
    while(true){
        set<pair<ll,ll>>::iterator it=se.upper_bound({mex, LLONG_MAX});
        if(it==se.begin()){break;}
        --it;
        if(it->first>mex || it->second<mex){break;}
        mex=it->second+1;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int Q;
    cin>>Q;
    while(Q--){
        ll L,R;
        cin>>L>>R;
        add_interval(L,R);
        update_mex();
        cout<<mex<<'\n';
    }
    return 0;
}