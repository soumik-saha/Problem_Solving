class SmallestInfiniteSet {
    set<int> s;
    int curr;
public:
    SmallestInfiniteSet() {
        curr = 1;
    }
    
    int popSmallest() {
        int ans;
        if(!s.empty()) {
            ans = *s.begin();
            s.erase(s.begin());
        }
        else {
            ans = curr;
            curr+=1;
        }
        return ans;
    }
    
    void addBack(int num) {
        if (curr<=num || s.find(num) != s.end())
            return;
        s.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
