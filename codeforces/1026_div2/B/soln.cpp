#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    string s;
    cin >> s;
    int cnt = 0;
    int first_0 = -1;
    for(int i = 0; i < s.size(); ++i) {
      if (s[i] == '(')
        ++cnt;
      else
        --cnt;
      if(cnt == 0) {
        first_0 = i;
        break;
      }
    }

    int res = false;
    for(int j = first_0 + 1; j < s.size(); ++j)
      if(s[j] == ')')
        res = true;
    if(res)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
