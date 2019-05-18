#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

long long pow2[55], res[55];

void print_res(int k, long long a) {
  // for (int i = 0; i < k; ++i)
  // cout << res[i] << " ";
  // cout << endl;
  printf("%d ", k);
  cout << a << " ";
  long long num = a;
  for (int i = 1; i < k; ++i) {
    num = a * pow2[i - 1];
    // cout << "Lalstl2" << num << endl;
    for (int j = 2; j <= i; ++j) {
      num += pow2[i - j] * res[j - 2];
      //  cout << "Lalst1" << num << endl;
    }
    // cout << "Last" << num << endl;
    num += res[i - 1];
    cout << num << " ";
  }
  printf("\n");
}

void solve(long long a, long long b, long long m) {
  if (a == b) {
    cout << 1 << " " << a << endl;
    return;
  }
  for (int i = 2; i <= 50; ++i) {
    long long rem = b;
    rem -= pow2[i - 2] * a;
    // cout << rem << endl;
    for (int j = 3; j <= i; ++j) {
      rem -= pow2[i - j];
      res[j - 3] = 1;
    }
    // cout << rem << endl;
    --rem;
    if (rem < 0)
      break;
    for (int j = 3; j <= i; ++j) {
      long long r = min(rem / pow2[i - j], m - 1);
      rem -= r * pow2[i - j];
      res[j - 3] += r;
      // cout << r << " " << pow2[i - j] << " " << rem << endl;
    }

    // cout << "last:" << rem << endl;
    if (rem < 0 || rem >= m)
      continue;

    res[i - 2] = rem + 1;
    print_res(i, a);
    return;
  }
  printf("-1\n");
}

int main() {
  for (int i = 0; i <= 50; ++i) {
    pow2[i] = 1LL << i;
  }

  long long t;
  cin >> t;
  for (long long i = 0; i < t; ++i) {
    long long a, b, m;
    cin >> a >> b >> m;
    /// scanf("%l64d %l64d %l64d", &a, &b, &m);
    solve(a, b, m);
  }
  return 0;
}
