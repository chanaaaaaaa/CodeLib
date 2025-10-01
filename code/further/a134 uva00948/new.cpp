#include <iostream>
using namespace std;

int main ()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int i, j;
	int n, s, a;
	int f[40]={0,1};

	for (i=2;i<40;i++)
		f[i] = f[i-1] + f[i-2];

	cin >> n;

	for (i=0;i<n;i++) {
		cin >> a;

		cout << a << " = ";

		int check = 0, base[41]={};

		for (j=39;j>=2;j--) {
			if (a - f[j] >= 0) {
				check = 1;

				if (base[j+1] != 1) {
					base[j] = 1;
					a = a - f[j];
				}
			}

			if (check == 1)
				cout << base[j];
		}

		cout << " (fib)" << endl;
	}

	return 0;
}
