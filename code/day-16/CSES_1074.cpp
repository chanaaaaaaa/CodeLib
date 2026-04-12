#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

#define int long long
using namespace std;

signed main()
{
    int N;
    cin >> N;
    vector<int> dat;
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        dat.push_back(temp);
    }
    sort(dat.begin(), dat.end());
    int mid = dat[N / 2], ans = 0;
    for (int i = 0; i < N; i++)
    {
        ans += abs(dat[i] - mid);
    }
    cout << ans << "\n";
    return 0;
}
