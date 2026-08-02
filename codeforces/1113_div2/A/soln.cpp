#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    bool zero = true, one = true;
    for (int i = 0; i < s.size(); ++i) {
      if (zero && s[i] == '0')
        zero = false;
      else if (one && s[i] == '1')
        one = false;
      else
        cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
