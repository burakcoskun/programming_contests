#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n+1);
    for(int i = 0; i < n; ++i) {
      cin >> a[i];
      b[a[i]]++;
    }
    int res = 0;
    for(int i = 0; i <= n; ++i) {
      if(b[i] > 0) {
        if (b[i] >= i)
          res += b[i] - i;
        else res += b[i];
      }
    }
    cout << res << endl;
  }
  return 0;
}
