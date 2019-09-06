#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m, cycle = 0;
int vis[5005], s[5005], p[5005];
vector<pair<int, int>> e, in;

void dfs(int node) {
  if (p[node]) {
    cycle = 1;
    return;
  }
  if (vis[node])
    return;

  vis[node] = 1;
  p[node] = 1;

  for (int i = s[node]; i < m && e[i].first == node; ++i)
    dfs(e[i].second);
  p[node] = 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;

    e.push_back(make_pair(a, b));
    in.push_back(make_pair(a, b));
  }
  sort(e.begin(), e.end());
  s[e[0].first] = 0;
  for (int i = 1; i < m; ++i) {
    if (e[i].first != e[i - 1].first)
      s[e[i].first] = i;
  }

  for (int i = 0; i < n; ++i)
    if (!vis[i]) {
      dfs(i);
      //  cout << i << " " << cycle << endl;
    }

  if (cycle == 0) {
    cout << 1 << endl;
    for (int i = 0; i < m; ++i)
      cout << 1 << " ";
    cout << endl;
  } else {
    cout << 2 << endl;
    for (int i = 0; i < m; ++i)
      if (in[i].first < in[i].second)
        cout << 1 << " ";
      else
        cout << 2 << " ";
    cout << endl;
  }

  return 0;
}
