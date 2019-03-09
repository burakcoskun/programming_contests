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

int a, b, c, x, y, z;

void read_input() {
  scanf(" %d %d %d %d %d %d", &x, &y, &z, &a, &b, &c);
  if (a < x) {
    printf("NO\n");
    return;
  }

  a -= x;

  if (a + b < y) {
    printf("NO\n");
    return;
  }

  a -= y;

  if (a + b + c < z) {
    printf("NO\n");
    return;
  }

  printf("YES\n");
}

int main() {
  read_input();
  return 0;
}
