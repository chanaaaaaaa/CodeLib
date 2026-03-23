#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma comment(linker, "/stack:200000000")

#include<cstdio>
#include<set>

using namespace std;

inline int read(){
    int x=0;
    char c=0;
    while(c<'0' || c>'9'){
        c=getchar();
	}
	while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
	}
	return x;
}
inline void write(long x){
    if(x>=10){write(x/10);}
    putchar(x%10+'0');
}
//寶寶好電不只優化還寫加強版<3
signed main() {
    int t=read();
    while(t--){
        int num=read();
        int dic[num];
        for(int i=0;i<num;i++){
            dic[i]=read();
        }
        //-input

        //init
        int maxx=0,head=0,bottom=0;
        set<int>dat;
        for(int i=0;i<num;i++){
            if(dat.count(dic[i])){bottom=i;break;}
            maxx++;
            dat.insert(dic[i]);
        }
        //-init
        //gre
        while(bottom<num){
            while(dat.count(dic[bottom])){dat.erase(dic[head++]);}

            dat.insert(dic[bottom++]);
            if((bottom-head)>maxx){maxx=bottom-head;}
            if(maxx>(num-head)){break;}
        }
        //-gre
        //output
        write(maxx);
        putchar('\n');
    }
    return 0;
}
