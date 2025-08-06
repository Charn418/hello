#include<bits/stdc++.h>
using namespace std;
int a[100][100] = {0};
int main(){
  ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
  int n,m,t; cin >> n>> m ;
  cin >> t;
  for(int i=0; i<t; i++){
    int x,y;cin >> x >> y;
      a[x][y] = 1; //x为行y为列
  }
  int k; cin >> k;
  int ans = t,shui = 0;
  for(int i = 0; i < k; i++){
     shui = shui +1;
    for(int _x = 1; _x <= n; _x++){
      for(int _y = 1; _y <= m; _y++)
      if(a[_x][_y]==shui){
        if(_y>1&&a[_x][_y-1]==0) {a[_x][_y-1] = 1+ shui;ans++;}//左边
        if(_y<m&&a[_x][_y+1]==0) {a[_x][_y+1] = 1 + shui;ans++;}//右边
        if(_x>1&&a[_x-1][_y]==0) {a[_x-1][_y] = 1 + shui;ans++;}//上边
        if(_x<n&&a[_x+1][_y]==0) {a[_x+1][_y] = 1 + shui;ans++;}//下边
      }
    }
  }
  cout << ans;

  return 0;
}