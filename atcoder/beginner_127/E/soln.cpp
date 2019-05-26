#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, m, k;
const int mod = 1e9 + 7;

long long res2() {
  long long num = m - 1;
  long long res_x = 0, res_y = 0;
  res_x = (long long)((num + 1) * (2 * num + 4) * num / 12) % mod;
  res_x = res_x * n * n % mod;

  num = n - 1;
  res_y = (long long)((num + 1) * (2 * num + 4) * num / 12) % mod;
  res_y = res_y * m * m % mod;
  return (res_x + res_y) % mod;
}

long long comb(int a, int b) {
  long long res = 1;
  long long top = 1, bot = 1;
  for (int i = 0; i < b; ++i) {
    top = top * (a - i) % mod;
    bot = bot * (b - i) % mod;
  }

  long long binpow = mod - 2, botinv = 1;
  while (binpow) {
    if (binpow & 1)
      botinv = botinv * bot % mod;
    bot = bot * bot % mod;
    binpow >>= 1;
  }
  return (top * botinv) % mod;
}

int main() {
  cin >> n >> m >> k;
  long long res_2 = res2();
  cout << res_2 * comb(n * m - 2, k - 2) % mod << endl;
  return 0;
}
