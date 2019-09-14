#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
string s;
int a[105], b[105];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;

  for (int i = 0; i < n; ++i)
    cin >> a[i] >> b[i];

  int res = 0;
  for (int t = 0; t < 10000; ++t) {

    int current = 0;
    for (int i = 0; i < n; ++i) {
      int lamp = (s[i] == '1');

      if (t >= b[i]) {
        int cnt = 1;
        int timepassed = t - b[i];
        cnt += timepassed / a[i];
        if (cnt % 2)
          lamp = 1 - lamp;
      }

      if (lamp)
        ++current;
    }

    res = max(res, current);
  }

  cout << res << endl;
  return 0;
}
