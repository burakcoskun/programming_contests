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

int n, m, h, res;
int l[55], r[55], x[55];

int main() {
  cin >> n >> h >> m;
  for (int i = 0; i < m; ++i)
    scanf(" %d %d %d", &l[i], &r[i], &x[i]);
  for (int i = 0; i < n; ++i) {
    int cmax = h;
    for (int j = 0; j < m; ++j) {
      if (i + 1 >= l[j] && i + 1 <= r[j])
        cmax = min(cmax, x[j]);
    }
    res += cmax * cmax;
  }
  cout << res << endl;
  return 0;
}
