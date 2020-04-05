#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
vector<long long> l, res;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  l.resize(m);
  res.resize(m);
  ll sum = 0;
  for (int i = 0; i < m; ++i) {
    cin >> l[i];
    sum += l[i];
  }

  if (sum < n || (l.size() > 1 && l[0] == n && l[1] == n)) {
    cout << -1 << endl;
    return 0;
  }

  ll left = sum - n;
  ll pos = 0;

  for (int i = 0; i < m; ++i) {
    res[i] = pos + 1;
    if (l[i] >= n - pos + 1) {
      cout << -1 << endl;
      return 0;
    }
    // cout << pos << " " << left << endl;
    ll npos = max(pos + 1, pos + l[i] - left);
    left -= max((ll)0, pos + l[i] - npos);
    pos = npos;
  }
  for (int i = 0; i < m; ++i)
    cout << res[i] << " ";
  cout << endl;
  return 0;
}
