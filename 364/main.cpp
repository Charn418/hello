#include <iostream>
using namespace std;
using ll = long long;
const int N = 5e4 + 5;
int a[N], L, n, M;
int check(int mid){  //check(mid)即在跳跃最短值为mid下，需要移走几块石头
    int count = 0,res = 0;
    for(int i = 1; i <= n; i++){
        if(a[i] - a[res] < mid){ //说明这个石头需要被移走，则下一次算距离res仍是该值
            count++;
            continue;
        }
        res = i;
    }
    if( L - a[res] < mid) return M+1;
    return count;
}
int main()
{
    cin >> L >> n >> M;
    for(int i = 1; i <= n; i++) cin >> a[i];
    ll l = 0, r = 1e9+4;
    while(l + 1 != r){
        ll mid = (l+r)/2; //mid即最短跳跃的最大值
        if(check(mid) <= M) l = mid;
        else r = mid;
    }
    cout << l << '\n';
    return 0;
}