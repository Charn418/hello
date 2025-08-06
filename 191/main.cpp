#include<bits/stdc++.h>
using namespace std;
using ll = long long;
bool pd(ll n){
    int a;
    while(n!=0){
        a = n%10;
        if(a==1||a==2||a==0||a==9){
            return true;
        }
        n = n/10;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n; cin >> n;
    ll sum =0 ;
    for (int i = 1; i <= n; ++i) {
        if(pd(i)) sum = sum + i;
    }
    cout << sum ;
    return 0;
}
