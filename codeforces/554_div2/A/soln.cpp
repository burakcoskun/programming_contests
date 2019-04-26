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

int n, m;
int f, s;

void read_input() {
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a % 2)
      ++f;
  }
  for (int i = 0; i < m; ++i) {
    int a;
    cin >> a;
    if (a % 2)
      ++s;
  }
  cout << min(f, m - s) + min(s, n - f) << endl;
}

int main() {
  read_input();
  return 0;
}
