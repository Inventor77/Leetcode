class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int push=0, pop=0;
        stack<int> stk;
        while(push<pushed.size() || pop<popped.size()){
            if(!stk.empty() && stk.top()==popped[pop]){
                stk.pop();
                ++pop;
                continue;
            }
            else if(!stk.empty() && stk.top()!=popped[pop] && push==pushed.size()) break;
            if(push<pushed.size()){
                int temp = pushed[push];
                stk.push(temp);
                ++push;    
            }            
        }
        if(stk.empty()) return true;
        return false;
    }
};