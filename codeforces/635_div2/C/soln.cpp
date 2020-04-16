#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
const int maxn = 3e5 + 1;
vector<int> e[maxn];
pair<ll, ll> sub[maxn];
ll depth[maxn];

int dfs(int node, int p) {
  depth[node] = depth[p] + 1;
  ll res = 1;
  for (int i = 0; i < e[node].size(); ++i)
    if (e[node][i] != p)
      res += dfs(e[node][i], node);
  sub[node] = make_pair(res, node);
  return res;
}

bool comp(const pair<ll, ll> &l, const pair<ll, ll> &r) {
  ll num = l.first - depth[l.second] - r.first + depth[r.second];
  return num > 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  scanf(" %d %d", &n, &k);
  for (int i = 1; i < n; ++i) {
    int a, b;
    scanf(" %d %d", &a, &b);
    --a;
    --b;
    e[a].push_back(b);
    e[b].push_back(a);
  }

  dfs(0, 0);

  nth_element(sub, sub + n - k, sub + n, comp);
  ll res = 0;
  for (int i = 0; i < n - k; ++i)
    res += sub[i].first - depth[sub[i].second];
  printf("%lld\n", res);

  return 0;
}
