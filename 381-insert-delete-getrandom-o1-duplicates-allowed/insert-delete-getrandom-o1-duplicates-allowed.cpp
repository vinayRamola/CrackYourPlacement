class RandomizedCollection {
public:
    unordered_map<int, unordered_set<int>> val_to_indices;
    vector<int> values;
    
public:
    RandomizedCollection() {
        srand(static_cast<unsigned int>(time(0)));
    }
    
    bool insert(int val) {
        bool isNewElement = val_to_indices[val].empty();
        values.push_back(val);
        val_to_indices[val].insert(values.size() - 1);
        return isNewElement;
    }
    
    bool remove(int val) {
        if (val_to_indices[val].empty()) return false;
        
        int remove_idx = *val_to_indices[val].begin();
        val_to_indices[val].erase(remove_idx);
        
        int last_val = values.back();
        values[remove_idx] = last_val;
        val_to_indices[last_val].erase(values.size() - 1);
        if (remove_idx < values.size() - 1) {
            val_to_indices[last_val].insert(remove_idx);
        }
        
        values.pop_back();
        
        if (val_to_indices[val].empty()) {
            val_to_indices.erase(val);
        }
        
        return true;
    }
    
    int getRandom() {
        int random_idx = rand() % values.size();
        return values[random_idx];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */