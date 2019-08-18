#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, a[100005];
int used[1005], p[1005];
const int inf = 1e9;
int res = inf;

bool con(ll f, ll s) {
  while (f && s) {
    if ((f % 2) && (s % 2))
      return true;
    f /= 2;
    s /= 2;
  }

  return false;
}

void bfs(int s) {
  queue<pair<int, int>> q;
  q.push(make_pair(s, 1));
  while (!q.empty()) {
    int cur = q.front().first;
    int d = q.front().second;
    q.pop();
    cout << cur << " " << d << endl;

    if (cur == s && d > 1)
      res = min(res, d);

    for (int i = 0; i < n; ++i)
      if (i != cur && !used[i] && p[i] != cur) {
        ll f = a[cur];
        ll s = a[i];

        if (con(f, s)) {
          p[i] = cur;
          q.push(make_pair(i, d + 1));
          used[i] = 1;
        }
      }
  }
}

void solve() {

  for (int i = 3; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      used[j] = 0;
      p[j] = -1;
    }
    bfs(i);
  }
  if (res == inf)
    res = -1;
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  if (n > 100)
    cout << 3 << endl;
  else
    solve();

  return 0;
}
