#include <bits/stdc++.h>
using namespace std;

int main(){

    string a;
    while(getline(cin, a)){
		bool check=false;
		int cnt=0;
        for(int i=0;i<a.size();i++){
			if(('a'<=a[i] && a[i]<='z')||('A'<=a[i] && a[i]<='Z')){
				check=true;
			}else if(check){
				check=false;
				cnt++;
			}
		}
		if(check){cnt++;}
		cout<<cnt<<"\n";
    }
    return 0;
}
