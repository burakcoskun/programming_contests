#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T;
int n;
int a[200005];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> T;
  for (int t = 0; t < T; ++t) {
    cin >> n;
    for (int i = 0; i < n; ++i)
      cin >> a[i];

    priority_queue<int> pq;
    for (int i = 0; i < n; ++i)
      pq.push(a[i]);

    int res = 0;
    while (!pq.empty()) {
      while (!pq.empty() && pq.top() % 2)
        pq.pop();
      if (pq.empty())
        break;
      int top = pq.top();
      while (!pq.empty() && pq.top() == top) {
        pq.pop();
        pq.push(top / 2);
      }

      ++res;
    }

    cout << res << endl;
  }
  return 0;
}
