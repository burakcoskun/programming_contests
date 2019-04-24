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

long long l, r;
long long mod = 1e9 + 7;

long long sum_to_n(long long n) {
  long long res = (n % mod) * ((n + 1) % mod) / 2;
  return res % mod;
}

long long calceven(long long l, long long r) {
  if (l == r)
    return l;
  // cout << "even" << l << " " << r << endl;
  long long res = sum_to_n(r / 2) - sum_to_n((l - 2) / 2);
  if (res < 0)
    res += mod;
  res %= mod;
  return (res * 2) % mod;
}

long long calcodd(long long l, long long r) {
  if (l == r)
    return l;
  // cout << l << " " << r << endl;
  long long res = sum_to_n(r) - sum_to_n(l - 1);
  if (res < 0)
    res += mod;
  res = res % mod;
  res = res - calceven(l + 1, r - 1);
  if (res < 0)
    res += mod;
  return res % mod;
}

long long calc(long long n) {
  long long cnt = 1, odd = 0, even = 0;
  long long res = 0;
  int t = 0;
  while (cnt * 2 <= n) {
    if (!t)
      res += calcodd(odd * 2 + 1, odd * 2 + 1 + (cnt - 1) * 2);
    else
      res += calceven((even + 1) * 2, (even + 1) * 2 + (cnt - 1) * 2);
    res = res % mod;
    // cout << res << " " << cnt << endl;

    if (!t)
      odd += cnt;
    else
      even += cnt;
    t = 1 - t;
    cnt *= 2;
  }

  // cout << odd << " " << even << endl;

  if (odd + even < n) {
    if (!t)
      res += calcodd(odd * 2 + 1, odd * 2 + 1 + (n - odd - even - 1) * 2);
    else
      res +=
          calceven((even + 1) * 2, (even + 1) * 2 + (n - odd - even - 1) * 2);
    res = res % mod;
  }
  if (res < 0)
    res += mod;
  res %= mod;
  return res;
}

void read_input() {
  cin >> l >> r;
  // cout << calc(0) << endl;
  // cout << calceven(6, 16) << endl;
  // cout << calcodd(3, 3) << endl;
  long long res = calc(r) - calc(l - 1);
  if (res < 0)
    res += mod;
  res %= mod;
  cout << res << endl;
  // cout << calc(r) << " " << calc(l - 1) << endl;
}

int main() {
  read_input();
  return 0;
}
