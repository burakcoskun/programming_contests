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

int n, h;
int a[1005];

void read_input() {
  scanf(" %d %d", &n, &h);
  for (int i = 0; i < n; ++i) {
    scanf(" %d", &a[i]);
  }
  for (int i = 1; i < n; ++i) {
    for (int j = i; j > 0; --j) {
      if (a[j - 1] < a[j]) {
        int tmp = a[j - 1];
        a[j - 1] = a[j];
        a[j] = tmp;
      } else
        break;
    }
    int h_sum = 0;
    for (int j = 0; j <= i; j += 2) {
      // printf("%d ", a[j]);
      h_sum += a[j];
    }

    if (h_sum > h) {
      printf("%d\n", i);
      return;
    }
  }
  printf("%d\n", n);
}

int main() {
  read_input();
  return 0;
}
