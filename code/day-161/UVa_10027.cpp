#include <bits/stdc++.h>

using namespace std;

/* I/O Optimize */
struct roleS{
    string l,r;
    roleS(const string &_l, const string &_r):l(_l),r(_r){}
    roleS(){}
};
inline string CleanStr(const string &s){
    if(s.size()>=2 && s.front()=='"' && s.back()=='"'){
        return s.substr(1,s.size()-2);
    }
    return s;
}

inline void solve(){
    int T;
    string line;
    getline(cin,line);
    while(line.empty() && getline(cin,line)){}
    T=stoi(line);
    while(T--){
        string s;
        while(getline(cin,s) && s.empty()){}

        //init
        string InitS;
        InitS=CleanStr(s);
        //init

        bool f=false;
        vector<roleS>trans;
        while(getline(cin,s)){
            if(s.empty()){break;}
            if(s.find("->")==string::npos){continue;}
            size_t pos=s.find("->");
            
            string lft=CleanStr(s.substr(0,pos));
            string rit=CleanStr(s.substr(pos+2));
            if(lft==rit){continue;}
            if(lft.empty() && !rit.empty()){f=true;}
            if(rit.find(lft)!=rit.npos){f=true;}
            trans.emplace_back(lft,rit);
        }
        if(f){
            cout<<"Too many.\n";
            continue;
        }
        unordered_set<string> vis;
        vis.reserve(1001);
        queue<string> Q;
        vis.emplace(InitS);
        Q.emplace(InitS);
        while(!Q.empty() && vis.size() <= 1000){
            string cur=Q.front();
            Q.pop();
            for(const auto &form:trans){
                auto pos=0;
                while((pos=cur.find(form.l,pos))!=string::npos){
                    string ns=cur.substr(0,pos) + form.r + cur.substr(pos+form.l.size());

                    if(vis.find(ns)==vis.end()){
                        vis.emplace(ns);
                        Q.push(move(ns));
                        if(vis.size() > 1000){f=true;break;}
                    }
                }
                if(f){break;}
                ++pos;
            }
            if(f){break;}
        }
        if(f){
            cout<<"Too many.\n";
        }else{
            cout<<vis.size()<<'\n';
        }
        if(T>0) cout<<'\n';  // 測資間空行
    }
    cout.flush();
}

/* Programing area*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
