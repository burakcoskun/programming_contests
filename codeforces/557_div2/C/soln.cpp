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

int n, k;
int res, x[100005], f[100005], l[100005];

int main() {
  cin >> n >> k;
  for (int i = 0; i < k; ++i) {
    cin >> x[i];
    if (!f[x[i]])
      f[x[i]] = i + 1;
    l[x[i]] = i + 1;
  }

  for (int i = 1; i <= n; ++i) {
    if (!f[i]) {
      if (i > 1 && i < n)
        res += 3;
      else
        res += 2;
    } else {
      if (i > 1 && (!l[i - 1] || l[i - 1] < f[i]))
        ++res;
      if (i < n && (!l[i + 1] || l[i + 1] < f[i]))
        ++res;
    }
  }
  cout << res << endl;
  return 0;
}
