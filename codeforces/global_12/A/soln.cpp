#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
      if (s[i] == 'r')
        ++cnt;

    for (int i = 0; i < cnt; ++i)
      cout << 'r';
    for (int i = 0; i < n; ++i)
      if (s[i] != 'r')
        cout << s[i];
    cout << "\n";
  }
  return 0;
}
