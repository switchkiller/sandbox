class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()){
            int res = mp[key]->second;
            put(key,res);
            return res;
        }
        return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()){
            // already present
            queue.erase(mp[key]);
            queue.push_front({key,value});
            mp[key] = queue.begin();
            return;
        }
        if (queue.size() >= capacity){
            auto it = queue.back();
            mp.erase(it.first);
            queue.pop_back();
        }
        queue.push_front({key,value});
        mp[key] = queue.begin();
    }
private:
    list<pair<int,int>> queue;
    map<int, list<pair<int,int> >::iterator > mp;
    int capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
