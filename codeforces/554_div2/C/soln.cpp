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

int a, b;
int diff;

int main() {
  cin >> a >> b;

  if (a == b) {
    cout << 0 << endl;
    return 0;
  }

  diff = abs(a - b);
  vector<int> divs;
  for (int i = 1; i * i <= diff; ++i) {
    if (diff % i == 0) {
      divs.pb(i);
      if (i * i != diff)
        divs.pb(diff / i);
    }
  }

  long long res = -1;
  long long res_k;

  for (int i = 0; i < divs.size(); ++i) {
    long long c = a / divs[i];
    if (a % divs[i])
      ++c;

    // cout << divs[i] << " " << c << endl;

    long long k = c * divs[i] - a;
    long long lcm = (a + k) * (b + k) / __gcd(a + k, b + k);
    if (res == -1 || res > lcm) {
      res_k = k;
      res = lcm;
    }
  }
  cout << res_k << endl;
  return 0;
}
