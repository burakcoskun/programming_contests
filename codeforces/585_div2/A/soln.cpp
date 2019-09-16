#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int a1, a2, k1, k2, n;
int r1, r2;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> a1 >> a2 >> k1 >> k2 >> n;
  if (k2 > k1) {
    int tmp = k2;
    k2 = k1;
    k1 = tmp;

    tmp = a2;
    a2 = a1;
    a1 = tmp;
  }

  int l = a1 * (k1 - 1) + a2 * (k2 - 1);
  if (l > n)
    r1 = 0;
  else
    r1 = n - l;

  int p2 = n / k2;
  p2 = min(a2, p2);
  n -= p2 * k2;
  int p1 = n / k1;
  p1 = min(a1, p1);

  r2 = p1 + p2;

  cout << r1 << " " << r2 << endl;
  return 0;
}
