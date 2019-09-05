#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n;
int a[55];

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  sort(a, a + n);
  if (a[0] == a[n / 2]) {
    cout << "Bob" << endl;
  } else
    cout << "Alice" << endl;
  return 0;
}
