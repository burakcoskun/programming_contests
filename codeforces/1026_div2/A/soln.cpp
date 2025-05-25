#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i)
      cin >> a[i];
    sort(a.begin(), a.end());

    int left = 0, right = n - 1;
    int soln_left = 0, soln_right = 0;
    while((a[left] + a[right]) % 2 != 0) {
      left++;
      soln_left++;
    }
    left = 0;
    right = n -1;
    while((a[left] + a[right]) % 2 != 0) {
      right--;
      soln_right++;
    }
    cout << min(soln_left, soln_right) << endl;
  }

  return 0;
}
