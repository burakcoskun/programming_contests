#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n;
ll low;
ll res[200005];
bool used[200005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  if (n % 2 == 0) {
    cout << "NO\n";
    return 0;
  }
  if (n == 1) {
    cout << "YES\n";
    cout << 1 << " " << 2 << endl;
    return 0;
  }

  low = 2 * n * (2 * n + 1) / 4;
  res[0] = 1;
  used[2] = 1;

  ll sum = 1;
  ll left = 2;
  ll right = 2 * n;

  for (int i = 1; i < n - 1; ++i) {
    if (i % 2) {
      while (used[right] && right > 0)
        --right;
      res[i] = right;
      --right;
      used[right] = 1;
    } else {
      while (used[left] && left < 2 * n) {
        ++left;
      }

      res[i] = left;
      ++left;
      used[left] = 1;
    }

    sum += res[i];
  }

  res[n - 1] = low - sum;
  sum = low;
  for (int i = n; i < 2 * n; ++i) {
    sum -= res[i - n];
    if (i % 2)
      res[i] = low + 1 - sum;
    else
      res[i] = low - sum;
    sum += res[i];
  }

  cout << "YES\n";
  for (int i = 0; i < 2 * n; ++i)
    cout << res[i] << " ";
  cout << endl;

  return 0;
}
