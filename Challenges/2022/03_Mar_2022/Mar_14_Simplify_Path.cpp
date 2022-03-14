class Solution {
public:
    string simplifyPath(string path) {
        
        path.push_back('/');        
        stack<string> st;
        string directory = "";
        for(int i=0; i<path.size(); i++) {
            if( path[i] == '/' ) {      
                if( directory == ".." && !st.empty() ) st.pop();
                else if( directory != "" && directory != "." && directory != "..") st.push(directory);
                directory = "";
            }
            else directory.push_back(path[i]);  
        }
        
        string result = "";
        while(!st.empty()) {
            result = "/"+st.top()+result;
            st.pop();
        }
        
        if(result=="") return "/";
        return result;
    }
};