class NumberContainers {
public:
    unordered_map<int, int> container;
    unordered_map<int, set<int>> minIndex;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if(container.find(index)!=container.end()) {
            minIndex[container[index]].erase(index);
            if(minIndex[container[index]].size()==0)
                minIndex.erase(container[index]);
        }

        container[index] = number;
        minIndex[number].insert(index);
    }
    
    int find(int number) {
        if(minIndex.find(number)==minIndex.end())   return -1;
        return *minIndex[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
