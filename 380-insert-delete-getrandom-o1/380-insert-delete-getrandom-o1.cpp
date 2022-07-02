class RandomizedSet {
private: 
    unordered_set<int> s;
    vector<int> set;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(s.find(val) == s.end()) {
            set.push_back(val);
            s.insert(val);
            return true;
        }
        else {
            return false;
        }
    }
    
    bool remove(int val) {
        if(s.find(val) != s.end()) {
            s.erase(s.find(val));
            set.erase(find(set.begin(), set.end(), val));
            return true;
        }
        else {
            return false;
        }
    }
    
    int getRandom() {
        int random = rand() % set.size();;
        return set[random];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */