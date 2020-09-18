#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  string s;
  cin >> s;
  vector<pair<char, int>> beg(s.size() + 1);
  vector<int> p(beg.size() + 1);
  for (int i = 0; i < s.size(); ++i) {
    beg[i].first = s[i];
    beg[i].second = i;
  }
  beg[s.size()].first = '$';
  beg[s.size()].second = s.size();
  sort(beg.begin(), beg.end());
  p[0] = 0;
  for (int i = 1; i < beg.size(); ++i) {
    if (beg[i].first != beg[i - 1].first)
      p[i] = p[i - 1] + 1;
    else
      p[i] = p[i - 1];
  }

  int k = 1, n = beg.size();
  while ((1 << (k - 1)) <= n) {
    /*
        for (int i = 0; i < n; ++i)
          cout << beg[i].second << " ";
        cout << endl;
        for (int i = 0; i < n; ++i)
          cout << p[i] << " ";
        cout << endl;
    */
    vector<int> temp(beg.size());
    for (int i = 0; i < n; ++i)
      temp[beg[i].second] = p[i];

    vector<pair<pair<int, int>, int>> suf(s.size() + 1);
    for (int i = 0; i < beg.size(); ++i) {
      suf[i].first.first = temp[i];
      suf[i].first.second = temp[(i + (1 << (k - 1))) % n];
      suf[i].second = i;
      // cout << "_" << suf[i].first.first << " " << suf[i].first.second << "_";
    }
    // cout << endl;
    sort(suf.begin(), suf.end());
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
      if (suf[i].first != suf[i - 1].first)
        p[i] = p[i - 1] + 1;
      else
        p[i] = p[i - 1];
    }
    for (int i = 0; i < n; ++i)
      beg[i].second = suf[i].second;
    ++k;
  }

  for (int i = 0; i < n; ++i)
    cout << beg[i].second << " ";
  cout << endl;
  return 0;
}
