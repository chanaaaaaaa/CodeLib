#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}

inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}

signed main(){
    int H=read(),W=read(),M=read();
    vector<int>mp(H*W,-1000000000);

    for(int i=0;i<M;++i){
        int r=read()-1,c=read()-1,s=read(),idx=r*W+c;
        if(s>mp[idx]){mp[idx]=s;}
    }

    for(int i=0;i<H;++i){
        for(int j= 0;j<W;++j){
            int idx=i*W+j;
            if(i>0){mp[idx]=max(mp[idx],mp[(i-1)*W+j]-1);}
            if(j>0){mp[idx]=max(mp[idx],mp[i*W+(j-1)]-1);}
        }
    }

    for(int i=0;i<H;++i){
        for(int j=W-1;j>=0;--j){
            int idx=i*W+j;
            if(i>0){mp[idx]=max(mp[idx],mp[(i-1)*W+j]-1);}
            if(j<W-1){mp[idx]=max(mp[idx],mp[i*W+(j+1)]-1);}
        }
    }

    for(int i=H-1;i>=0;--i){
        for(int j=0;j<W;++j){
            int idx=i*W+j;
            if(i<H-1){mp[idx]=max(mp[idx],mp[(i+1)*W+j]-1);}
            if(j>0){mp[idx]=max(mp[idx],mp[i*W+(j-1)]-1);}
        }
    }


    for(int i=H-1;i>= 0;--i){
        for(int j=W-1;j>=0;--j){
            int idx=i*W+j;
            if(i<H-1){mp[idx]=max(mp[idx],mp[(i+1)*W+j]-1);}
            if(j<W-1){mp[idx]=max(mp[idx],mp[i*W+(j+1)]-1);}
        }
    }

    int minn=2000000000;
    for(int &x:mp) {
        if(x<minn){minn=x;}
    }
    if(minn>=0){
        write(-1);
    }else{
        write(-minn-1);
    }
    putchar('\n');

    return 0;
}
