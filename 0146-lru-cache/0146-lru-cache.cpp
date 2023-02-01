class LRUCache {
    list<pair<int, int>> ls;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;
public:
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        ls.splice(ls.begin(), ls, mp[key]);
        return mp[key] -> second;
    }
    
    void put(int key, int value) {
        if(get(key) != -1){
            mp[key] -> second = value;
            return;
        }
        if(mp.size() == capacity){
            int delKey = ls.back().first;
            ls.pop_back();
            mp.erase(delKey);
        }
        ls.emplace_front(key, value);
        mp[key] = ls.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */