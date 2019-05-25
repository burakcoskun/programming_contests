#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int r, d, x;

int main() {
  cin >> r >> d >> x;
  int cur = x;
  for (int i = 0; i < 10; ++i) {
    cur = r * cur - d;
    cout << cur << endl;
  }
  return 0;
}
