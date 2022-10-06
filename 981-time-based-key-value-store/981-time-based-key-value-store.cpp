class TimeMap {
    private: 
    unordered_map<string,unordered_map<int,string>>storage;
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        storage[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        for(int t=timestamp;t>0;t--){
            if(storage[key].find(t)!=storage[key].end())return storage[key][t];
        }
        return "";
    }
};
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */