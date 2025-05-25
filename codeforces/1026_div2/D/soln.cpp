#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct edge{
  int t, w;
};

bool possible(int max_w, int n, vector<vector<edge>> &graph, vector<int> &b) {
  vector<int> dp(n, -1*(1e9 + 11));
  dp[0] = 0;
  // cout << "maxw:" << max_w << endl;
  for (int i = 0; i < n; ++i) {
    dp[i] += b[i];
    dp[i] = min(dp[i], max_w);
    // cout << dp[i] << " ";
    for(int j = 0; j < graph[i].size(); ++j) {
      if(dp[i] >= graph[i][j].w) {
        dp[graph[i][j].t] = max(dp[graph[i][j].t], dp[i]);
      }
    }
  }
  // cout << endl;
  return dp[n-1] >= 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n, m;
    cin >> n >> m;
    vector<int> b(n, 0);
    vector<vector<edge>> graph(n, vector<edge>());
    for(int i = 0; i < n; ++i)
      cin >> b[i];
    for(int i = 0; i < m; ++i) {
      int s, t, w;
      cin >> s >> t >> w;
      --s; --t;
      graph[s].push_back(edge{t, w});
    }

    int left = 0, right = 1e9 + 11;
    int ans = -1;
    while(left <= right) {
      int mid = (left + right) / 2;
      if(possible(mid, n, graph, b)) {
        ans = mid;
        right = mid - 1;
      }
      else
        left = mid + 1;
    }
    cout << ans << endl;
  }

  return 0;
}
