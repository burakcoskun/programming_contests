#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n, k;
string s;

void reverse(string &s, int l, int r) {

  for (int i = 0; l + i < r - i; ++i) {
    char tmp = s[l + i];
    s[l + i] = s[r - i];
    s[r - i] = tmp;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n >> k >> s;
    --k;
    vector<pair<int, int>> res;

    for (int i = 0; i < n; ++i) {
      char ch;
      if (i < 2 * k && i % 2 == 0)
        ch = '(';
      else if (i < 2 * k)
        ch = ')';
      else if (i < 2 * k + (n - 2 * k) / 2)
        ch = '(';
      else
        ch = ')';

      if (s[i] != ch) {
        for (int j = i + 1; j < n; ++j)
          if (s[j] == ch) {
            res.push_back(make_pair(i + 1, j + 1));
            reverse(s, i, j);
            break;
          }
      }
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
      cout << res[i].first << " " << res[i].second << endl;
  }
  return 0;
}
