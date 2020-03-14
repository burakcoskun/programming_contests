#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int p[100005][3];
int freq[100005];
int v[100005], vres[100005];
vector<vector<int>> pos(100005, vector<int>());
vector<int> res;

int find_next(int node, int f) {
  if (freq[p[node][0]] == f)
    return p[node][0];
  else if (freq[p[node][1]] == f)
    return p[node][1];
  else
    return p[node][2];
}

int find_nonvisited(int node) {
  if (!vres[p[node][0]])
    return p[node][0];
  if (!vres[p[node][1]])
    return p[node][1];
  return p[node][2];
}

int find_pos(int k) {
  if (!v[pos[k][0]])
    return pos[k][0];
  if (!v[pos[k][1]])
    return pos[k][1];
  return pos[k][2];
}

void solve() {
  int f = -1, l = -1;
  for (int i = 0; i < n; ++i)
    if (freq[i] == 1) {
      if (f == -1)
        f = i;
      else
        l = i;
    }

  int node = pos[f][0];
  v[node] = 1;
  for (int i = 0; i < n - 3; ++i) {
    freq[p[node][0]]--;
    freq[p[node][1]]--;
    freq[p[node][2]]--;

    if (!res.size()) {
      int tmp = find_next(node, 0);
      res.push_back(tmp);
      vres[tmp] = 1;
      tmp = find_next(node, 1);
      res.push_back(tmp);
      vres[tmp] = 1;
    }

    int tmp = find_nonvisited(node);
    res.push_back(tmp);
    vres[tmp] = 1;

    node = find_pos(find_next(node, 1));
    v[node] = 1;
  }
  res.push_back(l);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n - 2; ++i) {
    cin >> p[i][0] >> p[i][1] >> p[i][2];
    p[i][0]--;
    p[i][1]--;
    p[i][2]--;
    freq[p[i][0]]++;
    freq[p[i][1]]++;
    freq[p[i][2]]++;
    pos[p[i][0]].push_back(i);
    pos[p[i][1]].push_back(i);
    pos[p[i][2]].push_back(i);
  }
  solve();

  for (int i = 0; i < res.size(); ++i)
    cout << res[i] + 1 << " ";
  cout << endl;
  return 0;
}
