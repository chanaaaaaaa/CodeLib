#pragma GCC optimize("Ofast")
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// 快速讀入
inline int read(){
    int x=0;
    char c=0;
    while(c<'0'||c>'9'){
        c=getchar();
        if(c==-1){return 0;}
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}

int main(){
    int N=read();
    vector<int>cnt(200005,0);
    int max_len=0;

    for(int i=0;i<N;++i){
        int tmp=read();
        cnt[tmp]++;
        if(tmp>max_len){max_len=tmp;}
    }

    vector<int>res;
    res.reserve(max_len+10);
    int current_active=N,carry=0;
    for(int i=0;i<max_len || carry>0; ++i){
        int sum=carry;

        if(i<max_len){
            sum+=current_active;
            current_active-=cnt[i+1];
        }

        res.emplace_back(sum%10);
        carry=sum/10;
    }

    for(int i=res.size()-1;i>=0;--i){
        putchar(res[i]+'0');
    }
    putchar('\n');

    return 0;
}
