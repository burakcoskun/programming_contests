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

int t;

int main() {
  cin >> t;
  for (int i = 0; i < t; ++i) {
    int n;
    string s;
    cin >> n >> s;
    if (n < 11) {
      cout << "NO" << endl;
      continue;
    }
    int pos = n;
    for (int j = 0; j < s.size(); ++j) {
      if (s[j] == '8') {
        pos = j;
        break;
      }
    }

    if (n - pos >= 11) {
      cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
  return 0;
}
