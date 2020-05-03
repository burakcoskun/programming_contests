#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> s;
    bool same = true;
    for (int i = 1; i < s.size(); ++i)
      if (s[i] != s[i - 1])
        same = false;
    if (same)
      cout << s << "\n";
    else {
      for (int i = 0; i < s.size(); ++i)
        cout << "10";
      cout << "\n";
    }
  }
  return 0;
}
