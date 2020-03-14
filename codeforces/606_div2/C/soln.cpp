#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
string s;
vector<string> d{"twone", "one", "two"};

void add(int cnt, int st, vector<int> &res) {
  for (int k = st; k < st + cnt; ++k)
    res.push_back(k + 1);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> s;
    vector<int> res;
    for (int i = 0; i < s.size() - 2; ++i) {

      int lpos = i;
      for (int j = 0; j < 3; ++j) {
        bool f = true;
        int pos = i;
        int mcnt = s.size();
        int st;
        vector<pair<int, int>> ccnt;
        for (int k = 0; k < d[j].size(); ++k) {
          if (s[pos] != d[j][k]) {
            f = false;
            break;
          }
          int cnt = 0;
          while (pos < s.size() && s[pos] == d[j][k]) {
            ++pos;
            ++cnt;
          }
          ccnt.push_back(make_pair(cnt, pos - cnt));
          if (cnt < mcnt) {
            mcnt = cnt;
            st = pos - cnt;
          }
        }
        for (int k = 0; k < ccnt.size(); ++k) {
          if (j > 0 && k == 1 && ccnt[k].first > 1)
            f = false;
          if (j == 0 && (k != 0 && k != 2 && k != 4) && ccnt[k].first > 1)
            f = false;
        }
        if (f == true) {
          lpos = pos - 1;
          if (j > 0) {
            for (int k = st; k < st + mcnt; ++k)
              res.push_back(k + 1);
          } else {
            int minl = min(ccnt[0].first, ccnt[1].first);
            int minr = min(ccnt[3].first, ccnt[4].first);
            if (minl + minr < ccnt[2].first) {
              if (ccnt[0].first < ccnt[1].first)
                add(ccnt[0].first, ccnt[0].second, res);
              else
                add(ccnt[1].first, ccnt[1].second, res);

              if (ccnt[3].first < ccnt[4].first)
                add(ccnt[3].first, ccnt[3].second, res);
              else
                add(ccnt[4].first, ccnt[4].second, res);
            } else {
              add(ccnt[2].first, ccnt[2].second, res);
            }
          }
          break;
        } else
          lpos = max(lpos, pos - 1);
      }
      i = max(lpos, i);
    }

    cout << res.size() << endl;
    for (int i = 0; i < res.size(); ++i)
      cout << res[i] << " ";
    cout << endl;
  }

  return 0;
}
