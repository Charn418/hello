#include <bits/stdc++.h>
using namespace std;
const int N = 3e4+4;
using ll = long long;
ll a[N];
int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int w,n; cin >> w >> n;
  for(int i = 1; i <= n; i++) cin >>a[i];
  sort(a + 1, a + 1 + n);
  int ans = 0,count = 1; //前面第几个
    for(int i = n; i >= count; i--){
      if(a[i] + a[count] <= w) {
        ans = ans + 1;
        count++;
      }
       else ans = ans + 1;
    }
    cout << ans ;
  return 0;
}