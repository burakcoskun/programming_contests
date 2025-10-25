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
    vector<int> b(n);
    vector<int> d(n);
    for(int i = 0; i < n; ++i) {
      cin >> b[i];
      --b[i];
      d[b[i]] = 1;
    }
    int res = 0;
    for (int i = 0; i < n; ++i)
      res += d[i];
    cout << res << endl;
  }
  return 0;
}
