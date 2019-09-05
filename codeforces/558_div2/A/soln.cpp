#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n, m;

int main() {
  cin >> n >> m;
  if (m <= 1) {
    cout << 1 << endl;
  } else if (m <= n / 2) {
    cout << m << endl;
  } else
    cout << n - m << endl;
  return 0;
}
