#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
//#pragma comment(linker, "/stack:200000000")
#include<cstdio>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
        if(c==-1){return -1;}
    }
    while(c>='0' && c<='9'){
        x=(x<<3)+(x<<1)+(c-'0');
        c=getchar();
    }
    return x;
}
inline void write(long long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//-block
//long long lib[50]={1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296,433494437,701408733,1134903170,1836311903,2971215073,4807526976,7778742049,12586269025,20365011074};
//-some bad things
//normally ans
long long lib[51];
inline void form(){
    lib[0]=1;
    lib[1]=2;
    for(int i=2;i<51;i++){
        lib[i]=lib[i-1]+lib[i-2];
    }
}
//-normally ans
int N;
int main(){
    form();/*the bad things
    for(int i=0;i<50;i++){
        write(lib[i]);
        putchar(',');
    }*/
    while(N=read()){
        write(lib[N-1]);
        putchar('\n');
    }
    return 0;
}
