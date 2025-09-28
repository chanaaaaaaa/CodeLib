//#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma comment(linker, "/stack:200000000")

//#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
/*
inline int read(){
    int x=0,w=1;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c=='-'){w=-1;}
	}
	while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
	}
	return x*w;
}
inline void write(int x){
    if(x<0){putchar('-');x=-x;}
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
*/
int LCS[1001][1001];
string s1,s2;
inline int Flcs(int i,int j){
    if(i==0 || j==0){return 0;}
    if(LCS[i][j]!=-1){return LCS[i][j];}
    if(s1[i]==s2[j]){
        return LCS[i][j]=Flcs(i-1,j-1)+1;
    }else{
        return LCS[i][j]=max(Flcs(i-1,j),Flcs(i,j-1));
    }
}
/*
bcacbcabbaccbab
bccabccbbabacbc
a1b2c3d4e
zz1yy2xx3ww4vv
abcdgh
aedfhr
abcdefghijklmnopqrstuvwxyz
a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0
abcdefghijklmnzyxwvutsrqpo
opqrstuvwxyzabcdefghijklmn

11
4
3
26
14
*/
signed main() {
    while(getline(cin,s1)){
        getline(cin,s2);
        fill(LCS[0],LCS[0]+1001*1001,-1);
        s1.insert(s1.begin(),'\0');
        s2.insert(s2.begin(),'\0');

        cout<<Flcs(s1.size(),s2.size())-1<<"\n";
    }
    return 0;
}
