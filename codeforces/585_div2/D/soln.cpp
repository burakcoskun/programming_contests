#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, lq, rq;
string s;
int lsum, rsum;

void sum() {
  for (int i = 0; i < n / 2; ++i) {
    if (s[i] != '?')
      lsum += s[i] - '0';
    else
      ++lq;
  }
  for (int i = n / 2; i < n; ++i) {
    if (s[i] != '?')
      rsum += s[i] - '0';
    else
      ++rq;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> s;
  sum();
  // left min
  int minlsum = lsum + lq / 2 * 9;
  int maxrsum = rsum + (rq / 2) * 9;
  if (maxrsum > minlsum) {
    cout << "Monocarp" << endl;
    return 0;
  }
  int maxlsum = lsum + (lq + 1) / 2 * 9;
  int minrsum = rsum + (rq + 1) / 2 * 9;
  if (maxlsum > minrsum) {
    cout << "Monocarp" << endl;
    return 0;
  }

  maxrsum = rsum + (rq + 1) / 2 * 9;
  minlsum = lsum + (lq + 1) / 2 * 9;
  if (maxrsum > minlsum) {
    cout << "Monocarp" << endl;
    return 0;
  }

  minrsum = rsum + rq / 2 * 9;
  maxlsum = lsum + lq / 2 * 9;
  if (maxlsum > minrsum) {
    cout << "Monocarp" << endl;
    return 0;
  }

  cout << "Bicarp" << endl;
  return 0;
}
