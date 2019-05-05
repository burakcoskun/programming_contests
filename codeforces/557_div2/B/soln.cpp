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

int a[55][55], b[55][55];
int n, m;

bool check(int i, int j) {
  if (i > 0 && ((a[i][j] <= a[i - 1][j] || b[i][j] <= b[i - 1][j]) &&
                (a[i][j] <= b[i - 1][j] || b[i][j] <= a[i - 1][j])))
    return false;
  if (j > 0 && ((a[i][j] <= a[i][j - 1] || b[i][j] <= b[i][j - 1]) &&
                (a[i][j] <= b[i][j - 1] || b[i][j] <= a[i][j - 1])))
    return false;
  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf(" %d", &a[i][j]);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf(" %d", &b[i][j]);

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (!check(i, j)) {
        cout << "Impossible" << endl;
        return 0;
      }
    }
  cout << "Possible" << endl;
  return 0;
}
