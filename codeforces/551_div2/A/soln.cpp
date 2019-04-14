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

int n, t;

void read_input() {
  scanf(" %d %d", &n, &t);
  int res = 0, min_t = 200005;

  for (int i = 0; i < n; ++i) {
    int a, b, x;
    scanf(" %d %d", &a, &b);
    if (a >= t)
      x = 0;
    else
      x = ((t - 1 - a) / b) + 1;
    if (min_t > a + b * x) {
      min_t = a + b * x;
      res = i + 1;
    }
  }

  printf("%d\n", res);
}

int main() {
  read_input();
  return 0;
}
