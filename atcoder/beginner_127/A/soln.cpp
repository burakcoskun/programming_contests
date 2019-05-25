#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int a, b;

int main() {
  cin >> a >> b;
  if (a >= 13)
    cout << b << endl;
  else if (a >= 6)
    cout << b / 2 << endl;
  else
    cout << 0 << endl;
  return 0;
}
