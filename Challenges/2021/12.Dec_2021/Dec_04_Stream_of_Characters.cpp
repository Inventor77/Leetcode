class Node {

private:

    Node* links[26];
    bool isEnd;

public:

    Node()
    {
        isEnd = false;
        for (int i = 0;i < 26;i++) links[i] = NULL;
    }
    Node* get(char c)
    {
        if (links[c - 'a'] == NULL) return NULL;
        else return links[c - 'a'];
    }
    void set(char c)
    {
        links[c - 'a'] = new Node();
    }
    void setEnd()
    {
        isEnd = true;
    }
    bool getEnd()
    {
        return isEnd;
    }

};

class StreamChecker {

private:

    Node* root;
    int lword;
    string suffix;

    void insert(string word)
    {
        Node* cur = root;
        int n = word.length();
        lword = max(n, lword);
        for (int i = 0;i < n;i++)
        {
            char current = word[i];
            if (cur->get(current) == NULL) cur->set(current);
            cur = cur->get(current);
        }
        cur->setEnd();
    }

public:

    StreamChecker(vector<string>& words) {
        root = new Node();
        lword = 0;
        for (auto& word : words)
        {
            reverse(word.begin(), word.end());
            insert(word);
        }
    }

    bool query(char letter) {

        suffix.insert(suffix.begin(), letter);
        int n = suffix.size();
        if (n > lword) suffix.pop_back();
        Node* cur = root;
        for (int i = 0;i < n;i++)
        {
            char current = suffix[i];
            if (cur->getEnd()) return true;
            cur = cur->get(current);
            if (!cur) return false;
        }

        return cur->getEnd();
    }
};
/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */