#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
const int maxn = 1e5 + 1;
int deg[maxn], odd[maxn], even[maxn], v[maxn], cnt[maxn];
vector<vector<int>> e(maxn, vector<int>());

void dfs(int node) {
  if (deg[node] == 1) {
    even[node] = 1;
    return;
  }
  v[node] = 1;
  for (int i = 0; i < e[node].size(); ++i) {
    int child = e[node][i];
    if (!v[child]) {
      dfs(child);
      if (even[child])
        odd[node] = 1;
      if (odd[child])
        even[node] = 1;
    }
  }
}

void find() {
  int res1 = 1;
  int res2 = n - 1;
  for (int i = 0; i < n; ++i)
    if (odd[i] && even[i])
      res1 = 3;

  for (int i = 0; i < n; ++i)
    if (deg[i] == 1)
      cnt[e[i][0]]++;
  for (int i = 0; i < n; ++i)
    if (cnt[i] > 0)
      res2 -= cnt[i] - 1;
  cout << res1 << " " << res2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    --a;
    --b;
    deg[a]++;
    deg[b]++;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  for (int i = 0; i < n; ++i)
    if (deg[i] != 1) {
      dfs(i);
      break;
    }
  find();
  return 0;
}
