#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    if(b == 0)
        return a;
    return gcd(b, a % b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    long long a,b,k;
    cin >> a >> b >> k;
    long long g = gcd(a,b);

    long long n = a / g;
    long long m = b / g;
    if(k >= a && k >= b)
        cout << "1" << endl;
    else if(g > 1 && n <= k && m <= k)
        cout << "1" << endl;
    else if(a == b)
        cout << "1" << endl;
    else
        cout << "2" << endl;
  }
  return 0;
}
