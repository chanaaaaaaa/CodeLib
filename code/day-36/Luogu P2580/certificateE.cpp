#include<bits/stdc++.h>

using namespace std;

struct TrieNode{
    int nxt[26];
    int cnt;
} node[500050];

int idx=2;
inline void insert(string si){
    int cur=1;
    for(auto i:si){
        if(node[cur].nxt[i-'a']==0){
            node[cur].nxt[i-'a']=idx;
            cur=idx;
            ++idx;
        }else{
            cur=node[cur].nxt[i-'a'];
        }
    }
    node[cur].cnt=1;
}
inline int query(string sq){
    int cur=1;
    for(auto i:sq){
        if(node[cur].nxt[i-'a']==0){
            return 0;
        }else{
            cur=node[cur].nxt[i-'a'];
        }
    }
    if(node[cur].cnt==1){
        node[cur].cnt=2;
        return 1;
    }
    return node[cur].cnt;
}

signed main(){
    int n;
    string s;
    cin>>n;

    while(n--){
        cin>>s;
        insert(s);
    }

    cin>>n;
    while(n--){
        cin>>s;
        int res=query(s);
        if(res==0){
            cout<<"WRONG\n";
        }else if(res==1){
            cout<<"OK\n";
        }else{
            cout<<"REPEAT\n";
        }
    }
    return 0;
}
