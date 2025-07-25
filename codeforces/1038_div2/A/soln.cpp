#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    if( n <=1 || m <=1) {
        cout << "NO" << endl;
    }
    else if(n==2 && m ==2) 
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
  }
  return 0;
}
