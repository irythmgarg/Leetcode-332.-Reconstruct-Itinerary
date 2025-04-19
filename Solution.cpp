class Solution {
public:
    // Adjacency list where each source maps to a min-heap (lexicographically sorted) of destinations
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> adj;
    vector<string> result;

    // DFS traversal using Hierholzer’s algorithm to construct Eulerian path
    void dfs(string src) {
        auto& dests = adj[src];
        while (!dests.empty()) {
            string next = dests.top();
            dests.pop();
            dfs(next);
        }
        result.push_back(src); // Add airport after visiting all destinations from it
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph by pushing destinations into min-heaps for lexical order
        for (auto& ticket : tickets) {
            adj[ticket[0]].push(ticket[1]);
        }

        // Start DFS from JFK airport as required
        dfs("JFK");

        // Reverse the result since it's built in post-order (destinations added after recursion)
        reverse(result.begin(), result.end());
        return result;
    }
};
