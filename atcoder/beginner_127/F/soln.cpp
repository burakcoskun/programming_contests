#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

int q;
long long leftsum, rightsum, bsum;
priority_queue<int> maxh;
priority_queue<int, vector<int>, greater<int>> minh;

void print_min() {
  long long med = maxh.top();
  long long lsize = maxh.size() - 1;
  long long rsize = minh.size();

  long long res = bsum;
  res += med * lsize - (leftsum - med);
  res += rightsum - med * rsize;
  cout << med << " " << res << "\n";
}

void update(int a, int b) {
  bsum += b;

  if (maxh.size() == 0 || maxh.top() >= a) {
    maxh.push(a);
    leftsum += a;
  } else {
    minh.push(a);
    rightsum += a;
  }

  if (maxh.size() > minh.size() + 1) {
    leftsum -= maxh.top();
    rightsum += maxh.top();
    minh.push(maxh.top());
    maxh.pop();
  } else if (minh.size() > maxh.size()) {
    leftsum += minh.top();
    rightsum -= minh.top();
    maxh.push(minh.top());
    minh.pop();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> q;
  for (int t = 0; t < q; ++t) {
    int c;
    cin >> c;
    if (c == 2) {
      print_min();
    } else {
      int a, b;
      cin >> a >> b;
      update(a, b);
    }
  }
  return 0;
}
