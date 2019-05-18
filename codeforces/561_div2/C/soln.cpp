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

int a[200005];
int n;
long long res;

bool comp(int left, int right) { return abs(left) < abs(right); }

int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  sort(a, a + n, comp);

  /*
  for (int i = 0; i < n; ++i)
    cout << a[i] << " ";
  cout << endl;*/
  long long first = 0, sec = 0;
  for (; first < n; ++first) {
    while (sec < n && abs(a[sec]) <= abs(a[first]) * 2) {
      ++sec;
      // cout << abs(a[sec]) << endl;
    }
    // cout << "**" << sec << "" << endl;
    // cout << first << " " << sec << endl;
    res += sec - first - 1;
    // cout << res << endl;
  }
  cout << res << endl;

  return 0;
}
