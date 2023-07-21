class LRUCache {
public:
    
    map<int,int>m;
    list<int>cache;
    map<int,list<int>::iterator> add;
    int size;
    int cap;
    
    LRUCache(int capacity) {
        
        cap = capacity;
        size =0;
        
    }
    
    int get(int key) {
        
        if(m.find(key) == m.end()) return -1;
        auto it = add[key];

        cache.erase(it);
        add.erase(key);

        cache.push_front(key);
        add[key] = cache.begin();
        
        
        return m[key];
    }
    
    void put(int key, int value) {
        
        if(m.find(key) != m.end()){

            auto it = add[key];
            cache.erase(it);
            add.erase(key);
            m.erase(key);
            size--;
        }

        if(size== cap){

            int k = cache.back();
            cache.pop_back(); 
            add.erase(k);
            m.erase(k);
            size--;
        }

        size++;
        m[key] = value;
        cache.push_front(key);
        add[key] = cache.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */