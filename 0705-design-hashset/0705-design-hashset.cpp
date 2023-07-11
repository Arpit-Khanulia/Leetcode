class MyHashSet {
public:
    
    vector<list<int>>m;
    int size;
    
    MyHashSet() {
        
        size =100;
        m.resize(size);
        
    }
    
    int hashfn(int key){
        
        return key%100;
    }
    
    list<int>::iterator search(int key){
        
        int index = hashfn(key);
        return find(m[index].begin(),m[index].end(),key);
        
    }
    
    
    
    void add(int key) {
        
        if(contains(key)) return;
        int index = hashfn(key);
        m[index].push_back(key);
        
    }
    
    void remove(int key) {
        
        if(! contains(key)) return;
        int index = hashfn(key);
        m[index].erase( search(key)     );
        
    }
    
    bool contains(int key) {
        
        int index = hashfn(key);
        if(search(key) == m[index].end()) return 0;
        else return 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */