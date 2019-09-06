class LRUCache {
private:
    int capacity;
    map<int,list< pair<int,int> >::iterator > mp;
    list< pair<int,int> > q;
public:
    // get(key) should be in O(1)
    // put(key,value) should be in O(1)
    // hashmap keeps track of position of key in queue
    //for each insertion maintain a queue, if overflow delete last element fro queue as well as map

    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        auto it = mp.find(key);
        if (it != mp.end()){
            auto val = mp[key];
            put(key,val->second);
            return val->second;
        }
        else return -1;
    }

    void put(int key, int value) {
        if (mp.find(key) != mp.end()){
            q.erase(mp[key]);
            q.push_front({key,value});
            mp[key] = q.begin();
            return;
        }
        if (q.size() == capacity){
            pair<int,int> val = q.back();
            mp.erase(val.first);
            q.pop_back();
        }
        q.push_front({key,value});
        mp[key] = q.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
