#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, m;
int maxl, minr;

int main() {
  cin >> n >> m;
  minr = n;
  for (int i = 0; i < m; ++i) {
    int l, r;
    cin >> l >> r;
    maxl = max(maxl, l);
    minr = min(minr, r);
  }
  cout << max(minr - maxl + 1, 0) << endl;
  return 0;
}
