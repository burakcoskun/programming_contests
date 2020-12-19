#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string r, b;
    cin >> r >> b;

    int rc = 0;
    int bc = 0;
    for (int i = 0; i < n; ++i) {
      if (r[i] - '0' > b[i] - '0')
        ++rc;
      else if (r[i] - '0' < b[i] - '0')
        ++bc;
    }

    if (rc > bc)
      cout << "RED\n";
    else if (rc < bc)
      cout << "BLUE\n";
    else
      cout << "EQUAL\n";
  }
  return 0;
}
