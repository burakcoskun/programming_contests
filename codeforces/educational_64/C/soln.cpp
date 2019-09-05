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

#define maxn 200005
int n, z, used[maxn], x[maxn], res;

void read_input() {
  cin >> n >> z;
  for (int i = 0; i < n; ++i)
    scanf(" %d", &x[i]);
  sort(x, x + n);

  int last = n - 1;
  for (int i = n - 1; i >= 0; --i) {
    if (used[i])
      continue;
    while (used[last] && last > 0) {
      --last;
    }
    if (x[last] - x[i] >= z) {
      ++res;
      used[i] = 1;
      --last;
    }
  }
  cout << res << endl;
}

int main() {
  read_input();
  return 0;
}
