class Solution {

    struct TrieNode {
        struct TrieNode* children[26];
        int ew;
    };

public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {

        struct TrieNode* root = getNode();

        for (string& s : words) {
            set<char>st;

            st.insert(s.begin(), s.end());

            string sorted_str = "";
            for (char ch : st)
                sorted_str += ch;

            insert(root, sorted_str);

        }


        vector<int>count;
        for (string puzz : puzzles) {
            char first_ch = puzz[0];
            sort(puzz.begin(), puzz.end());

            int c = 0;
            c = search(root, puzz, first_ch, false);
            count.push_back(c);

        }
        return count;
    }


    struct TrieNode* getNode(void)
    {

        struct TrieNode* pNode = new TrieNode;
        pNode->ew = 0;

        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;

        return pNode;
    }


    void insert(struct TrieNode* root, string key)
    {
        struct TrieNode* pCrawl = root;

        for (int i = 0; i < key.length(); i++) {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();

            pCrawl = pCrawl->children[index];
        }

        pCrawl->ew += 1;
    }


    int search(struct TrieNode* root, string str, char first_ch, bool firstSeen)
    {
        if (!root)
            return 0;

        int count = 0;

        if (firstSeen)
            count += root->ew;

        for (int i = 0; i < str.length(); i++)
        {
            int index = str[i] - 'a';
            if (str[i] == first_ch)
                count += search(root->children[index], str, first_ch, true);
            else
                count += search(root->children[index], str, first_ch, firstSeen);
        }

        return count;
    }

};