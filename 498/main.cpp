#include<bits/stdc++.h>
using namespace std;

int suan(int x){ //传入一个四位数
    int a,b,c=1000;
    a = x*10000;
    while(x!=0){
        b = x % 10;
        a = a + b*c;
        c = c/10;
        x = x/10;
    }
    return a;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n; cin >> n;
    int data = 0,ab = 0;
    int a,b;
    a = n/10000;
    b = n%10000;
    a = suan(a);
    b = suan(b);
    if(a>b&&b!=n) cout << b;
    else {
        ab = (n/10000 + 1);
        data = suan(ab);
    }
    cout << data << "\n";
    data = n/10000 +1;
    a = data/100;
    b = data%100;
    if(a>b) data = a*100+a;
    else data = b*100+b;
    data = suan(data);
    cout << data ;
    return 0;
}