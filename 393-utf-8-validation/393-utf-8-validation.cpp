class Solution {
public:
    int parse_first_byte(int byte) {
        if ((byte >> 7) == 0) { 
            return 0;
        } else if ((byte >> 5) == 6) { 
            return 1;
        } else if ((byte >> 4) == 14) { 
            return 2;
        } else if ((byte >> 3) == 30) { 
            return 3;
        } 
        return -1;
    }
    
    bool validUtf8(vector<int>& data) {
        int need_to_process{};
        for (int i = 0; i < data.size(); ++i) {
            if (need_to_process == 0) {
                need_to_process = parse_first_byte(data[i]);
                if ((need_to_process == -1) || (data.size() - i < need_to_process)) {
                    return false;
                }
            } else {
                if ((data[i] >> 6) != 2) {
                    return false;
                } else {
                    --need_to_process;
                }
            }
        }
        return true;
    }
};