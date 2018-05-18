#include <cstdint>
#include <cstdio>
#include <set>
#include <vector>

const int MAXN = 100000;
const int64_t INF = 0x3f3f3f3f3f3f3f3fLL;

typedef int Node;

struct Edge {
  Node other;
  int64_t cost;
  int capacity;
};

struct QueueElement {
  Node node;
  int64_t cost;

  bool operator<(const QueueElement &other) const {
    if (cost != other.cost) {
      return  cost < other.cost;
    }
    return node < other.node;
  }
};

std::vector<Edge> edges[MAXN];
int n, m;
int64_t budget;

inline int64_t sqr(int x) {
  return (int64_t)x * (int64_t)x;
}

inline int64_t getSingleEdgeCost(const Edge& edge, int wantedCapacity) {
  if (edge.capacity >= wantedCapacity) {
    return 0;
  }
  return edge.cost * sqr(edge.capacity - wantedCapacity);
}

inline bool Dijkstra(int wantedCapacity) {
  std::set<QueueElement> queue;
  std::vector<int64_t> costs(n, INF);

  costs[0] = 0;
  queue.insert({0, 0});

  while (!queue.empty()) {
    auto top = *queue.begin();
    queue.erase(queue.begin());

    if (top.cost > budget) {
      return false;
    }
    if (top.node == n-1) {
      return true;
    }

    for (auto edge: edges[top.node]) {
      auto cost = getSingleEdgeCost(edge, wantedCapacity);
      if (cost + top.cost < costs[edge.other]) {
        queue.erase({edge.other, costs[edge.other]});
        costs[edge.other] = cost + top.cost;
        queue.insert({edge.other, costs[edge.other]});
      }
    }
  }

  return false;
}

inline int BinarySearch() {
  int l = 0, r = 1000000, m;

  while (l + 1 < r) {
    m = l + (r - l) / 2;
    bool result = Dijkstra(m);
    if (result) {
      l = m;
    } else {
      r = m;
    }
  }
  return l;
}

int main() {
  scanf("%d%d%lld", &n, &m, &budget);
  for (int i = 0; i < m; ++i) {
    int a, b, t;
    long long c;
    scanf("%d%d%lld%d", &a, &b, &c, &t);
    --a; --b;
    edges[a].push_back({b, c, t});
    edges[b].push_back({a, c, t});
  }

  printf("%d\n", BinarySearch());

  return 0;
}
