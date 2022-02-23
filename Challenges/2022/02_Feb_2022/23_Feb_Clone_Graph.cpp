class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == NULL) {
            return NULL;
        }
        queue<Node*>q;
        unordered_map<Node*, Node*>m;
        Node* src = new Node(node->val);
        m[node] = src;
        q.push(node);
        while (!q.empty()) {
            auto fn = q.front();
            q.pop();
            for (auto it : fn->neighbors) {
                if (m.find(it) == m.end()) {
                    Node* ne = new Node(it->val);
                    q.push(it);
                    m[it] = ne;
                }
                m[fn]->neighbors.push_back(m[it]);
            }
        }
        return src;
    }
};