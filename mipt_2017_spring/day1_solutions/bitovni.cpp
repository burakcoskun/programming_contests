#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 500500;
const int B = 31;

int a[MAX];
int best[MAX];

int main(void) {
  int N;
  scanf("%d", &N);
  for (int i = 0; i < N; ++i)
    scanf("%d", &a[i]);
  
  static int next[B];
  for (int i = 0; i < B; ++i)
    next[i] = N;

  for (int i = N-1; i >= 0; --i) {
    for (int j = 0; j < B; ++j)
      if (a[i] & (1<<j)) next[j] = i;
    
    vector<int> v(next, next + B);
    sort(v.begin(), v.end());
    int total_or = 0;
    for (int j: v) {
      total_or |= a[j];
      best[j-i+1] = max(best[j-i+1], total_or);
    }
  }

  for (int i = 1; i <= N; ++i) {
    printf("%d\n", best[i]);
    best[i+1] = max(best[i+1], best[i]);
  }

  return 0;
}
