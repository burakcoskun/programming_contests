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

int n, m, h;
int l[105], r[105], t[105][105];

void read_input() {
  scanf(" %d %d %d", &n, &m, &h);
  for (int i = 0; i < m; ++i) {
    scanf(" %d", &l[i]);
  }
  for (int i = 0; i < n; ++i) {
    scanf(" %d", &r[i]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int c;
      scanf(" %d", &c);
      if (!c)
        printf("0 ");
      else
        printf("%d ", min(l[j], r[i]));
    }
    printf("\n");
  }
}

int main() {
  read_input();
  return 0;
}
