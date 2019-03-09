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

int n, max_numb, res;

void read_input() {
  scanf(" %d", &n);
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    int a;
    scanf(" %d", &a);
    if (a > max_numb) {
      cnt = 1;
      res = 1;
      max_numb = a;
    } else if (a < max_numb) {
      cnt = 0;
    } else {
      ++cnt;
      res = max(res, cnt);
    }
  }
  printf("%d\n", res);
}

int main() {
  read_input();
  return 0;
}
