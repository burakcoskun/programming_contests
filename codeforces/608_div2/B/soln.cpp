#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s;

void pans(vector<int> &ans) {
  cout << ans.size() << endl;
  if (!ans.size())
    return;
  for (int i = 0; i < ans.size(); ++i)
    cout << ans[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;

  vector<int> res1;
  string bl = s;
  for (int i = 0; i < bl.size(); ++i) {
    if (bl[i] == 'W' && i + 1 < bl.size()) {
      bl[i] = 'B';
      if (bl[i + 1] == 'B')
        bl[i + 1] = 'W';
      else
        bl[i + 1] = 'B';
      res1.push_back(i + 1);
    }
  }
  if (bl[bl.size() - 1] == 'B') {
    pans(res1);
    return 0;
  }

  vector<int> res2;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == 'B' && i + 1 < s.size()) {
      s[i] = 'W';
      if (s[i + 1] == 'B')
        s[i + 1] = 'W';
      else
        s[i + 1] = 'B';
      res2.push_back(i + 1);
    }
  }
  if (s[s.size() - 1] == 'W') {
    pans(res2);
    return 0;
  }
  cout << -1 << endl;
  return 0;
}
