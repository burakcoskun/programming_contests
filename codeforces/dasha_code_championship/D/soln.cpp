#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
vector<pair<int, int>> cow;
int vis[100005], res;

vector<vector<int>> cont(100005);

void dfs(int node) {
  int a = cow[node].first;
  int b = cow[node].second;
  ++res;
  int isa = vis[a];
  int isb = vis[b];

  vis[a] = 1;
  vis[b] = 1;
  if (!isa)
    for (int i = 0; i < cont[a].size(); ++i) {
      int child = cont[a][i];
      if (!vis[cow[child].first] || !vis[cow[child].second])
        dfs(child);
    }
  if (!isb)
    for (int i = 0; i < cont[b].size(); ++i) {
      int child = cont[b][i];
      if (!vis[cow[child].first] || !vis[cow[child].second])
        dfs(child);
    }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> k;

  for (int i = 0; i < k; ++i) {
    int a, b;
    cin >> a >> b;
    if (b < a) {
      int tmp = b;
      b = a;
      a = tmp;
    }

    cont[a].push_back(i);
    cont[b].push_back(i);
    cow.push_back(make_pair(a, b));
  }

  for (int i = 0; i < k; ++i)
    if (!vis[cow[i].first] && !vis[cow[i].second])
      dfs(i);

  cout << k - res << endl;
  return 0;
}
