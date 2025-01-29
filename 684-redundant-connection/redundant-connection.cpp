class Solution {
public:
    bitset<1001> viz;
    vector<vector<short>> adj;
    vector<int> parent;
    int found = -1;

    void dfs(int i) {
        viz[i] = 1;
        for (int j : adj[i]) {
            if (!viz[j]) {
                parent[j] = i;
                dfs(j);
            } else if (j != parent[i] && found == -1) {
                found = j;
                parent[j] = i;
            }
        }
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        adj.resize(n + 1);
        parent.assign(n + 1, -1);

        for (auto& e : edges) {
            short u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(edges[0][0]);
        //    cout<<found<<endl;

        bitset<1001> cycle = 0;
        int j = found;
        do {
            cycle[j] = 1;
            j = parent[j];
        } while (j != found);

        for (int i = n - 1; i >= 0; i--) {
            int u = edges[i][0], v = edges[i][1];
            if (cycle[u] && cycle[v])
                return edges[i];
        }
        return {};
    }
};