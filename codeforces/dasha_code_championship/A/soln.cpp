#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int a[105], p[105], res;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  sort(a, a + n);
  for (int i = 0; i < n; ++i) {
    if (p[i])
      continue;

    ++res;

    for (int j = i + 1; j < n; ++j)
      if (a[j] % a[i] == 0)
        p[j] = 1;
  }

  cout << res << endl;
  return 0;
}
