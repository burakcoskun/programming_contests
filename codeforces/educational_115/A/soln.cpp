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
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    bool res = true;
    for (int i = 0; i < n; ++i)
      if (s1[i] == '1' && s2[i] == '1')
        res = false;
    if (res)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
