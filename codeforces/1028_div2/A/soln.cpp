#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while(t--) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int g = min(a,c);
    int f = min(b,d);

    if(g >= f)
      cout << "Gellyfish" ;
    else
      cout << "Flower";
    cout << endl;
  }
  return 0;
}
