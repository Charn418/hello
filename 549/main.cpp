#include<bits/stdc++.h>
using namespace std;
int N = 1e4+2;


int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int n,m;cin >> n >> m;
    int a[N];
    for(int i=1; i <= n*m; i++){
        int x;cin >> x;
        if(x==1) a[i]=9;
        else a[i] = 0;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(a[(i-1)*m+j]==9){
                if(j<m&&a[(i-1)*m+j+1]!=9) a[(i-1)*m+j+1]++; //右边
                if(j>1&&a[(i-1)*m+j-1]!=9) a[(i-1)*m+j-1]++; //左边
                if(i<n&&a[i*m+j]!=9) a[i*m+j]++; //下边
                if(i>1&&a[(i-2)*m+j]!=9) a[(i-2)*m+j]++;  //上边
                if(j>1&&i>1&&a[(i-2)*m+j-1]!=9)  a[(i-2)*m+j-1]++;//左上方
                if(i>1&&j<m&&a[(i-2)*m+j+1]!=9) a[(i-2)*m+j+1]++;//右上方
                if(j>1&&i<n&&a[i*m+j-1]!=9) a[i*m+j-1]++;//左下方
                if(j<m&&i<n&&a[i*m+j+1]!=9) a[i*m+j+1]++;//右下方
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++)
            cout << a[(i-1)*m+j] << " ";
        cout << "\n";
    }
    return 0;
}