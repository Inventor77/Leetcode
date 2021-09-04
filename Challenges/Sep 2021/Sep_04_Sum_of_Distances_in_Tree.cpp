// ------------------- BruteForce ----------------------
// -----------------------------------------------------


class Solution {
    int size;
public:
    vector<int> ans;
    vector<int> cnt;

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        size = n;
        vector<int> adj[n];
        ans.resize(n, 0);
        cnt.resize(n, 1);
        for (auto x : edges)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        dfs(0, -1, adj);
        dfs2(0, -1, adj);
        return ans;
    }
    void dfs(int src, int par, vector<int> adj[]) {
        for (auto& child : adj[src]) {
            if (child != par)
            {
                dfs(child, src, adj);
                cnt[src] += cnt[child];
                ans[src] += ans[child] + cnt[child];
            }

        }
    }
    void dfs2(int src, int par, vector<int> adj[]) {
        for (auto& child : adj[src]) {
            if (child != par)
            {
                ans[child] += (ans[src] + (size - cnt[child]) - ans[child] - cnt[child]);
                dfs2(child, src, adj);
            }
        }
    }
};



// ------------------ 56ms Submission ----------------------

// class Solution {
// public:

//     vector<vector<int>> v;
//     vector<int> counter, res;


//     void dfs(int i, int p = -1) {
//         for (auto u : v[i]) {
//             if (u == p)
//                 continue;
//             dfs(u, i);
//             counter[i] += counter[u];
//             res[i] += res[u] + counter[u];
//         }
//         counter[i] += 1;
//     }


//     void dfs2(int i, int n, int p = -1) {
//         for (auto u : v[i]) {
//             if (u == p)
//                 continue;
//             res[u] = res[i] - counter[u] + n - counter[u];
//             dfs2(u, n, i);
//         }
//     }

//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
//         v.resize(n);
//         for (int i = 0; i < n - 1; i++) {
//             int a = edges[i][0];
//             int b = edges[i][1];
//             v[a].push_back(b);
//             v[b].push_back(a);
//         }
//         res.resize(n);
//         counter.resize(n);
//         dfs(0);
//         dfs2(0, n);
//         return res;
//     }
// };

// ---------------------------------------------------------------


//  --------------------- 29500KB Submission ---------------------

// class Solution {
// public:
//     vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {

//         vector<int> sumOfDistances(n, 0);

//         vector<int> adj[n];
//         for (auto& edge : edges) {

//             int u = edge[0], v = edge[1];

//             adj[u].push_back(v);
//             adj[v].push_back(u);

//         }

//         getCountNodesInBranch(0, 0, -1, sumOfDistances, adj);
//         updateAnswer(0, -1, sumOfDistances, adj, n);

//         return sumOfDistances;
//     }

//     void updateAnswer(int u, int parent, vector<int>& sumOfDis, vector<int> adj[], int n) {

//         if (u)
//             sumOfDis[u] = sumOfDis[parent] - sumOfDis[u] + (n - sumOfDis[u]);

//         for (auto& v : adj[u]) {

//             if (v != parent)
//                 updateAnswer(v, u, sumOfDis, adj, n);
//         }
//     }

//     int getCountNodesInBranch(int u, int dis, int P, vector<int>& sumOfDis, vector<int> adj[]) {

//         sumOfDis[0] += dis;
//         int countDescenders = 0;

//         for (auto& v : adj[u]) {

//             if (v != P)
//                 countDescenders += getCountNodesInBranch(v, dis + 1, u, sumOfDis, adj);
//         }

//         if (u)
//             sumOfDis[u] = countDescenders + 1;

//         return countDescenders + 1;
//     }
// };

// ------------------------------------------------------------------------------------