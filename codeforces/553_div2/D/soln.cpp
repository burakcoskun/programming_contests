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
vector<pair<int, int>> d;

void read_input() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    d.pb(mp(a, b));
  }

  sort(d.begin(), d.end(),
       [](const pair<int, int> &lhs, const pair<int, int> &rhs) {
         return lhs.fs - lhs.sc > rhs.fs - rhs.sc;
       });
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    res += (long long)i * d[i].fs + (long long)(n - 1 - i) * d[i].sc;
  }
  cout << res << endl;
}

int main() {
  read_input();
  return 0;
}
