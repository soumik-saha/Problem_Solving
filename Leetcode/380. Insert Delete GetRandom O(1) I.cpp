class RandomizedSet {
public:
    unordered_map<int, int> mp;
    vector<int> elements;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (mp.count(val) > 0)
            return false;

        mp[val] = elements.size();
        elements.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (mp.count(val) == 0)
            return false;

        int index = mp[val];
        int lastElement = elements.back();

        elements[index] = lastElement;
        mp[lastElement] = index;

        elements.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int randomIndex = rand() % elements.size();
        return elements[randomIndex];
    }
};
