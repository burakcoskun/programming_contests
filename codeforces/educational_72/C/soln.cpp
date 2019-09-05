#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    string s;

    cin >> s;
    int n = s.size();

    int res = 0;
    vector<int> zeros(n);
    zeros[0] = s[0] == '0';
    for (int i = 1; i < n; ++i) {
      if (s[i] == '0')
        zeros[i] = zeros[i - 1] + 1;
      else
        zeros[i] = 0;
    }

    for (int i = n - 1; i >= 0; --i) {
      int cur = 0;
      int pow = 1;
      for (int j = i; j >= i - 25 && j >= 0; --j) {
        if (s[j] == '1')
          cur += pow;
        pow *= 2;

        if (s[j] == '0')
          continue;

        int z;
        if (j > 0)
          z = zeros[j - 1];
        else
          z = 0;

        // cout << cur << " " << i << " " << j << " z:" << z << endl;
        if (cur > 0 && z + i - j + 1 >= cur) {
          ++res;
          // cout << i << " " << j << " " << z << endl;
        }
      }
    }

    cout << res << endl;
  }

  return 0;
}
