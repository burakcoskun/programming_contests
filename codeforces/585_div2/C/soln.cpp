#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s, t;
vector<vector<int>> p(4, vector<int>());
vector<pair<int, int>> res;

void solve() {
  while (p[1].size() > 0 || p[2].size() > 0) {
    if (p[1].size() > 0) {
      if (p[1].size() > 1) {
        int last = p[1].size() - 1;
        int first = p[1][last];
        int second = p[1][last - 1];
        res.push_back(make_pair(first, second));
        p[1].pop_back();
        p[1].pop_back();
      } else {
        res.push_back(make_pair(p[1][0], p[1][0]));
        p[2].push_back(p[1][0]);
        p[1].pop_back();
      }
    } else {
      if (p[2].size() > 1) {
        int last = p[2].size() - 1;
        int first = p[2][last];
        int second = p[2][last - 1];
        res.push_back(make_pair(first, second));
        p[2].pop_back();
        p[2].pop_back();
      } else {
        res.push_back(make_pair(p[2][0], p[2][0]));
        p[1].push_back(p[2][0]);
        p[2].pop_back();
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s >> t;
  int cnt = 0;
  for (int i = 0; i < s.size(); ++i) {
    cnt += s[i] == 'a';
    cnt += t[i] == 'a';

    if (s[i] == 'a' && t[i] == 'a')
      p[0].push_back(i);
    else if (s[i] == 'a' && t[i] == 'b')
      p[1].push_back(i);
    else if (s[i] == 'b' && t[i] == 'a')
      p[2].push_back(i);
    else
      p[3].push_back(i);
  }

  if (cnt % 2) {
    cout << -1 << endl;
    return 0;
  }

  solve();

  cout << res.size() << endl;
  for (int i = 0; i < res.size(); ++i)
    cout << res[i].first + 1 << " " << res[i].second + 1 << endl;

  return 0;
}
