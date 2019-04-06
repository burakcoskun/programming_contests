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
long long a[300005];

void read_input() {
  scanf(" %d", &n);
  for (int i = 0; i < n; ++i)
    scanf(" %l64d", &a[i]);

  long long carry = 0, res = 0;
  for (int i = 0; i < n; ++i) {
    long long v = min(a[i] / 2, carry);
    // printf("%d %d\n", res, l);
    res += v;
    carry -= v;
    a[i] -= 2 * v;
    res += a[i] / 3;
    a[i] %= 3;
    carry += a[i];
  }

  cout << res << endl;
}

int main() {
  read_input();
  return 0;
}
