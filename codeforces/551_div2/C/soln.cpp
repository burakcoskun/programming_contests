#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int n;
string s;

void read_input() {
  cin >> n >> s;
  if (n % 2) {
    printf(":(\n");
    return;
  }
  if (n == 2) {
    if (s[0] == ')' || s[1] == '(')
      printf(":(\n");
    else
      printf("()\n");
    return;
  }
  if (s[0] == ')' || s[1] == ')' || s[n - 1] == '(' || s[n - 2] == '(') {
    printf(":(\n");
    return;
  }

  int cnt = 0, q = 0;
  for (int i = 2; i < n - 2; ++i) {
    if (s[i] == '(')
      ++cnt;
    else if (s[i] == ')')
      --cnt;
    else
      ++q;
    // cout << q << " " << cnt << endl;
  }
  if (abs(cnt) > q || ((q - abs(cnt)) % 2)) {
    printf(":(\n");
    return;
  }
  int numr = (q - abs(cnt)) / 2;
  if (cnt < 0)
    numr += abs(cnt);
  string res(n, ' ');
  res[0] = res[1] = '(';
  res[n - 2] = res[n - 1] = ')';
  for (int i = 2; i < n - 2; ++i) {
    if (s[i] != '?')
      res[i] = s[i];
    else {
      if (numr) {
        res[i] = '(';
        --numr;
      } else {
        res[i] = ')';
      }
    }
  }
  // cout << res << endl;

  cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (res[i] == '(')
      ++cnt;
    else
      --cnt;
    if (!cnt && i < n - 1) {
      printf(":(\n");
      return;
    }
  }
  if (cnt) {
    printf(":(\n");
    return;
  }
  cout << res << endl;
}

int main() {
  read_input();
  return 0;
}
