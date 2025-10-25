#include <iostream>
#include <vector>
#include <queue>
#include <limits> // Required for std::numeric_limits
#include <algorithm> // Required for std::max

// Define a large enough infinity for long long
const long long INF = std::numeric_limits<long long>::max();

// State for Dijkstra's algorithm
struct State {
    long long batteries; // Batteries upon arrival at the node
    int node_idx;

    // Custom comparator for min-heap
    bool operator>(const State& other) const {
        if (batteries != other.batteries) {
            return batteries > other.batteries;
        }
        // Tie-breaking, can be useful for deterministic behavior but not strictly for correctness
        return node_idx > other.node_idx; 
    }
};

// Edge representation for adjacency list
struct Edge {
    int to;
    long long requirement; // Batteries required for this passage
};

void solve() {
    int n; // Number of checkpoints
    int m; // Number of passages
    std::cin >> n >> m;

    // b[i] = batteries available at checkpoint i (1-indexed)
    std::vector<long long> b(n + 1); 
    for (int i = 1; i <= n; ++i) {
        std::cin >> b[i];
    }

    std::vector<std::vector<Edge>> adj(n + 1);
    for (int i = 0; i < m; ++i) {
        int u_node, v_node;
        long long w_req;
        std::cin >> u_node >> v_node >> w_req;
        adj[u_node].push_back({v_node, w_req});
    }

    // min_arrival_batteries[i] = minimum batteries robot has upon arrival at checkpoint i
    std::vector<long long> min_arrival_batteries(n + 1, INF);
    
    // Priority queue for Dijkstra. Stores {batteries_on_arrival, node_index}
    std::priority_queue<State, std::vector<State>, std::greater<State>> pq;

    min_arrival_batteries[1] = 0; // Robot starts at checkpoint 1 with 0 batteries
    pq.push({0, 1});

    while (!pq.empty()) {
        State current_state = pq.top();
        pq.pop();

        long long batteries_on_arrival_at_u = current_state.batteries;
        int u = current_state.node_idx;

        // If we've already found a path to u with fewer (or equal) arrival batteries
        if (batteries_on_arrival_at_u > min_arrival_batteries[u]) {
            continue;
        }

        // Explore passages from checkpoint u
        for (const auto& edge : adj[u]) {
            int v = edge.to;
            long long passage_requirement_w = edge.requirement;

            // Calculate batteries needed to collect at u to meet passage_requirement_w
            long long batteries_to_collect_at_u = std::max(0LL, passage_requirement_w - batteries_on_arrival_at_u);

            // Check if checkpoint u has enough batteries to collect
            if (batteries_to_collect_at_u > b[u]) {
                // Not enough batteries at checkpoint u to make this passage
                continue; 
            }

            // Batteries possessed when leaving u (and thus arriving at v)
            // This is equivalent to std::max(batteries_on_arrival_at_u, passage_requirement_w)
            long long batteries_on_arrival_at_v = batteries_on_arrival_at_u + batteries_to_collect_at_u;
            
            if (batteries_on_arrival_at_v < min_arrival_batteries[v]) {
                min_arrival_batteries[v] = batteries_on_arrival_at_v;
                pq.push({min_arrival_batteries[v], v});
            }
        }
    }

    if (min_arrival_batteries[n] == INF) {
        std::cout << -1 << std::endl;
    } else {
        // The question asks for the minimum number of batteries the robot can have AT THE END.
        // This means after arriving at checkpoint n (with min_arrival_batteries[n])
        // and then potentially collecting batteries b[n]. To minimize, collect 0 from b[n].
        std::cout << min_arrival_batteries[n] << std::endl;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}