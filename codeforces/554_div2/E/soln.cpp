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
map<pair<int, int>, int> used;
vector<vector<int>> e(2 * (1e5 + 10));
vector<int> vals(1e5 + 10), b, c;
int n;

void euler(int v) {
  for (int i = 0; i < e[v].size(); ++i)
    if (used[mp(v, e[v][i])] > 0) {
      used[mp(v, e[v][i])]--;
      used[mp(e[v][i], v)]--;
      // cout << "v:" << e[v][i] << endl;
      euler(e[v][i]);
    }
  cout << vals[v] << " ";
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
    e[v1].pb(v2);
    e[v2].pb(v1);
    used[mp(v1, v2)]++;
    used[mp(v2, v1)]++;
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
  return 0;
}
