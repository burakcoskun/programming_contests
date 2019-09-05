#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n;
string s;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  int b = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      ++b;
    else
      --b;
    if (b < -1) {
      cout << "No" << endl;
      return 0;
    }
  }
  if (b != 0) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;

  return 0;
}
