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

int main() {
  cin >> n >> s;
  int o = 1, c = 1;

  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      cout << 1 - o;
      o = 1 - o;
    } else {
      cout << 1 - c;
      c = 1 - c;
    }
  }
  return 0;
}
