class Solution {
private:
    void run_bfs(const vector<vector<int>>& g, vector<int>& bfs, vector<int>& parent, int n, int root) {
        parent.assign(n, -1);
        bfs = { root };
        for (int i = 0; i<int(bfs.size()); i++) {
            int u = bfs[i];
            for (int v : g[u])
                if (v != root && parent[v] == -1) {
                    parent[v] = u;
                    bfs.push_back(v);
                }
        }
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> g(n);
        for (const auto& edge : edges) {
            g[edge[0]].push_back(edge[1]);
            g[edge[1]].push_back(edge[0]);
        }
        vector<int> bfs, parent;
        int root = 0;
        run_bfs(g, bfs, parent, n, root);

        root = bfs.back();
        run_bfs(g, bfs, parent, n, root);

        int last = bfs.back();
        vector<int> path = { last };
        while (path.back() != root)
            path.push_back(parent[path.back()]);

        if (int len = int(path.size()); len % 2)
            return { path[len / 2] };
        else
            return { path[len / 2], path[len / 2 - 1] };
    }
};