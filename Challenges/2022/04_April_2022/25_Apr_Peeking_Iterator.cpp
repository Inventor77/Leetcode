class PeekingIterator : public Iterator {
    int nextVal;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        nextVal = Iterator::next();
    }

    int peek() {
        return nextVal;
    }
    int next() {
        int temp = nextVal;
        if (Iterator::hasNext())
            nextVal = Iterator::next();
        else
            nextVal = NULL;
        return temp;
    }

    bool hasNext() const {
        return (nextVal != NULL);
    }
};