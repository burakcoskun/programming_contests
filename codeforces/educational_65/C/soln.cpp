#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int maxn = 500005;
int temp[500005], res[500005], used[500005];
int n, m;
vector<vector<int>> edge(maxn);
int ans;

void dfs(int node, int cnt) {
  // cout << node << endl;
  if (used[node])
    return;
  ++ans;
  used[node] = cnt;

  for (int i = 0; i < edge[node].size(); ++i)
    dfs(edge[node][i], cnt);
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    for (int j = 0; j < x; ++j) {
      scanf(" %d", &temp[j]);
      if (j) {
        edge[temp[j - 1]].pb(temp[j]);
      }
    }
    if (x > 0)
      edge[temp[x - 1]].pb(temp[0]);
  }

  int cnt = 1;
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      ans = 0;
      dfs(i, cnt);
      res[cnt++] = ans;
    }
    cout << res[used[i]] << " ";
  }
  cout << endl;
  return 0;
}
