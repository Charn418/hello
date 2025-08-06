#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
int a[N];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    long long ans = 0;
    for(int i = 0; i < n - 1; i++){
        sort(a + 1 + i, a + 1 + n);
        a[i + 2] = a[i + 1] + a[i + 2];
        ans = ans + a[i + 2];
    }
    cout << ans;
    return 0;
}