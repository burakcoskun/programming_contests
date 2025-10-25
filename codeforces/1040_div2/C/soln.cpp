#include <bits/stdc++.h>

using namespace std;

struct segment {
  int left, right, index;
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<segment> a(n);
    for(int i = 0; i < n; ++i) {
      cin >> a[i].left >> a[i].right;
      a[i].index = i + 1;
    }
    sort(a.begin(), a.end(), [](const segment& a, const segment& b) {
      if (a.left != b.left) {
          return a.left < b.left;
      }
      return a.right > b.right;
    });
    vector<int> res;
    for(int i = 0; i < n; ++i) {
      if(i > 0 && a[i].left == a[i-1].left)
        continue;
      res.push_back(a[i].index);
    }
    cout << res.size() << endl;
    for(int i = 0; i < res.size(); ++i)
      cout << res[i] << " ";
    cout << endl;
  }
  return 0;
}
