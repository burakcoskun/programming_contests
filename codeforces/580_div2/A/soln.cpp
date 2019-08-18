#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
int a[105], b[105];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];

  cin >> m;
  for (int i = 0; i < m; ++i)
    cin >> b[i];

  sort(a, a + n);
  sort(b, b + m);
  cout << a[n - 1] << " " << b[m - 1] << endl;
  return 0;
}
