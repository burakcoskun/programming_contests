#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {

    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
      int a;
      cin >> a;
      pq.push(a);
    }

    int f = pq.top();
    pq.pop();
    int res = 0;

    while (!pq.empty()) {
      int c = pq.top();
      pq.pop();
      if (c + f <= k) {
        ++res;
        pq.push(c + f);
      }
    }

    cout << res << endl;
  }
  return 0;
}
