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

int n;
int c[300005], last_differ, res = 0;

void read_input() {
  scanf(" %d", &n);
  for (int i = 0; i < n; ++i)
    scanf(" %d", &c[i]);
  for (int i = n - 2; i >= 0; --i) {
    if (c[i] != c[n - 1]) {
      last_differ = i;
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (c[i] != c[n - 1]) {
      res = max(res, n - 1 - i);
    } else
      res = max(res, last_differ - i);
  }
  printf("%d\n", res);
}

int main() {
  read_input();
  return 0;
}
