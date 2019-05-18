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

int cnt[30];
int n, res;

int calc(int num) {
  if (num >= 2) {
    return num * (num - 1) / 2;
  }
  return 0;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    cnt[s[0] - 'a']++;
  }

  for (int i = 0; i < 26; ++i) {
    res += calc(cnt[i] / 2);
    res += calc((cnt[i] + 1) / 2);
  }

  cout << res << endl;
  return 0;
}
