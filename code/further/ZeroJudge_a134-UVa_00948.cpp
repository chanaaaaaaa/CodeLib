#include <iostream>
using namespace std;

int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n,a,
		f[40]={0,1};

	for(int i=2;i<40;i++){f[i]=f[i-1]+f[i-2];}

	cin>>n;
	while(n--){
		cin>>a;
        cout<<a;

		string s="";
		for (int j=39;j>=2;j--) {
			if(a>=f[j]){
				s+='1';
				a-=f[j];
			}else if(s.size()!=0){s+='0';}
		}
		cout<<" = "<<s<<" (fib)\n";
	}
	return 0;
}
