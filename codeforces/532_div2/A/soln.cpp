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

int n, k, res = 0;
int a[105];

void read_input() {
  scanf(" %d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf(" %d", &a[i]);
  }
}

void solve() {
  for (int b = 0; b < n; ++b) {
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int diff = abs(i - b);
      if (diff % k != 0) {
        cnt += a[i];
      }
    }
    cnt = abs(cnt);
    res = max(res, cnt);
  }
}

int main() {
  read_input();
  solve();
  printf("%d\n", res);
  return 0;
}
