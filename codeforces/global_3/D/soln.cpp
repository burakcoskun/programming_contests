#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

struct node {
  int a, b, pos;
};

int n;
vector<node> x, y;

int comp1(node &f, node &s) {
  return f.b > s.b;
}
int comp2(node &f, node &s) {
  return f.b < s.b;
}

void print_res(vector<node> &res) {
  printf("%d\n", res.size());
  for (int i = 0; i < res.size(); ++i)
    printf("%d ", res[i].pos + 1);
  printf("\n");
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d %d", &a, &b);
    node tmp;
    tmp.a = a;
    tmp.b = b;
    tmp.pos = i;
    if (a < b) {
      x.pb(tmp);
    } else if (a > b)
      y.pb(tmp);
  }
  if (x.size() > y.size()) {
    sort(x.begin(), x.end(), comp1);
    print_res(x);
  } else {
    sort(y.begin(), y.end(), comp2);
    print_res(y);
  }
  return 0;
}
