#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    if (k > n - 2)
      cout << -1 << endl;
    else if (k == 0) {
      for (int i = 0; i < n; ++i) {
        if (i % 2 == 0)
          cout << '0';
        else
          cout << '1';
      }
      cout << endl;
    } else {
      string s;
      for (int i = 0; i < (n + 1) / 2; ++i)
        s += '0';
      for (int i = (n + 1) / 2; i < n; ++i)
        s += '1';

      int left_pos = 1, one_pos = (n + 1) / 2;
      int current = n - 2;
      while (current > k) {
        s[left_pos] = '1';
        s[one_pos] = '0';
        left_pos += 2;
        one_pos++;
        current -= 2;
      }
      if (current < k) {
        s[0] = '1';
        s[1] = '0';
      }
      cout << s << endl;
    }
  }
  return 0;
}
