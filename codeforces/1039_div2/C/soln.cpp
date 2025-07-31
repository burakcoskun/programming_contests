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
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    int min_left = a[0];
    string res = "YES";
    for(int i = 1; i < n; ++i) {
      // cout << min_left << " "<< a[i] << endl;
      if(a[i] >= min_left * 2) {
        res = "NO";
        break;
      }
      min_left = min(min_left, a[i]);
    }
    cout << res << endl;
  }
  return 0;
}
