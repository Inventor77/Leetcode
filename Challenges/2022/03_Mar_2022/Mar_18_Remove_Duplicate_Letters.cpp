class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s.length() == 1)
            return s;
        map<char, int> mp; 
        stack<char> st; 
        vector<int> visited(26 ,0); 
        int index = 0; 
        for(char c : s)
            mp[c]++; 
        for(char c : s){
            index = (c - 'a');
            mp[c]--;
            
            if(visited[index]) continue;
            while(!st.empty() && st.top() > c && mp[st.top()] > 0){
                visited[st.top() - 'a'] = 0;
                st.pop();
            }
            st.push(c); 
            visited[index] = 1; 
        }
        s = "";
        
        while(!st.empty()){
            s = st.top() + s;
            st.pop();
        }
        return s;
    }
};