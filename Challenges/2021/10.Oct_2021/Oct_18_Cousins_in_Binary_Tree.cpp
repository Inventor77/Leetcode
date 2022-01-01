bool isCousins(TreeNode* root, int x, int y) {
    if (!root)
        return false;
    queue<pair<int, TreeNode*>> q;
    q.push({ 0,root });
    pair<int, int>x1 = { 0,0 };
    pair<int, int> y1 = { 0,0 };
    int h = 0;
    while (q.size())
    {
        auto current = q.front();
        q.pop();
        int h = current.first;
        if (current.second->left) {
            q.push({ h + 1,current.second->left });
            if (current.second->left->val == x)
                x1 = { h + 1,current.second->val };
            if (current.second->left->val == y)
                y1 = { h + 1,current.second->val };

        }
        if (current.second->right) {
            q.push({ h + 1,current.second->right });
            if (current.second->right->val == x)
                x1 = { h + 1,current.second->val };
            if (current.second->right->val == y)
                y1 = { h + 1,current.second->val };

        }


    }

    return (x1.first == y1.first and x1.second != y1.second);

}