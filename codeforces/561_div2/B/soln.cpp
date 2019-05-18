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

int k;
char w[5] = {'a', 'e', 'i', 'o', 'u'};

void find(int n, int m) {
  // cout << n << " " << m << endl;
  for (int i = 0; i < n; ++i) {
    // cout << endl;
    for (int j = 0; j < m; ++j)
      cout << w[(j + (i % 5)) % 5];
  }
  cout << endl;
}

int main() {
  cin >> k;
  for (int i = 5; i <= k; ++i)
    if (k % i == 0) {
      int j = k / i;
      if (j < 5)
        continue;

      find(i, j);
      return 0;
    }

  cout << -1 << endl;
  return 0;
}
