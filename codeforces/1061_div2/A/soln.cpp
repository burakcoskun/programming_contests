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
    int res = 0;
    while(n > 2) {
      int m1 = n / 3;
      int m2 = m1;
      n = n - m1 - m2;
      res += m1;
    }
    cout << res << endl;
  }
  return 0;
}
