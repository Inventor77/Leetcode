class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        vector<int> dist(N, INT_MAX);
        unordered_map<int, unordered_map<int, int>> g;
        for (auto& e : edges) g[e[0]][e[1]] = g[e[1]][e[0]] = e[2] + 1;
        auto cmp = [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({ 0,0 });
        dist[0] = 0;
        while (!pq.empty()) {
            auto u = pq.top().first; pq.pop();
            if (dist[u] >= M) break;
            for (auto n_w : g[u]) {
                int v = n_w.first, w = n_w.second;
                if (dist[u] + w < dist[v]) {
                    dist[v] = w + dist[u];
                    pq.push({ v, dist[v] });
                }
            }
        }
        int res = 0;
        for (int i = 0; i < N; i++) if (dist[i] <= M) res++;
        /** the smart part **/
        for (auto& e : edges) {
            //couting the reachable nodes lying on edge e from node e[0] 
            int a = dist[e[0]] >= M ? 0 : min(M - dist[e[0]], e[2]);
            //couting the reachable nodes lying on edge e from node e[1] 
            int b = dist[e[1]] >= M ? 0 : min(M - dist[e[1]], e[2]);
            res += min(a + b, e[2]);
        }
        return res;

    }
};



// -------------- 96ms and 35100KB Submission -------------------------

#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ins insert
#define vii vector<int>
#define pii pair<int,int>
const int N = 3001;
int finalAns = 0;
vector<int>dist(N, INT_MAX);
vector<bool>check(N, false);
vector<pii>graph[N];
int maxMoves;

void dijkstra()
{
    //The start node is 0
    dist[0] = 0;
    check[0] = true;
    set<pii>s;
    //Weight,Node
    s.ins(mp(0, 0));

    while (s.size() > 0)
    {
        auto itr = s.begin();
        int w = itr->fi;
        int u = itr->se;
        s.erase(itr);
        dist[u] = w;
        check[u] = true;
        finalAns++;

        for (int i = 0;i < graph[u].size();i++)
        {
            int v = graph[u][i].fi;
            int weight = graph[u][i].se;

            if (dist[u] + weight < dist[v] && dist[u] + weight <= maxMoves)
            {
                s.erase(mp(dist[v], v));
                dist[v] = dist[u] + weight;
                s.ins(mp(dist[v], v));
            }
        }
    }
}

class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMove, int n)
    {
        for (int i = 0;i < n;i++) {
            graph[i].clear();
            dist[i] = INT_MAX;
            check[i] = false;
        }

        maxMoves = maxMove;
        for (int i = 0;i < edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2] + 1;
            graph[u].pb(mp(v, w));
            graph[v].pb(mp(u, w));
        }


        finalAns = 0;
        dijkstra();
        for (int i = 0;i < edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];


            int val1 = max(0, maxMoves - dist[u]);
            int val2 = max(0, maxMoves - dist[v]);
            finalAns += min(val1 + val2, w);
        }
        return finalAns;
    }
};

// --------------------------------------------------------