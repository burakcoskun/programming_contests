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
    vector<int> a(n), b(n), c(n), d(n);

    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }

    long long result = 0;
    for (int i = 0 ; i < n; ++i) {
        if(c[i] < a[i]) {
            result += (a[i] - c[i]);
            a[i] = c[i];
        }
        if(d[i] < b[i]) {
            result += a[i];
            result += (b[i] - d[i]);
        }
    }
    cout << result << endl;
  }
  return 0;
}
