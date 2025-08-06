#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
bool bei(int a,int x,int y,int z){
    if(a%x==0||a%y==0||a%z==0) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n ;cin >> n;
    ll ans = 0;
    int x,y,z; cin >> x >> y >> z;
    for (int i = 1; i <= n; ++i) {
        if(bei(i,x,y,z)) ans = ans + 1;
    }
    cout << ans;
    return 0;
}