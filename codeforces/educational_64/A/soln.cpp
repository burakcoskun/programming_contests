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

int p[3][3];
int res = 0, n;

void read_input() {
  p[0][1] = 3;
  p[0][2] = 4;
  p[1][0] = 3;
  p[1][2] = 0;
  p[2][0] = 4;
  p[2][1] = 0;

  int pr, t;

  cin >> n;
  cin >> pr;
  --pr;
  for (int i = 1; i < n; ++i) {
    cin >> t;
    --t;

    if (p[pr][t] == 0) {
      cout << "Infinite" << endl;
      return;
    }
    res += p[pr][t];
    pr = t;
  }
  cout << "Finite" << endl;
  cout << res << endl;
}

int main() {
  read_input();
  return 0;
}
