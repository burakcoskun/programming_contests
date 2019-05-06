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

map<int, int> vname;
vector<multiset<int>> e(2 * (1e5 + 10));
// vector<vector<int>> e(2 * (1e5 + 10));
vector<int> vals(2 * (1e5 + 10)), b, c;
vector<int> res;
int n;

void euler(int v) {
  while (!e[v].empty()) {
    int node = *e[v].begin();
    e[v].erase(e[v].begin());
    e[node].erase(e[node].find(v));
    // cout << "v:" << e[v][i] << endl;
    euler(node);
  }
  res.pb(vals[v]);
}

int main() {
  cin >> n;
  --n;
  int pos = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (vname.find(a) == vname.end()) {
      vname[a] = pos;
      vals[pos++] = a;
    }
    b.pb(a);
  }
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (vname.find(a) == vname.end()) {
      vname[a] = pos;
      vals[pos++] = a;
    }
    c.pb(a);
  }

  for (int i = 0; i < n; ++i) {
    if (b[i] > c[i]) {
      cout << -1 << endl;
      return 0;
    }
    int v1 = vname[c[i]], v2 = vname[b[i]];
    e[v1].insert(v2);
    e[v2].insert(v1);
  }
  int odd = 0, first_odd = 0;
  for (int i = 0; i < pos; ++i) {
    if (e[i].size() % 2) {
      ++odd;
      first_odd = i;
    }
  }
  if (odd != 0 && odd != 2) {
    cout << -1 << endl;
    return 0;
  }
  // cout << odd << " " << vals[first_odd] << " " << first_odd << " "
  //     << vname[vals[first_odd]] << endl;
  euler(first_odd);
  if (res.size() == n + 1) {
    for (int i = 0; i < res.size(); ++i)
      cout << res[i] << " ";
  } else
    cout << -1;
  cout << endl;
  return 0;
}
