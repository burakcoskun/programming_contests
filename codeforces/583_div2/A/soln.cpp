#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, d, e;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> d >> e;
  int res = n;

  for (long long eur = 0; eur * e * 5 <= n; ++eur) {
    int cur = n - (eur * e * 5);
    cur = cur % (d);

    res = min(res, cur);
  }
  cout << res << endl;
  return 0;
}
