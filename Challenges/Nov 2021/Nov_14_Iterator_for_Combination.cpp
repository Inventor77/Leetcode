class CombinationIterator {
private:
    set<string>combinations; 
    set<string>::iterator cur; 
public:
    CombinationIterator(string characters, int combinationLength) {

        int total = (1 << characters.size()); 

        for (int mask{ 1 }; mask < total; ++mask) {

            if (__builtin_popcount(mask) != combinationLength)
                continue;

            set<char>my_set; 

            for (int i{}; i < characters.size(); ++i) {

                int f = (1 << i);

                if (mask & f)
                    my_set.insert(characters[i]);
            }

            string st{};
            for (auto c : my_set) {
                st.push_back(c);
            }
            combinations.insert(st);
        }
        cur = combinations.begin();

    }
    string next() {
        return *cur++;
    }
    bool hasNext() {
        return cur != combinations.end();
    }
};