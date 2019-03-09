#include <algorithm>
#include <climits>
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

long long n, b, res = LLONG_MAX;

long long calc2(long long d) {

  long long res = 0;
  for (long long k = d; k <= n; k *= d) {
    res += n / k;
    if (n / k < d)
      break;
  }
  return res;
}

void calc(long long d) {
  long long cnt = 0;
  while (b % d == 0) {
    // cout << b << " " << d << "\n";
    b /= d;
    ++cnt;
  }
  if (cnt) {
    long long cnt2 = calc2(d);
    // cout << cnt << " " << cnt2 << " " << d << "\n";
    res = min(res, cnt2 / cnt);
  }
}

void read_input() {
  cin >> n >> b;
  long long tmp = b;

  for (long long d = 2; d * d <= tmp; ++d) {
    calc(d);
  }
  if (b > 1)
    calc(b);
  cout << res << "\n";
}

int main() {
  read_input();
  return 0;
}
