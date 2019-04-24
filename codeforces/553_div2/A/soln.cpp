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

int n, res = 1e8;
string g = "ACTG";
string s;

int convert(char a, char b) {
  int right = max(a, b) - min(a, b);
  int left = min(a, b) - 'A' + 'Z' - max(a, b) + 1;
  return min(left, right);
}

void read_input() {
  cin >> n >> s;
  for (int i = 0; i < n - 3; ++i) {
    int cost = 0;
    for (int j = i; j < i + 4; ++j)
      cost += convert(s[j], g[j - i]);
    res = min(res, cost);
  }
  cout << res << endl;
}

int main() {
  read_input();
  return 0;
}
